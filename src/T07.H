#ifndef __T07_H
#define __T07_H

#include "tiro.h"

class T07:public TIRO {
public:

   T07(int px,int py);
   ~T07(void);

   virtual void desenha(void);
   virtual void anima(void);

};

#endif
