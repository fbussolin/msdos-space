#ifndef __N07_H
#define __N07_H

#include "nave.h"

class N07:public NAVE {
   char dirx;
   char conty;
   char contdesce;
public:
   N07(void);
   virtual void anima(void);
};

#endif