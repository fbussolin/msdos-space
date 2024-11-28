#ifndef __N10_H
#define __N10_H

#include "nave.h"

class N10:public NAVE {
   char animacao,vely;
public:
   N10(int px,int py);
   virtual void anima(void);
   virtual void bateu(void);
};

#endif