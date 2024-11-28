#include "n10.h"
#include <stdlib.h>
#include <graphics.h>

extern int maxy;
extern NAVE *nave;

N10::N10(int px,int py):NAVE(){
   define(px,py,10);
   animacao=0;
   vely=random(4)+1;
   cor=LIGHTCYAN;
}

void N10::anima(void){
   int dx=0;
   if(animacao++>5){
      if(fig==10) animacao=3,fig=8;
      else animacao=0,fig=10;
   }
   if(nave->x>x) dx=2;
   else if(nave->x<x) dx=-2;
   move(dx,vely);
   if(y>maxy+30) morre();
}

void N10::bateu(void){
   morre();
   nave->forca+=4;
}
