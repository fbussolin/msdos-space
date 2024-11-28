#include "n07.h"
#include <stdlib.h>
#include <assert.h>
#include <graphics.h>

extern int maxx,maxy;

N07::N07(void):NAVE(){
   dirx=10;
   conty=contdesce=0;
   if(!formacao.add++){
      formacao.x=0;
      formacao.y=15+random(60);
   }
   define(formacao.x-=30,formacao.y,7);
   if(formacao.add==5){
         formacao.add=0;
   }else{
      assert(new N07!=NULL);
   }
   cor=LIGHTBLUE;
}

void N07::anima(void){
   if(!conty){
      move(dirx,0);
      if(!random(100)){
         dispara(x+15,y+1,3);
         dispara(x+15,y+1,x>maxx/2?2:4);
      }
      if((x>maxx-60||(x<30&&contdesce))&&contdesce<12){
         dirx=-dirx;
         contdesce++;
         conty=3;
      }
   }else{
      move(0,8);
      conty--;
   }
   if(x>maxx) morre();
}
