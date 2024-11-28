#include "t06.h"
#include <stdlib.h>
#include <graphics.h>
#include "nave.h"

extern int maxy;
extern NAVE *nave;

T06::T06(int px,int py)
    :TIRO(px,py,7,7,1){
    contx=maxcontx=8;
    cfig=0;
    dirx=(x>nave->x)?-1:1;
    velx=2;
}

T06::~T06(void){
}

void T06::anima(void){
   if(!--contx){
      if(maxcontx>1)maxcontx--;
      contx=maxcontx;
      velx++;
   }
   move(dirx*velx*.6,8);
   if(y>maxy+20) morreu=1;
}


void T06::desenha(void){
   setcolor(random(16));
   line(x+3-cfig,y+3,x+3+cfig,y+3);
   line(x+3,y+3-cfig,x+3,y+3+cfig);
   if(++cfig==4) cfig=0;
}
