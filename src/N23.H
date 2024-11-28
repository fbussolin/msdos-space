#ifndef __N23_H
#define __N23_H

#include "nave.h"

class N23:public NAVE {
   int dx,dy;
   char stop,disp;
public:
   N23(void);
   virtual ~N23();
   virtual void anima(void);
};

#endif