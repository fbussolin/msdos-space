#ifndef __N03_H
#define __N03_H

#include "nave.h"

class N03:public NAVE {
   char dirx;
   int velx;
   static char grupo;
public:
   N03(void);
   virtual void anima(void);
};

#endif