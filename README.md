# Using the RAAD Workstation

This is a quick tutorial to using the RAAD workstation at NYUAD Astroparticle Lab. The computer should be accessible in and out of campus. 

## Accessing the RAAD workstation

To access the computer, either connect to it over the internet or physically come to lab. 

### LAB

To login to the RAAD Workstation the username and password are as follows:
    
    Username: nyuad
    Password: nyuad123$

Once you are there you can open a terinal 


### Over the internet

To login to the RAAD Workstation over the internet it is preferred to use [SSH](https://www.techtarget.com/searchsecurity/definition/Secure-Shell). SSH is a method to open a terminal of another computer from your computer. Unix systems (e.g MacOS, Linux) have ssh by default but if you're using windows or don't have ssh enabled click on one of the lnks below to set up ssh.

**SSH setup Links**
    
1. MacOS: [https://support.languard.gfi.com/hc/en-us/articles/360015162139-Enabling-SSH-Daemon-in-Mac-OS-X](https://support.languard.gfi.com/hc/en-us/articles/360015162139-Enabling-SSH-Daemon-in-Mac-OS-X)
2. Windows: [https://www.makeuseof.com/tag/4-easy-ways-to-use-ssh-in-windows/](https://www.makeuseof.com/tag/4-easy-ways-to-use-ssh-in-windows/). Any of these methods should work, but we recommend using *Powersheel* (Method 2)
3. Linux: [https://www.cyberciti.biz/faq/ubuntu-linux-install-openssh-server/](https://www.cyberciti.biz/faq/ubuntu-linux-install-openssh-server/)

If/Once ssh is already set up open a terminal by doing so in the following Operating systems:
- **Mac** 
1. Press <kbd>&#8984;</kbd> + <kbd>SPACE</kbd>
2. Type *"terminal"*
3. Click enter
- **Windows**
1. Press <kbd>![Windows Key](http://i.stack.imgur.com/Rfuw7.png)</kbd>
2. Search for *"PowerShell"*
3. Click enter
- **Ubuntu**
1. Press <kbd>Ctrl</kbd> + <kbd>Alt</kbd> + <kbd>T</kbd>

With an open terminal type the following command
```shell
$ ssh nyuad@RAAD.abudhabi.nyu.edu
```

And that's it! You have connected to the RAAD Workstation!

## Working on the RAAD workstation

Once you have a working terminal of the RAAD workstation (either in person or remotely through ssh) you can enable the python environment and simultaneously go to the directory of all the RAAD Analysis data by typing the following command

```shell
$ RAAD
```
Note that this command is case sensitive (typing *"raad"* will not work).

Then you can start a jupyter notebook session on the RAAD directory by typing:

```shell
$ jupyter notebook
```

This will produce something like the following output

```shell
$ jupyter notebook
[I 16:03:01.029 NotebookApp] Serving notebooks from local directory: /home/nyuad/Desktop/RAAD
[I 16:03:01.029 NotebookApp] Jupyter Notebook 6.4.8 is running at:
[I 16:03:01.029 NotebookApp] http://localhost:8888/?token=40cf9daf7e49ec13822cd4498f4e1573841ebb14cc0c468c
[I 16:03:01.029 NotebookApp]  or http://127.0.0.1:8888/?token=40cf9daf7e49ec13822cd4498f4e1573841ebb14cc0c468c
[I 16:03:01.029 NotebookApp] Use Control-C to stop this server and shut down all kernels (twice to skip confirmation).
[C 16:03:01.075 NotebookApp] 
    
    To access the notebook, open this file in a browser:
        file:///home/nyuad/.local/share/jupyter/runtime/nbserver-35595-open.html
    Or copy and paste one of these URLs:
        http://localhost:8888/?token=40cf9daf7e49ec13822cd4498f4e1573841ebb14cc0c468c
     or http://127.0.0.1:8888/?token=40cf9daf7e49ec13822cd4498f4e1573841ebb14cc0c468c

```

If you are working in the physical computer then a browser window will automatically open with the jupyter notebook environment. 

**! If you are working remotely:** No window will open. But don't panic, it's not supposed to! Simply copy the last line (the last link) of the output in the terminal, and paste it on the browser of your choice. 

In this case we copy: http://127.0.0.1:8888/?token=40cf9daf7e49ec13822cd4498f4e1573841ebb14cc0c468c to google chrome and start working with jupyter normally. 