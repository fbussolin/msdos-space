#include "t01.h"
#include <stdlib.h>
#include <graphics.h>

extern int maxy;

T01::T01(int px,int py)
    :TIRO(px,py,3,3,1){
}

T01::~T01(void){
}

void T01::anima(void){
   if(y>maxy+20) morreu=1; else move(0,5);
}


void T01::desenha(void){
   setcolor(random(16));
   rectangle(x,y,x+2,y+2);
}
