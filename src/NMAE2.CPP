#include "nmae2.h"

#include "n07.h"
#include "n14.h"
#include "explosao.h"

#include <stdlib.h>
#include <assert.h>
#include <graphics.h>

extern int maxx,maxy;

NMAE2::NMAE2(int tipo):NAVE(){
   dirx=tipo==29?1:-1;
   diry=1;
   define(tipo==29?-70:maxx+1,0,tipo);
   cont=estagio=0;
   cor=LIGHTBLUE;
}

NMAE2::~NMAE2(){
   int cont;
   for(cont=1;cont<50;cont++){
      assert(new EXPLOSAO((x+random(tamx))*-1,y-30)!=NULL);
   }
}

void NMAE2::anima(void){
   cont++;
   if(cont==70||
      cont==70+(int)(maxy*.6)||
      cont==170+(int)(maxy*.6)){
      estagio++;
      if(estagio==1){
         dirx=0;
      }else if(estagio==2){
         diry=0;
      }else{
         if(fig==29) dirx=-1; else dirx=1;
         diry=-1;
      }
   }
   move(dirx,diry);
   if(x<-80||x>maxx) morre();
   if(!(cont%5)) dispara(fig==29?x+70:x-3,y-random(maxy),fig==29?4:2);
   if(!(cont%10)) dispara(x+random(70),y+1,fig==29?4:2);
   if(!(cont%15)) dispara(x+random(70),y+1,7);

   if(!(cont%100)) assert(new N14(fig==29?x+50:x+20,fig==29?y-80:y-110)!=NULL);
}
