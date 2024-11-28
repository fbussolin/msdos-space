#include "n09.h"
#include <stdlib.h>
#include <graphics.h>

extern int maxy;
extern char potencia;
extern NAVE *nave;

N09::N09(int px,int py):NAVE(){
   define(px,py,9);
   animacao=0;
   vely=random(4)+1;
   cor=LIGHTGREEN;
}

void N09::anima(void){
   int dx=0;
   if(animacao++>5){
      if(fig==9) animacao=3,fig=8;
      else animacao=0,fig=9;
   }
   if(nave->x>x) dx=2;
   else if(nave->x<x) dx=-2;
   move(dx,vely);
   if(y>maxy+30) morre();
}

void N09::bateu(void){
   morre();
   potencia++;
}
