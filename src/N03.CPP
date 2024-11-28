#include "n03.h"
#include <stdlib.h>
#include <assert.h>
#include <graphics.h>

extern int maxx,maxy;

N03::N03(void):NAVE(){
   dirx=1;
   if(!formacao.add++){
      velx=-9;
      define(formacao.x=random(maxx-50),formacao.y=-30,3);
      assert(new N03!=NULL);
   }else{
      velx=formacao.add==2?-7:-5;
      define(formacao.x+(formacao.add==2?16:26),formacao.y-=30,3);
      if(formacao.add==3){
         formacao.add=0;
      }else{
         assert(new N03!=NULL);
      }
   }
   cor=RED;
}

void N03::anima(void){
   move(velx,3);
   velx-=dirx;
   if(abs(velx)==10){
      dirx*=-1;
      dispara(x+15,y+1,1);
   }
   if(y>maxy+30) morre();
}
