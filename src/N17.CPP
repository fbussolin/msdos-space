#include "n17.h"
#include "n10.h"
#include "explosao.h"

#include <stdlib.h>
#include <assert.h>
#include <graphics.h>

extern int maxx,maxy;

N17::N17(void):NAVE(){
   first=0;
   dirx=-1;
   velx=15;
   define(maxx+50,60+random(maxy*.10),17);
   cor=MAGENTA;
}

N17::~N17(void){
   assert(new N10(x,y)!=NULL);
   for(int cont=0;cont<10;cont++) assert(new EXPLOSAO(-(x+random(tamx)),y-30)!=NULL);
}

void N17::anima(void){
   move(velx--*dirx,0);
   if((x>maxx-60&&first)||x<10) first=dirx=-dirx;
   if(!velx){
      velx=15;
      dispara(x+25,y+1,2);
      dispara(x+25,y+1,4);
   }else if(velx==14){
      dispara(x+25,y+1,3);
   }
}
