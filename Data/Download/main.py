from FileDownload import FileDownloader
from FileDownload import FileStorage

storage = FileStorage("storage")

fd = FileDownloader(
    fileName="pc_buff1",
    host="https://light1.mcs.nanoavionics.com",
    token="eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJyb2xlIjoia2hhbGlmYSIsImV4cCI6MTcwNDA2NzIwMCwiZW1haWwiOiJhZGcxMUBueXUuZWR1In0.LiV8bfKb2JUG2eIIxouXKebQpPFLXewO1BqoOD22xS4", 
    storage=storage)

fd.DownloadLoop(max=10, sleep=10)
