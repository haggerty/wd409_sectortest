#ifndef __WD409DATA_H__
#define __WD409DATA_H__

#include "TObject.h"

static const int NRMOD = 6;
static const int NMODBYXMIT[] = {3,3};

static const int NXMIT = sizeof(NMODBYXMIT)/sizeof(*NMODBYXMIT);
static const int PACKET[NXMIT] = {21351, 21352};

static const int NCHANPERMOD = 64;
static const int NRSAM = 31;
static const int NPEDSAM = 3;

class wd409data
{

 public:
  int runnumber;
  int evtnr;
  int clock;

  int evenchecksum;
  int calcevenchecksum;
  int oddchecksum;
  int calcoddchecksum;

  int femslot[NRMOD];
  int femevtnr[NRMOD];
  int femclock[NRMOD];

  int adc[NRMOD*NCHANPERMOD][NRSAM];
  float mean[NRMOD*NCHANPERMOD];
  float rms[NRMOD*NCHANPERMOD];
  int minadc[NRMOD*NCHANPERMOD];
  int maxadc[NRMOD*NCHANPERMOD];
  float pedestal[NRMOD*NCHANPERMOD];
  float pedsig[NRMOD*NCHANPERMOD];
  float peak[NRMOD*NCHANPERMOD];
  float time[NRMOD*NCHANPERMOD];
  float integral[NRMOD*NCHANPERMOD];
  float integral2[NRMOD*NCHANPERMOD];

  int summary[NXMIT];

  wd409data() {
    runnumber = 0;

  };
  
  ~wd409data() {
  }; 

};

#endif /* __WD409DATA_H__ */
