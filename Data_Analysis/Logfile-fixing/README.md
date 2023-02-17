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

# Sample Script

Here is a sample script to show the commands you would expect to see in one orbit. Bare in mind that the script changed throughout the mission, so it might be a little different for your logfile. Also bare in mind that the following does not include the response form the computer. In the logfile you will see the output of each command as well. Before each command you will see an ``SE0>``.
```shell
# Start Of Script 22 December 2022 0:00:00
rtc read                        # Read the time
script delayuntil 1671667200    # Delay until some point 
csp txrx 4 14 600 000800201C    # Prepare to turn on
csp txrx 4 14 600 000A00341C
csp txrx 4 14 600 000700391C
rtc read                        # Read the time
fs list                         # Show the storage of the buffers
rtc read                        # Read the time
csp txrx 4 14 600 0007010100    # POWER ON
script delay 1000               # Delay
csp txrx 4 14 600 000A010100    # Setup things
script delay 1000
csp txrx 4 14 600 0008010100
script delay 180000             # Do nothing wile you are measuring
csp txrx 12 8 3000 0F           # Some more setup
csp txrx 13 8 3000 0F
csp txrx 12 8 3000 0F
csp txrx 13 8 3000 0F
script delay 10000
rtc read
csp txrx 12 4 3000 01
script delay 10000
csp txrx 13 4 3000 01
script delay 10000
csp txrx 12 4 3000 01
script delay 10000
csp txrx 13 4 3000 01
script delay 40000
rtc read
csp txrx 12 4 3000 02
script delay 10000
csp txrx 13 4 3000 02
script delay 10000
csp txrx 12 4 3000 02
script delay 10000
csp txrx 13 4 3000 02
rtc read
script delay 60000
rtc read                        # Set the power supply voltages
csp txrx 12 9 3000 00000009FFFFFFFFFFFFFFFF
script delay 10000
csp txrx 13 9 3000 00000009FFFFFFFFFFFFFFFF
script delay 10000
csp txrx 12 9 3000 00000009FFFFFFFFFFFFFFFF
script delay 10000 
csp txrx 13 9 3000 00000009FFFFFFFFFFFFFFFF
rtc read
script delay 120000
rtc read
script delayuntil 1671669720    # Wait until a specific point
rtc read
csp txrx 12 4 3000 08           # Start the shutdown cycle
script delay 10000
csp txrx 13 4 3000 08
script delay 30000
csp txrx 4 14 600 0008000000
script delay 20000
csp txrx 4 14 600 000A000000
script delay 5000
csp txrx 4 14 600 0007000000    # POWER OFF
script delayuntil 1671672600    # Wait some time
csp txrx 4 14 600 000800201C    # Preapre for the next power on
csp txrx 4 14 600 000A00341C
csp txrx 4 14 600 000700391C
rtc read
csp txrx 4 14 600 0007010100    # POWER ON
# End Of Script 22 Dec 2022 23:59:59

```