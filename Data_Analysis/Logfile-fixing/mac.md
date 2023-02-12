# Setup Instructions - Mac

To get started you need to install a couple of things using your terminal.

## Open a terminal

We will do everything from the terminal so please open one like so on your operating system.

1. Open spotilight by pressing <kbd>⌘</kbd> + <kbd> SPACE</kbd>
2. Type ``Terminal`` and press <kbd>⏎ Enter</kbd>

## Install SSH - Our way to connect with the lab computer

SSH is a way to conntect securely from one computer to the other. If you are using mac you probably have this already and you might just need to enable it.

For detailed instructions and older versions of the OS go [here](https://osxdaily.com/2022/07/08/turn-on-ssh-mac/).

1. Pull down the  Apple menu and go to “System Settings”
2. Open the “General” preference panel”
3. Go to “General”
4. Toggle the switch for “Remote Login” to turn on the SSH server on the Mac
5. Click the (i) button to customize user access and check the box for “Allow full disk access for remote users”
6. The SSH server starts immediately, and the Mac is able to receive inbound SSH connections

## Python

Our analysis is done in python, if you have python 3 installed you can skip this step. If not, here is a quick way to install it.

We first install Homebrew. Homebrew is a tool that installs things from your terminal. (don't copy the '$')

```shell
$ /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install.sh)"
```

Once this is done type the two commands as follows
```shell
$ export PATH="/usr/local/opt/python/libexec/bin:$PATH"
$ brew install python
```

## RAADpy - Our custom library

After you have installed python, all you need to do is to install our custom library ``raadpy`` that we developed specifically for the analysis of LIGHT-1 data. Simply type to your terminal:

```shell
$ pip install jupyter notebook raadpy
```

## Get the data

We have give you unique access to the supercomputer in the lab just for today! You should be able to get the data by typing the following in your terminal.

In your terminal type

```shell
$ mkdir logfix && cd "$_"
$ curl -O http://arneodolab.abudhabi.nyu.edu:8000/logfix/logfile-fixup-example.ipynb
```

# You are ready!

Now you should have everything in order to get started. Type the following on your terminal to open the jupyter notebook to start.

```shell
$ jupyter notebook logfile-fixup-example.ipynb
```

**Go back to the main page by clicking [here](./README.md).**