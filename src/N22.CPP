#include "n22.h"
#include <stdlib.h>
#include <graphics.h>
#include "explosao.h"
#include <assert.h>

extern int maxx,maxy;

N22::N22(void):NAVE(){
   dirx=3;
   vely=15;
   diry=-1;
   cont=0;
   define(-30,maxy/4+random(maxy/2),22);
   cor=LIGHTCYAN;
}

N22::~N22(){
   for(int cont=0;cont<10;cont++) assert(new EXPLOSAO(-(x+random(tamx)),y-30)!=NULL);
}

void N22::anima(void){
   if(cont++<50){
      move(dirx,vely*diry);
      if(x>maxx-35||(x<5&&dirx<0)) dirx=-dirx;
      vely+=diry;
      if(!vely||vely==16){
         vely-=diry; diry=-diry;
      }
      if((vely<3||vely>13)&&!random(2)) dispara(x+10+random(10),y+10,7);
   }else{
      move(random(3)-1,random(3)-1);
      if(cont>80) cont=0;
      if(!random(5)) dispara(x+10+random(10),y+10,8);
      if(!random(3)) dispara(x+10+random(10),y+10,10);
   }
}
