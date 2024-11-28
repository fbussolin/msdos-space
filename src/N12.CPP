#include "n12.h"
#include <stdlib.h>
#include <graphics.h>

extern int maxx,maxy;

N12::N12(void):NAVE(){
   dirx=2;
   vely=13;
   diry=-1;
   define(-30,maxy-30,12);
   cor=LIGHTMAGENTA;
}

void N12::anima(void){
   move(dirx,vely*diry);
   if(x>maxx-35||(x<5&&dirx<0)) dirx=-dirx;
   vely+=diry;
   if(!vely||vely==14){vely-=diry; diry=-diry;}
}
