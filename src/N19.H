#ifndef __N19_H
#define __N19_H

#include "nave.h"

class N19:public NAVE {
   char dirx,diry,stop;
   int contx;
public:
   N19(void);
   ~N19(void);
   virtual void anima(void);
};

#endif