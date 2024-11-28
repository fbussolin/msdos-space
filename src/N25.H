#ifndef __N25_H
#define __N25_H

#include "nave.h"

class N25:public NAVE {
   int vx;
public:
   N25(int,int);
   virtual ~N25();

   virtual void anima(void);
};

#endif