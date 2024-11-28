#include "n05.h"
#include <stdlib.h>
#include <graphics.h>

extern int maxx,maxy;

N05::N05(void):NAVE(){
   diry=4;
   conty=0;
   define(random(maxx-30),-30,5);
   cor=BROWN;
}

void N05::anima(void){
   move(0,diry);
   if(++conty>30){
      conty=0;
      dispara(x,y+1,2);
      dispara(x+30,y+1,4);
      if(diry==4){
         diry=-2;
         fig=6;
      }else{
         diry=4;
         fig=5;
      }
   }
   if(y>maxy+30) morre();
}
