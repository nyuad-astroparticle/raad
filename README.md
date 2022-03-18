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

<mark>**NOTE:** You need to be logged in to NYU VPN in order to access the computer while of campus.</mark> On Campus (i.e. connected to the network `nyu`) you don't need vpn.

**SSH setup Links**
    
1. MacOS: [https://support.languard.gfi.com/hc/en-us/articles/360015162139-Enabling-SSH-Daemon-in-Mac-OS-X](https://support.languard.gfi.com/hc/en-us/articles/360015162139-Enabling-SSH-Daemon-in-Mac-OS-X)
2. Windows: [https://www.makeuseof.com/tag/4-easy-ways-to-use-ssh-in-windows/](https://www.makeuseof.com/tag/4-easy-ways-to-use-ssh-in-windows/). Any of these methods should work, but we recommend using *Powersheel* (Method 2)
3. Linux: [https://www.cyberciti.biz/faq/ubuntu-linux-install-openssh-server/](https://www.cyberciti.biz/faq/ubuntu-linux-install-openssh-server/)

If/Once ssh is already set up open a terminal by doing so in the following Operating systems:
- **MacOS** 
1. Press <kbd>&#8984;</kbd> + <kbd>SPACE</kbd>
2. Type *"terminal"*
3. Click enter
- **Windows**
1. Press <kbd>![Windows Key](http://i.stack.imgur.com/Rfuw7.png)</kbd>
2. Search for *"PowerShell"*
3. Click enter
- **Linux**
1. Press <kbd>Ctrl</kbd> + <kbd>Alt</kbd> + <kbd>T</kbd>

There are two computers you can connect to. The NUC for day to day tasks, and the High Performance Computer in the lab.

With an open terminal type the following command to connect to the NUC
```shell
$ ssh nyuad@RAAD.abudhabi.nyu.edu
```
To connect to the High Performance computer for more intensive tasks type the follwoing
```shell
$ ssh raad@arneodolab.abudhabi.nyu.edu
```
This will prompt for a password, the password is the usual one.

And that's it! You have connected to the RAAD Workstation!

## Working on the RAAD workstation

Once you have a working terminal of the RAAD workstation (either in person or remotely through ssh) you can enable the python environment and simultaneously go to the directory of all the RAAD Analysis data by typing the following command

```shell
$ RAAD
```

Then you can start a jupyter notebook session on the RAAD directory by typing:

```shell
$ jupyter notebook
```

This will produce something like the following output

```shell
$ jupyter notebook
[W 18:16:19.954 NotebookApp] WARNING: The notebook server is listening on all IP addresses and not using encryption. This is not recommended.
[I 18:16:19.958 NotebookApp] Serving notebooks from local directory: /home/nyuad/RAAD
[I 18:16:19.958 NotebookApp] Jupyter Notebook 6.4.8 is running at:
[I 18:16:19.958 NotebookApp] http://nyuad-desktop:9999/
[I 18:16:19.958 NotebookApp] To open jupyter notebook from another computer, copy paste this on your browser:
[I 18:16:19.958 NotebookApp] http://raad.abudhabi.nyu.edu:9999/
[I 18:16:19.958 NotebookApp] Use Control-C to stop this server and shut down all kernels (twice to skip confirmation).
```

If you are working in the physical computer then a browser window will automatically open with the jupyter notebook environment. If it asks for a password the password is the usual one.

<mark>**! If you are working remotely:**</mark> No window will open. But don't panic, it's not supposed to! Simply copy the next to last line (the last link) of the output in the terminal, and paste it on the browser of your choice. 

In this case we copy: http://raad.abudhabi.nyu.edu:9999/ to google chrome and start working with jupyter normally. Unless two or more jupyter notebook sessions are running at the same time, this will be the url to use. 
