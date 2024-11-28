#include "n13.h"
#include <stdlib.h>
#include <assert.h>
#include <graphics.h>

extern int maxx,maxy;

N13::N13(void):NAVE(){
   if(!formacao.add++){
      formacao.x=random(maxx-90)-30;
   }
   disp=formacao.add;
   vely=formacao.add*3;
   define(formacao.x+=30,-30,13);
   if(formacao.add==3){
         formacao.add=0;
   }else{
      assert(new N13!=NULL);
   }
   cor=YELLOW;
}

void N13::anima(void){
   move(0,vely--);
   if(!vely){
      vely=6;
      if(!--disp){
         disp=5;
         dispara(x+15,y+1,7);
      }
   }
   if(y>maxy+30) morre();
}
