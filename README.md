# wd409_sectortest

This code was originally developed for beam tests of prototype sPHENIX calorimeters around 2014.   This version is the code that has been used to analyze
cosmic ray data taken with each production sPHENIX EMCAL sector 2020-2022.  This is not production analysis code, but a quick way to take raw data taken with
the sPHENIX 14 bit 60 MHz waveform digitizers in "prdf" ("PHENIX Raw Data Format") and make it accessible to further analysis in a ROOT TTree (W).  Building the
package relies on sPHENIX libraries which are part of the sPHENIX enviroment at RCF after "source /opt/sphenix/core/bin/sphenix_setup.sh -n".  It is quite specific
to EMCAL sectors--384 ADC channels in packets 21351 and 21352, with 31 samples/tower.  If all goes well, "make" will build without errors.

The code was developed to find a reasonable way to extract the time, peak, and pedestal of the digitzied waveform.  Some of the key bracnches in the TTRee are:

* int adc[384][31] are the raw adc samples
* float peak[384] is the maximum of the waveform extracted by a cubic spline interpolation near the maximum ADC values
* float time[384] is the time (in sample number) at the peak
