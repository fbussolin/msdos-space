#include "n01.h"
#include <graphics.h>
#include <stdlib.h>

extern int maxx,maxy;

N01::N01(void):NAVE(){
   dirx=(random(2)?1:-1)*(3+random(5));
   define(dirx>0?-30:maxx,30+random(maxy/2),1);
   cor=GREEN;
}

void N01::anima(void){
   move(dirx,0);
   if(!random(100)) dispara(x+15,y+1,1);
   if(x<-30||x>maxx) morre();
}
