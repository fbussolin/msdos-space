#ifndef __T03_H
#define __T03_H

#include "tiro.h"

class T03:public TIRO {
public:

   T03(int px,int py,char pdir);
   ~T03(void);

   virtual void desenha(void);
   virtual void anima(void);

};

#endif
