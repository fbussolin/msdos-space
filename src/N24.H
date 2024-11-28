#ifndef __N24_H
#define __N24_H

#include "nave.h"

class N24:public NAVE {
   char dirx,diry;
   int yf;
public:
   N24(void);
   virtual void anima(void);
};

#endif