#include "n04.h"
#include <stdlib.h>
#include <graphics.h>

extern int maxx,maxy;

N04::N04(void):NAVE(){
   yf=maxy*.25+random(maxy*.5);
   dispcont=dispdir=0;
   define(random(maxx-30),-30,4);
   cor=MAGENTA;
}

void N04::anima(void){
   if(y<yf) move(0,random(4));
   else{
      desenha();
      if(dispcont++>10){
         dispcont=0;
         dispara(x+15,y+1,2+dispdir);
         if(++dispdir==3) dispdir=0;
      }
   }
}
