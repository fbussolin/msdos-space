#ifndef __N14_H
#define __N14_H

#include "nave.h"

class N14:public NAVE {
   int dx,dy;
   char stop;
public:
   N14(int=-120,int=-120);
   virtual void anima(void);
};

#endif