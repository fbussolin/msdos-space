#include "n25.h"
#include <stdlib.h>
#include <graphics.h>
#include "explosao.h"
#include <assert.h>

extern int maxx,maxy;

N25::N25(int px,int py):NAVE(){
   define(px,py,25);
   vx=3;
   cor=YELLOW;
}

N25::~N25(){
   for(int cont=0;cont<10;cont++) assert(new EXPLOSAO(-(x+random(tamx)),y-30)!=NULL);
}

void N25::anima(void){
   move(0,vx+=2);
   if(y>maxy+20) morre();
}
