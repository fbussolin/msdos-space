#ifndef __N21_H
#define __N21_H

#include "nave.h"

class N21:public NAVE {
   char dirx,diry;
public:
   N21(void);
   ~N21(void);
   virtual void anima(void);
};

#endif