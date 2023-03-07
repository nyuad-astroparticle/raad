# Background Model of LIGHT-1

Using backgronud spectra along the trajectory of LIGHT-1, generated from SPENVIS we use a GEANT-4 simulation to estimate the number of charged particles that deposit energy on the detector. Hopefully this can be used to backestmate the threshold.



## SPENVIS

The charge particle fluxes along the trajectory of LIGHT-1 were generated in ESA’s [Space Environment Information System](https://www.spenvis.oma.be/help.php). 

In particular the particle fluxes examined along the track of the golden October are the following:

1. Trapped Protons (inlcuding angular distribution)
2. Trapped Electrons (including angular distribution)
3. Solar Particle Fluence
4. Solar Proton Flux
5. Extragalactic Cosmic rays



The following parameters were used for the simulation.

### Grid Generator

The orbital path is specified using the following parameters that we got from STK. The complete data can be found [here](./Atmospheric_Spectra_SPENVIS/INPUT_DATA/LIGHT-1_51509_Pirate_Data.csv).

![image-20230307180452792](README.assets/image-20230307180452792.png)

This is the output

![image-20230307181527143](README.assets/image-20230307181527143.png)

If anyone was wondering here are the orbit results

![image-20230307182037120](README.assets/image-20230307182037120.png)



### Trapped Particle Sources

We evaluated the flux of trapped particles at solar maximum.

1. Species: Electrons, Protons
2. Threshold for exposure 1 particle/$cm^2$/$s$

![image-20230307182510322](README.assets/image-20230307182510322.png)

### Trapped Proton Anisotropy Model

No parameters just generated it :). Generates the angular distribution of the proton flux

![image-20230307184354628](README.assets/image-20230307184354628.png)

### Solar Particle Fluence

Calculate the fluence of solar protons and heavy ions from the sun, along the orbit. Turns out it’s a lot.

![image-20230307185559643](README.assets/image-20230307185559643.png)

### Galactic Cosmic Rays

Get galactic cosmic rays throught the mission time from registered solar models.

![image-20230307190037343](README.assets/image-20230307190037343.png)



## Results

Here are result spectra

**Trapped Protons**

|                         Average Flux                         |                    Flux throguhout orbit                     |
| :----------------------------------------------------------: | :----------------------------------------------------------: |
| <img src=README.assets/image-20230307182658045.png width="50%"> | ![image-20230307182948593](README.assets/image-20230307182948593.png) |





**Trapped Electrons**

|                         Average Flux                         |                    Flux throguhout orbit                     |
| :----------------------------------------------------------: | :----------------------------------------------------------: |
| ![image-20230307182816955](README.assets/image-20230307182816955.png) | ![image-20230307183820247](README.assets/image-20230307183820247.png) |



**Angular distribution of proton flux**

| Angular Distribution [0.1, 1, 10, 100 MeV]                   |                                                              |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| ![image-20230307184557950](README.assets/image-20230307184557950.png) | ![image-20230307184625530](README.assets/image-20230307184625530.png) |
| ![image-20230307184656231](README.assets/image-20230307184656231.png) | ![image-20230307184756398](README.assets/image-20230307184756398.png) |



**Solar Particle Fluence**

|                           Protons                            |                     Heavy Ions (alphas)                      |
| :----------------------------------------------------------: | :----------------------------------------------------------: |
| ![image-20230307185716003](README.assets/image-20230307185716003.png) | ![image-20230307185736916](README.assets/image-20230307185736916.png) |



**Galactic Cosmic Rays**

Extragalactic Proton Flux

![image-20230307190308168](README.assets/image-20230307190308168.png)
