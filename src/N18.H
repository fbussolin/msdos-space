#ifndef __N18_H
#define __N18_H

#include "nave.h"

class N18:public NAVE {
   char dirx,conty;
public:
   N18(void);
   virtual ~N18(void);
   virtual void anima(void);
};

#endif