#ifndef __N08_H
#define __N08_H

#include "nave.h"

class N08:public NAVE {
   char animacao,vely;
public:
   N08(int px,int py);
   virtual void anima(void);
   virtual void bateu(void);
};

#endif