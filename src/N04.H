#ifndef __N04_H
#define __N04_H

#include "nave.h"

class N04:public NAVE {
   int yf;
   char dispcont,dispdir;
public:
   N04(void);
   virtual void anima(void);
};

#endif