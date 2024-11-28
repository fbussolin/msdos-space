#include "n24.h"
#include "n25.h"
#include "n14.h"
#include <stdlib.h>
#include <assert.h>
#include <graphics.h>

extern int maxx,maxy;

N24::N24(void):NAVE(){
   dirx=random(15)-7;
   diry=random(9)+4;
   yf=maxy*.25+random(maxy*.65);
   define(10+random(maxx-120),-30,24);
   cor=LIGHTMAGENTA;
}

void N24::anima(void){
   move(dirx,diry);
   if(y>=yf) {
      diry=-diry;
      if(!random(3)) assert(new N14(x+20,y+12)!=NULL);
      if(!random(3)) assert(new N14(x+50,y+12)!=NULL);
   }
   if(x<10||x>maxx-100) dirx=-dirx;

   if(diry<0){
      if(!random(10)) assert(new N25(x+20,y+12)!=NULL);
      if(!random(10)) assert(new N25(x+50,y+12)!=NULL);
      if(y<30){
         dirx=random(15)-7;
         diry=random(9)+4;
         yf=maxy*.25+random(maxy*.65);
      }
   }else if(!random(10)){
      dispara(x+random(100),y+2,7);
      dispara(x+random(100),y+2,10);
      dispara(x+random(100),y+2,10);
   }
}
