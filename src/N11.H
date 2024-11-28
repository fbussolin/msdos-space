#ifndef __N11_H
#define __N11_H

#include "nave.h"

class N11:public NAVE {
   char animacao,vely;
public:
   N11(int px,int py);
   virtual void anima(void);
   virtual void bateu(void);
};

#endif