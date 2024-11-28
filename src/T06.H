#ifndef __T06_H
#define __T06_H

#include "tiro.h"

class T06:public TIRO {
   char maxcontx,contx,cfig,dirx,velx;
public:

   T06(int px,int py);
   ~T06(void);

   virtual void desenha(void);
   virtual void anima(void);

};

#endif
