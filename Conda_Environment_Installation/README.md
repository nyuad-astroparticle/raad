# RAAD Conda Environment Installation

Instructions to install a python environment using conda to run the analysis scripts for RAAD (Light-1). The follwing setup is done in Ubuntu, please adjust the commands based on your operating system.

---

## Installing miniconda

We use miniconda to manage the environments. However, if you have any other **up-to-date** conda installation (e.g. Anaconda) the rest of the steps should work just as well, so you might want to skip miniconda installation. 

You can check if your installation is up to date by running the following command:
```shell
$ conda --version
conda 4.11.0
```

As you can see the version of conda we are using here is `4.11.0`

Installation instructrions for different operating systems: [https://docs.conda.io/projects/conda/en/latest/user-guide/install/index.html](https://docs.conda.io/projects/conda/en/latest/user-guide/install/index.html)

For **linux** open a terminal and type the following commands to download the miniconda installation:
```shell
$ wget https://repo.anaconda.com/miniconda/Miniconda3-latest-Linux-x86_64.sh
$ chmod +x Miniconda3-latest-Linux-x86_64.sh
```
After doing so run the installer by typing the following command and following the instructions.
```shell
./Miniconda3-latest-Linux-x86_64.sh
```
After the installation is complete colose this and open a new terminal to use conda. If the installation is done correctly `(base)` should appear before your directory like so:
```shell
(base) nyuad@nyuad-desktop:~$
```

To make sure everything is installed correctly, run the following command
```shell
$ conda info
```
The output should look like this:
```shell
     active environment : base
    active env location : /home/<username>/miniconda3
            shell level : 1
       user config file : /home/<username>/.condarc
 populated config files : 
          conda version : 4.11.0
    conda-build version : not installed
         python version : 3.9.7.final.0
       virtual packages : __linux=5.13.0=0
                          __glibc=2.31=0
                          __unix=0=0
                          __archspec=1=x86_64
       base environment : /home/<username>/miniconda3  (writable)
      conda av data dir : /home/<username>/miniconda3/etc/conda
  conda av metadata url : None
           channel URLs : https://repo.anaconda.com/pkgs/main/linux-64
                          https://repo.anaconda.com/pkgs/main/noarch
                          https://repo.anaconda.com/pkgs/r/linux-64
                          https://repo.anaconda.com/pkgs/r/noarch
          package cache : /home/<username>/miniconda3/pkgs
                          /home/<username>/.conda/pkgs
       envs directories : /home/<username>/miniconda3/envs
                          /home/<username>/.conda/envs
               platform : linux-64
             user-agent : conda/4.11.0 requests/2.27.1 CPython/3.9.7 Linux/5.13.0-35-generic ubuntu/20.04.4 glibc/2.31
                UID:GID : 1000:1000
             netrc file : None
           offline mode : False
```

By the way, here is a list of useful conda commands just in case: [https://docs.conda.io/projects/conda/en/latest/_downloads/843d9e0198f2a193a3484886fa28163c/conda-cheatsheet.pdf](https://docs.conda.io/projects/conda/en/latest/_downloads/843d9e0198f2a193a3484886fa28163c/conda-cheatsheet.pdf)

---

## Creating the RAAD conda environment

(If you need to uninstall an existing environment you can follow: [https://docs.conda.io/projects/conda/en/latest/commands/remove.html](https://docs.conda.io/projects/conda/en/latest/commands/remove.html))

Now that we have a working conda installation we are ready to create an environment. However, before we go all ballistic and download packages, it is ideal to do some housekeeping. We will install a bunch of packages from different sources using `conda`, as a result we need to make sure that if one depends on the other, one knows where to look for the other to load it properly. So it would be better to tell `conda install` to get its packages from the same source. To do this, we will to set as out primary source of packages `conda-forge` because it contains a lot more packages than others (read more about this [here](https://conda-forge.org/docs/user/tipsandtricks.html#using-multiple-channels)). To do this we type:
```shell
$ conda config --env --add channels conda-forge
$ conda config --set channel_priority strict
``` 

With that you can build the environment from the `.yml` file provided in this directory like so.
```shell
$ conda env create --file RAAD_env.yml
```

Alternatively, if you have masochistic tendencies like us, you can build it from scratch by using the following commands. <mark>**NOTE:** If your installation worked in the previous step (using the `.yml` file) you do not need to do the following steps. You are done!</mark> If for some reason it didn't work, maybe creating the environment step by step as below might do the trick : )

First create a new conda environment, we do so by running the following command
```shell
$ conda create --name RAAD python=3.9
```

Here we call the environment `RAAD` but you can call it whatever you want. This will create a clean python environment with python version `3.9.10`. Feel free to use higher version of python at your own risk, as some of the features we are using migh be deprecated. 

To activate that environment type
```shell
$ conda activate RAAD
```
Now on the left side of your terminal the `(base)` shoul have been replaced with `(RAAD)` like so
```shell
(RAAD) nyuad@nyuad-desktop:~$
```
We have created a clean conda environment for our pythoning. However,

Now it's time to install the needed modules one by one. We will install them one by one, just in case one doesn't work and we need to troubleshoot. To do so, run the following commands
```shell
$ conda install notebook
$ conda install matplotlib
$ conda install numpy
$ conda install scipy
$ conda install astropy
$ conda install requests
$ conda install lxml
$ conda install fitsio
$ conda install bokeh
$ conda install pandas
$ conda install folium 
$ conda install geoviews-core
$ conda install geopandas
$ conda install cartopy
$ conda install holoviews
```
After this you should be done. Congratulations! Now you can analyze TGF data!
