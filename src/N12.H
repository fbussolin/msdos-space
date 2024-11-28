#ifndef __N12_H
#define __N12_H

#include "nave.h"

class N12:public NAVE {
   char dirx,diry,vely;
public:
   N12(void);
   virtual void anima(void);
};

#endif