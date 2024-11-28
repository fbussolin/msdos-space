#include "nmae.h"
#include "explosao.h"
#include <stdlib.h>
#include <graphics.h>
#include <assert.h>

extern int maxx,maxy;

NMAE::NMAE(int tipo):NAVE(){
   dirx=1;
   define(10+random(maxx-tipos[tipo].tx-20),0,tipo);
   cont=0;
   cor=RED;
}

NMAE::~NMAE(){
   int cont;
   for(cont=1;cont<50;cont++){
      assert(new EXPLOSAO((x+random(tamx))*-1,y-30)!=NULL);
   }
}

void NMAE::anima(void){
   int diry=0;
   if(x<1||x+tamx>maxx-2) dirx=-dirx;
   if(y<tamy+10&&++cont>5)cont=diry=1;
   move(dirx,diry);

   if(!random(fig==26?5:fig==27?4:2)) dispara(x+random(tamx),y+1,10);
   if(!random(fig==26?10:fig==27?7:4)) dispara(x+random(tamx),y+1,7);
}
