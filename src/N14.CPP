#include "N14.h"
#include <stdlib.h>
#include <graphics.h>

extern int maxx,maxy;

N14::N14(int px,int py):NAVE(){
   if(px==-120&&py==-120){
      define(random(maxx-30),-30,15);
   }else{
      define(px,py,15);
   }
   dx=random(maxx-30);
   dy=random(maxy-60);
   stop=0;
   cor=GREEN;
}

void N14::anima(void){
   if(stop){
      if(!(--stop%10)) dispara(x+15,y+3,8);
      if(!stop) fig=15;
      move(0,0);
   }else{
      if(abs(x-dx)<6&&abs(y-dy)<6){
         dx=random(maxx-30);
         dy=random(maxy-60);
         stop=40;
         fig=14;
      }
      move(x>dx+5?-5:x<dx-5?5:0,y>dy+5?-5:y<dy-5?5:0);
   }
}
