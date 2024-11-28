#ifndef __T02_H
#define __T02_H

#include "tiro.h"

class T02:public TIRO {
   char dir;
   char raio,rd;
public:

   T02(int px,int py,char pdir);
   ~T02(void);

   virtual void desenha(void);
   virtual void anima(void);

};

#endif
