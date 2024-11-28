#include "n11.h"
#include <stdlib.h>
#include <graphics.h>

extern int maxy;
extern char misseis;
extern NAVE *nave;

N11::N11(int px,int py):NAVE(){
   define(px,py,11);
   animacao=0;
   vely=random(4)+1;
   cor=LIGHTRED;
}

void N11::anima(void){
   int dx=0;
   if(animacao++>5){
      if(fig==11) animacao=3,fig=8;
      else animacao=0,fig=11;
   }
   if(nave->x>x) dx=2;
   else if(nave->x<x) dx=-2;
   move(dx,vely);
   if(y>maxy+30) morre();
}

void N11::bateu(void){
   morre();
   misseis++;
}
