#ifndef __N15_H
#define __N15_H

#include "nave.h"

class N15:public NAVE {
   char animacao,vely;
public:
   N15(int px,int py);
   virtual void anima(void);
   virtual void bateu(void);
};

#endif