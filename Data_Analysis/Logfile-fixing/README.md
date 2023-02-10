# LIGHT-1 Analysis Workshop | Logfile Reconstruction

**Thank you** for joining our pain to reconstruct the data of the LIGHT-1 space mission! As you know our detector is facing so many issues and we need your help to fix them. Even though we have done a lot of work to atomate the corrections, this one we have tried and failed to automate. 

These are instructions to help you set up and carry out this analysis on your computer. We will use ``python`` to view things and submit them, but the actual corrections are going to be using your favorite text editor. 


# Setup | Pick your poison.

Your setup will look different depending on your operating system. Please click the one you have:

1. [Windows](./windows.md)
2. [Mac](./mac.md)
3. [Linux](./linux.md)

# The Analysis

Onboard the satellite there is a computer. If anything happens on the satellite (like turning it on and off, checking the clock, looking at the status of the files, etc.) it is because a command was executed on that computer.

We prepare the commands from the ground and they look something like this:

```
txrx 4 14 600 0007000000
```

This command, for example, means ``turn off the detector``. The ``txrx`` means "do on the payload", and the numbers after it specify which one of the predefined commands to execute. Why didn't we use something more user friendly? I have no clue.

Each command along with it's output is logged in a **logfile**. But because of transmission errors, and sometimes the accidental reboot of the on board computer this data is corrupt in places. 

> 
> **Our goal today is to fix this data chink by chunk.**
>

In particular we want to fix the following:

We care about when the satellite starts and ends, but since sections are corrupt when we walk through the logfile we might see something like:

1. Turn on
2. Turn off
3. Turn on
4. Turn on
5. Turn off

This means that after spe 3 we missed a turn off! We want to put this information back manually. And you can do that using your favorite text editor.

Here is the structure of the commands and their output you will need to append to the file in order to do this.

### Turn on
```
SE0>csp txrx 4 14 600 0007010100
Answer: 0000
Bytes: 2
Flags: 0x00 (frag=0, HMAC=0, XTEA=0, RDP=0, CRC32=0)
OK
```

### Turn off
```
SE0>csp txrx 4 14 600 0007000000
Answer: 0000
Bytes: 2
Flags: 0x00 (frag=0, HMAC=0, XTEA=0, RDP=0, CRC32=0)
OK
```

### Clock

Other useful commands you can look for is ``rtc read`` that reads the **real time clock** of the on board computer.
```
SE0>rtc read
curr rtc time 1671688800.014984 s, 2022-12-22 06:00:00 
OK
```