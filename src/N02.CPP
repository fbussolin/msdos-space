#include "n02.h"
#include <stdlib.h>
#include <graphics.h>

extern int maxx,maxy;

N02::N02(void):NAVE(){
   dirx=random(2)?1:-1;
   diry=random(4)+2;
   yf=maxy*.25+random(maxy*.75);
   define(maxx/2+(random(maxx/2)*(dirx>0?-1:1)),-30,2);
   cor=CYAN;
}

void N02::anima(void){
   move(dirx,diry);
   if(y>=yf) {
      diry=-diry;
      dispara(x+15,y+1,1);
   }

   if(!random(100)) dispara(x+15,y+1,1);
   if(y<-30) morre();
}
