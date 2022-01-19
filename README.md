# wd409_sectortest

This code was originally developed for beam tests of prototype sPHENIX calorimeters around 2014.   This version is the code that has been used to analyze
cosmic ray data taken with each production sPHENIX EMCAL sector 2020-2022.  This is not production sPHENIX analysis code, but a quick way to take raw data taken with the sPHENIX 14 bit 60 MHz waveform digitizers in "prdf" ("PHENIX Raw Data Format"), decoded by Martin&copy make it accessible to further analysis in a ROOT TTree (W).  Building the package relies on sPHENIX libraries which are part of the sPHENIX enviroment at RCF after "source /opt/sphenix/core/bin/sphenix_setup.sh -n".  It is quite specific to EMCAL sectors--384 ADC channels in packets 21351 and 21352, with 31 samples/tower.  If all goes well, "make" will build without errors.

The code was developed to find a reasonable way to quickly extract the time, peak, and pedestal of the digitized waveform.  Some of the key branches in the TTree are:

* int adc[384][31] are the raw adc samples
* float peak[384] is the maximum of the waveform extracted by a cubic spline interpolation near the maximum ADC values
* float time[384] is the time (in sample number) at the peak

Essentially all the data in the prdf is decoded and saved to the TTree, as well as some other attempts to extract features of the signal.  If a pulse saturates the ADC (2<sup>14</sup> = 16384), the peak is reported as 16384.

![onepulse_18595_56766_36](https://user-images.githubusercontent.com/1236965/150211124-0499dc97-85b1-44c6-ba26-600fbfa783be.png)
