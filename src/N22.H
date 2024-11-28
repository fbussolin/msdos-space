#ifndef __N22_H
#define __N22_H

#include "nave.h"

class N22:public NAVE {
   char dirx,diry,vely,cont;
public:
   N22(void);
   virtual ~N22();
   virtual void anima(void);
};

#endif