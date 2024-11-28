#include "t07.h"
#include <stdlib.h>
#include <graphics.h>

extern int maxy;

T07::T07(int px,int py)
    :TIRO(px,py,1,20,1){
}

T07::~T07(void){
}

void T07::anima(void){
   if(y>maxy+20) morreu=1; else move(0,10);
}


void T07::desenha(void){
   setcolor(random(16));
   line(x,y,x,y+19);
}
