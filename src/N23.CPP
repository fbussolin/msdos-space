#include "N23.h"
#include "N25.h"
#include "N14.h"
#include <stdlib.h>
#include <assert.h>
#include <graphics.h>
#include "explosao.h"

extern int maxx,maxy;

N23::N23(void):NAVE(){
   define(random(maxx-30),-30,23);
   dx=random(maxx-30);
   dy=random(maxy-60);
   stop=disp=0;
   cor=LIGHTRED;
}

N23::~N23(){
   for(int cont=0;cont<10;cont++) assert(new EXPLOSAO(-(x+random(tamx)),y-30)!=NULL);
}

void N23::anima(void){
   if(stop){
      move(0,0);
      if(disp){
         if(!(--stop%10)) assert(new N25(x+40,y+12)!=NULL);
      }else{
         if(!(--stop%20)) assert(new N14(x+40,y+12)!=NULL);
      }
   }else{
      if(abs(x-dx)<6&&abs(y-dy)<6){
         dx=random(maxx-30);
         dy=random(maxy-60);
         stop=80;
         disp=random(3);
      }
      move(x>dx+5?-5:x<dx-5?5:0,y>dy+5?-5:y<dy-5?5:0);
   }
}

