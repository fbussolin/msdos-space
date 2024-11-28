#include "n20.h"
#include <stdlib.h>
#include <assert.h>
#include <graphics.h>
#include "n11.h"
#include "explosao.h"

extern int maxx,maxy;
extern NAVE *nave;

N20::N20(void):NAVE(){
   dirx=(random(2)?1:-1)*(3+random(5));
   define(dirx>0?-30:maxx,30+random(maxy/2),20);
   cor=LIGHTBLUE;
}

N20::~N20(void){
   for(char i=0;i<3;i++)
   assert(new N11(x+random(20),y+random(20))!=NULL);
   for(int cont=0;cont<10;cont++) assert(new EXPLOSAO(-(x+random(tamx)),y-30)!=NULL);
}

void N20::anima(void){
   move(dirx,x+40>nave->x&&x<nave->x+30?7:y>50&&!random(3)?-1:0);
   if(!random(100)) dispara(x+15,y+1,7);
   if(y>maxy+40) morre();
   if((x<10&&dirx<0)||(x>maxx-60&&dirx>0)) dirx=-dirx;
}
