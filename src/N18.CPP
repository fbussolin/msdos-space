#include "n18.h"
#include "n11.h"
#include "explosao.h"

#include <stdlib.h>
#include <assert.h>
#include <graphics.h>

extern int maxx,maxy;

N18::N18(void):NAVE(){
   conty=4;
   dirx=random(2)?10:-10;
   define(dirx>0?-50:maxx+50,0,18);
   cor=BROWN;
}

N18::~N18(void){
   assert(new N11(x,y)!=NULL);
   for(int cont=0;cont<10;cont++) assert(new EXPLOSAO(-(x+random(tamx)),y-30)!=NULL);
}

void N18::anima(void){
   move(dirx,!conty?1:0);
   if(!conty--) conty=4;
   if((x>maxx-60&&dirx>0)||(x<10&&dirx<0)) dirx=-dirx;
   if(!random(15))dispara(x+25,y+3,10);
   if(y>maxy+40) morre();
}
