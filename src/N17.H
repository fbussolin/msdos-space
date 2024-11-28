#ifndef __N17_H
#define __N17_H

#include "nave.h"

class N17:public NAVE {
   char dirx,first;
   int velx;
public:
   N17(void);
   virtual ~N17(void);
   virtual void anima(void);
};

#endif