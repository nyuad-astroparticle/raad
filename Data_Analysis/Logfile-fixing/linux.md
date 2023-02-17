# Setup Instructions - Windows

To get started you need to install a couple of things using your terminal.

## Open a terminal

We will do everything from the terminal so please open one like so on your operating system.

1. Press <kbd>Ctrl</kbd> + <kbd>Alt</kbd> + <kbd>T</kbd>

## Install SSH - Our way to connect with the lab computer

SSH is a way to conntect securely from one computer to the other.


On your terminal type
```shell
sudo apt-get install openssh-server
```
After following the steps type the following on your terminal to start ssh
```shell
sudo systemctl enable ssh --now
```

## Python

Our analysis is done in python, if you have python 3 installed you can skip this step. If not, here is a quick way to install it. Type the following in your terminal to install

```shell
sudo apt update && sudo apt upgrade -y
sudo apt install python
```

## RAADpy - Our custom library

After you have installed python, all you need to do is to install our custom library ``raadpy`` that we developed specifically for the analysis of LIGHT-1 data. Simply type to your terminal:

```shell
pip install jupyter notebook ipympl raadpy
```

## Get the data

We have give you unique access to the supercomputer in the lab just for today! You should be able to get the data by typing the following in your terminal.

In your terminal type

```shell
mkdir logfix && cd "$_"
wget -r -np -nH --cut-dirs=3 -R index.html http://arneodolab.abudhabi.nyu.edu:8000/logfix/logfile-fixup-example.ipynb
```

# You are ready!

Now you should have everything in order to get started. Type the following on your terminal to open the jupyter notebook to start.

```shell
jupyter notebook logfile-fixup-example.ipynb
```

**Go back to the main page by clicking [here](./README.md).**
