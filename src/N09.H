#ifndef __N09_H
#define __N09_H

#include "nave.h"

class N09:public NAVE {
   char animacao,vely;
public:
   N09(int px,int py);
   virtual void anima(void);
   virtual void bateu(void);
};

#endif