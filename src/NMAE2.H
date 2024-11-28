#ifndef __NMAE2_H
#define __NMAE2_H

#include "nave.h"

class NMAE2:public NAVE {
   char dirx,diry,estagio;
   int cont;
public:
   NMAE2(int);
   virtual ~NMAE2();
   virtual void anima(void);
};

#endif