#include "n08.h"
#include <stdlib.h>
#include <graphics.h>

extern int maxy;
extern char repeater;
extern NAVE *nave;

N08::N08(int px,int py):NAVE(){
   define(px,py,8);
   animacao=0;
   vely=random(4)+1;
   cor=LIGHTBLUE;
}

void N08::anima(void){
   int dx=0;
   if(animacao++>5){
      if(fig==8) animacao=3,fig=12;
      else animacao=0,fig=8;
   }
   if(nave->x>x) dx=1;
   else if(nave->x<x) dx=-1;
   move(dx,vely);
   if(y>maxy+30) morre();
}

void N08::bateu(void){
   morre();
   if(repeater>1) repeater--;
}
