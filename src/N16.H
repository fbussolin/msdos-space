#ifndef __N16_H
#define __N16_H

#include "nave.h"

class N16:public NAVE {
   char dirx,diry,first;
   int upy;
public:
   N16(void);
   virtual ~N16(void);
   virtual void anima(void);
};

#endif