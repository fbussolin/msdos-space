#include "n19.h"
#include "n10.h"
#include "explosao.h"

#include <stdlib.h>
#include <assert.h>
#include <graphics.h>

extern int maxx,maxy;

N19::N19(void):NAVE(){
   dirx=8;
   diry=0;
   contx=random(500);
   define(-50,60+random(maxy*.10),19);
   cor=LIGHTGRAY;
}

N19::~N19(void){
   assert(new N10(x,y)!=NULL);
   for(int cont=0;cont<10;cont++) assert(new EXPLOSAO(-(x+random(tamx)),y-30)!=NULL);
}

void N19::anima(void){
   if(contx){
      if(!--contx){
         diry=15;
         stop=0;
      }else{
         move(dirx,diry);
         if((x<10&&dirx<0)||x>maxx-60) dirx=-dirx;
         if(y<80) diry=0;
         if(!random(50)) dispara(x+25,y+5,8);
      }
   }else{
      if(diry>0&&!stop){
         move(0,diry);
         if(y>maxy-40){
            stop=random(100);
            diry=-diry;
         }
      }else{
         if(stop){
            desenha();
            stop--;
         }else{
            contx=random(500);
         }
      }
   }
}
