#include "t02.h"
#include <stdlib.h>
#include <graphics.h>

extern int maxy;

T02::T02(int px,int py,char pdir)
    :TIRO(px,py,8,8 ,1){
    dir=pdir;
    rd=0;
    raio=1;
}

T02::~T02(void){
}

void T02::anima(void){
   if(y>maxy+20) morreu=1; else move(!dir?-3:dir==1?0:3,8);
}


void T02::desenha(void){
   setcolor(random(16));
   circle(x+4,y+4,raio);
   if(rd==0){
      if(++raio==4) rd=1;
   }else{
      if(--raio==1) rd=0;
   }
}
