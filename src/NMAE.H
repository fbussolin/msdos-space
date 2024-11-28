#ifndef __NMAE_H
#define __NMAE_H

#include "nave.h"

class NMAE:public NAVE {
   char dirx,cont;
public:
   NMAE(int);
   virtual ~NMAE();
   virtual void anima(void);
};

#endif