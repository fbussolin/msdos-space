#ifndef __N02_H
#define __N02_H

#include "nave.h"

class N02:public NAVE {
   char dirx,diry;
   int yf;
public:
   N02(void);
   virtual void anima(void);
};

#endif