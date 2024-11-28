#include "n16.h"
#include "n09.h"
#include "explosao.h"

#include <stdlib.h>
#include <assert.h>
#include <graphics.h>

extern int maxx,maxy;

N16::N16(void):NAVE(){
   first=0;
   dirx=diry=4;
   define(-50,upy=60+random(maxy*.10),16);
   cor=RED;
}

N16::~N16(void){
   assert(new N09(x,y)!=NULL);
   for(int cont=0;cont<10;cont++) assert(new EXPLOSAO(-(x+random(tamx)),y-30)!=NULL);
}

void N16::anima(void){
   move(dirx,diry);
   if(x>maxx-60||(x<10&&first)) first=dirx=-dirx;
   if(y<upy||y>upy+50){
      diry=-diry;
      if(y<upy){
         dispara(x+5,y+1,1);
         dispara(x+45,y+1,1);
      }else{
         dispara(x+25,y+1,1);
      }
   }
}
