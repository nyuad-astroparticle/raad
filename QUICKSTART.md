# RAAD Quickstart
Quickly get up and running with the RAAD Computer assuming you have installed everything properly. If you run to errors following this, please read the `README.md` files on the `RAAD/` and    Conda_Environment_Installation` directories.

## Connect to RAAD Workstation Remotely

If you're off campus please connect using **nyu vpn** at: `npn.abudhabi.nyu.edu`.

Open a terminal. Depending on your OS this may be different: 
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

With an open terminal type the following command to connect to the NUC
```shell
$ ssh nyuad@RAAD.abudhabi.nyu.edu
```

You will be prompted to enter a password:

    Username: nyuad
    Password: nyuad123$

To open a jupyter notebook type these two commands:

```shell
$ raad
$ jupyter notebook
```

Then follow the instructions in the screeen, by copying the appropriate URL on your browser. If no other instances of jupyter notebook are running the URL will be:

[http://raad.abudhabi.nyu.edu:9999/](http://raad.abudhabi.nyu.edu:9999/)

If prompted with a password enter the usual password shown at the beginning of this document. That's it! the workflow is 3 commands!

## Using git to get and update the code

To check the status of the raad repository make sure you are there (by typing: `RAAD` on the terminal or checking on the left of the `$` to see if it has `~/RAAD...`), and then use the command:

```shell
$ git status
```
If you want to download the latest update to the code, or the `main` branch is not up to date with the current branch, pull the code from the interet by typing:

```shell
$ git pull
```

Finally, to create a commit you first have to `git add` the files you have changed or created, then `git commit` them and finally, `git push` the changes to update the online version of the repository. To do this, type:

```shell
$ git add file1 file2 ... fileN
```

where `file1`, `file2`, etc. are the filenames of the files you want to update or have created from scratch. If you want to update all the files in a subdirectory you can type:

```shell
$ git add *
```

After adding the files, we need to create the commit, like so

```shell
$ git commit -m "<Your Message>"
```
Always add a message using the `-m` modifier, otherwise `git` does not allow the commit. Finally push your changes to the online repository by typing:

```shell
$ git push
```

The online repository can be found at: [https://github.com/nyuad-astroparticle/raad](https://github.com/nyuad-astroparticle/raad).
