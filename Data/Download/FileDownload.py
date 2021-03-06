
import requests
import json
import os
import time
import binascii

from requests.auth import HTTPBasicAuth
from requests.auth import HTTPDigestAuth
from requests_oauthlib import OAuth1

class FileStorage:
    """
    FileStorage is a simple entry storage.

    Entries are stored as files with entry_nr as names.
    Last download seqence number is stored in fileName.last file
    
    fileName/fileVersion/[entry].bin
    fileName.last
    """

    def __init__(self, directory):
        self.dir = directory

    def Store(self, fileName, seqNr, fileVer, entryNr, data):
        fileDir = os.path.join(self.dir, fileName, f"{fileVer}")
        if not os.path.exists(fileDir):
            os.makedirs(fileDir)
        filePath = os.path.join(fileDir, f"{entryNr}.bin")
        with open(filePath, "wb") as file:
            file.write(data)

        self.SaveSeq(fileName, seqNr)

    def SaveSeq(self, fileName, seqNr):
        lastPath = self.lastFile(fileName)
        with open(lastPath, "w") as file:
            file.write(f"{seqNr}")

    def LastSeq(self, fileName):
        lastPath = self.lastFile(fileName)
        if not os.path.exists(lastPath):
            return 0
        with open(lastPath, "r") as file:
            line = file.readline()
            return int(line)

    def checkDir(self):
        if not os.path.exists(self.dir):
            os.makedirs(self.dir)

    def lastFile(self, fileName):
        self.checkDir()
        return os.path.join(self.dir, f"{fileName}.last")

class FileDownloader:
    """
    FileDownloader loops over RESTful api download request.

    Download batch size is set as max argument.
    Downloaded data is stored in provided storage

    Sequence number is used to mark downloaded entry.
    """

    def __init__(self, fileName, host, token, storage):
        self.fileName = fileName
        self.host = host
        self.token = token
        self.storage = storage

    def Download(self, max = 100):

        downloaded = 0
        lastSeq = self.storage.LastSeq(self.fileName)

        while True:

            endSeq = lastSeq + max

            rest = self.makeDownloadRequest(lastSeq, endSeq)
            res = rest.SendGetReq()
            
            for row in res:
                binData = bytes.fromhex(row['entry_data'][2:])
                seqNr = row['seq_nr']
                self.storage.Store(self.fileName, seqNr, row['file_ver'], row['entry_nr'], binData)

                if seqNr > lastSeq:
                    lastSeq = seqNr

                downloaded = downloaded + 1

            if len(res) < max:
                break

        return downloaded

    def DownloadLoop(self, max = 100, sleep = 10):
        
        while True:
            try:
                res = self.Download(max=100)
                print(f"downloaded {res} entries")
            except Exception as e:
                print("Error", e.__class__, "occured")
                print(e)

            time.sleep(sleep)

    def makeDownloadRequest(self, start, end):
        return RestOperations(f'{self.host}/{self.fileName}_download?seq_nr=gt.{start}&seq_nr=lte.{end}', authType = 'token', token = self.token)

class RestOperations:
    
    def __init__(self, apiEndPoint, **kwargs):
        self.apiEndPoint = apiEndPoint
        self.kwargs = kwargs
    
    def SendGetReq(self):
        auth = self.CallAuth(self.kwargs)
        RespGetReq = requests.get(self.apiEndPoint, auth = auth)
        return json.loads(RespGetReq.text)

    def CallAuth(self, OptionalAttrs):
        authType = self.ValidateAuthAttrs(OptionalAttrs)
        if not authType:
            auth = None            
        elif authType == 'token':
            auth = HTTPBearerAuth(OptionalAttrs.get('token'))
        elif authType == 'basic':
            auth = HTTPBasicAuth(OptionalAttrs.get('username'), OptionalAttrs.get('password'))
        elif authType  == 'digest':
            auth = HTTPDigestAuth(OptionalAttrs.get('username'), OptionalAttrs.get('password'))
        elif authType  == 'oa1':
            auth = OAuth1(OptionalAttrs.get('AppKey'), OptionalAttrs.get('AppSecret'), OptionalAttrs.get('UserToken'), OptionalAttrs.get('UserSecret'))
        return auth
    
    def ValidateAuthAttrs(self, OptionalAttrs):
        if 'authType' not in OptionalAttrs:
            authType = None
        else:
            if OptionalAttrs.get('authType') not in ['token', 'digest', 'basic', 'oa1']:
                raise ValueError("Unknown authType received", OptionalAttrs.get('authType'))
            else:
                if OptionalAttrs.get('authType') == 'token' and 'token' not in OptionalAttrs:
                    raise ValueError("authType 'token' requires token")
                elif OptionalAttrs.get('authType') == 'basic' and not all(attr in OptionalAttrs for attr in ['username', 'password']):
                    raise ValueError("authType 'basic' requires username, password")
                elif OptionalAttrs.get('authType') == 'digest' and not all(attr in OptionalAttrs for attr in ['username', 'password']):
                    raise ValueError("authType 'digest' requires username, password")
                elif OptionalAttrs.get('authType') == 'oa1' and not all(attr in OptionalAttrs for attr in ['AppKey', 'AppSecret', 'UserToken' 'UserSecret']):
                    raise ValueError("authType 'oa1' requires AppKey, AppSecret, UserToken, UserSecret")
                else:
                    authType = OptionalAttrs.get('authType')
        return authType

class HTTPBearerAuth(requests.auth.AuthBase):
    '''requests() does not support HTTP Bearer tokens authentication, create one'''
    def __init__(self, token):
        self.token = token
    def __eq__(self, other):
        return self.token == getattr(other, 'token', None)
    def __ne__(self, other):
        return not self == other
    def __call__(self, r):
        r.headers['Authorization'] = 'Bearer ' + self.token
        return r
