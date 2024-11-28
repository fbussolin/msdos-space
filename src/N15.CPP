#include "n15.h"
#include <stdlib.h>
#include <graphics.h>

extern int maxy;
extern char goodisp;
extern NAVE *nave;
N15::N15(int px,int py):NAVE(){
   define(px,py,8);
   animacao=0;
   vely=random(4)+1;
   cor=CYAN;
}

void N15::anima(void){
   int dx=0;
   if(animacao++>5){
      if(fig==8) animacao=3,fig=15;
      else animacao=0,fig=8;
   }
   if(nave->x>x) dx=1;
   else if(nave->x<x) dx=-1;
   move(dx,vely);
   if(y>maxy+30) morre();
}

void N15::bateu(void){
   morre();
   goodisp++;
}
