#ifndef __N20_H
#define __N20_H

#include "nave.h"

class N20:public NAVE {
   char dirx;
public:
   N20(void);
   ~N20(void);
   virtual void anima(void);
};

#endif