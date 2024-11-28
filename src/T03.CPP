#include "t03.h"
#include <graphics.h>
#include <stdlib.h>

extern int maxy;

T03::T03(int px,int py,char pdir)
    :TIRO(px-1,py,5,6,1,pdir){
}

T03::~T03(void){
}

void T03::anima(void){
   if(y<-30) morreu=1; else move(0,-15);
}


void T03::desenha(void){
//   line(x,y,x+2,y+2);
//   line(x+2,y+2,x+4,y);
   setcolor(random(16));
   line(x,y,x+4,y+random(7));
   line(x,y+random(7),x+4,y);
}
