#ifndef __T04_H
#define __T04_H

#include "tiro.h"

class T04:public TIRO {
public:
   char nr;
   T04(int px,int py);
   ~T04(void);

   virtual void desenha(void);
   virtual void anima(void);

};

#endif
