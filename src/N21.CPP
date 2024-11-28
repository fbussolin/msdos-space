#include "n21.h"
#include <stdlib.h>
#include <assert.h>
#include <graphics.h>
#include "n11.h"
#include "explosao.h"

extern int maxx,maxy;
extern NAVE *nave;

N21::N21(void):NAVE(){
   dirx=(random(2)?1:-1)*(random(5)+1);
   diry=-1;
   define(dirx>0?-30:maxx,maxy-random(maxy/4),21);
   cor=LIGHTGREEN;
}

N21::~N21(void){
   for(int cont=0;cont<10;cont++) assert(new EXPLOSAO(-(x+random(tamx)),y-30)!=NULL);
//   for(char i=0;i<3;i++)
//      assert(new N11(x+random(20),y+random(20))!=NULL);
}

void N21::anima(void){
   move(dirx,diry);
   if(!random(10)) dispara(x+15,y+1,10);
   if(y<10) diry=-diry;
   if(y>maxy+30) morre();
   if((x<10&&dirx<0)||(x>maxx-60&&dirx>0)) dirx=-dirx;
}
