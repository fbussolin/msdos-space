#include "t05.h"
#include <graphics.h>
#include <stdlib.h>
extern int maxy;

T05::T05(int px,int py)
    :TIRO(px,py,5,7,1){
    conty=maxy/30;
    vely=5;
}

T05::~T05(void){
}

void T05::anima(void){
   move(0,vely);
   if(!--conty) vely++,conty=maxy/30;
   if(y>maxy+20) morreu=1;
}


void T05::desenha(void){
//   line(x,y,x+2,y+5);
//   line(x+2,y+5,x+4,y);
   setcolor(random(16));
   line(x,y,x+random(3),y+random(6));
   line(x+random(3),y+random(6),x+random(5),y);
}
