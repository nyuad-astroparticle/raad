# Setup Instructions - Windows

To get started you need to install a couple of things using your terminal.

## Open a terminal

We will do everything from the terminal so please open one like so on your operating system.

1. Press the <kbd>![Windows Key](http://i.stack.imgur.com/Rfuw7.png)</kbd> key.
2. Type ``powershell`` and press <kbd>⏎ Enter</kbd>
3. Right click on powershell and click on ``Run as Administrator``

## Install SSH - Our way to connect with the lab computer

SSH is a way to conntect securely from one computer to the other. If you are using windows you probably have this already and you just need to activate it by following:

On Windows 11:
1. Go to Settings > Apps > Optional features and click on View features.
2. Locate “OpenSSH server” feature, select it, click Next, and then click Install.

On Windows 10 (version 1803 and newer):
1. Go to Settings > Apps > Apps & features > Optional features and click on Add a feature.
2. Locate “OpenSSH server” feature, expand it, and select Install.


## Python

Our analysis is done in python, if you have python 3 installed you can skip this step. If not, here is a quick way to install it. Type the following in your terminal to first install a package manager

```shell
$ @"%SystemRoot%\System32\WindowsPowerShell\v1.0\powershell.exe" -NoProfile -InputFormat None -ExecutionPolicy Bypass -Command "iex ((New-Object System.Net.WebClient).DownloadString('https://chocolatey.org/install.ps1'))" && SET "PATH=%PATH%;%ALLUSERSPROFILE%\chocolatey\bin"
```

and then to install python

```shell
choco install python --version=3.9.0
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
$ wget -r -np -nH --cut-dirs=3 -R index.html http://arneodolab.abudhabi.nyu.edu/logfix/logfile-fixup-example.ipynb
```

# You are ready!

Now you should have everything in order to get started. Type the following on your terminal to open the jupyter notebook to start.

```shell
$ jupyter notebook logfile-fixup-example.ipynb
```

**Go back to the main page by clicking [here](./README.md).**