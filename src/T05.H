#ifndef __T05_H
#define __T05_H

#include "tiro.h"

class T05:public TIRO {
   char conty,vely;
public:

   T05(int px,int py);
   ~T05(void);

   virtual void desenha(void);
   virtual void anima(void);

};

#endif
