#ifndef __T01_H
#define __T01_H

#include "tiro.h"

class T01:public TIRO {
public:

   T01(int px,int py);
   ~T01(void);

   virtual void desenha(void);
   virtual void anima(void);

};

#endif
