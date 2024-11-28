#include "t04.h"
#include "raspao.h"
#include <graphics.h>
#include <stdlib.h>

extern int maxy;

T04::T04(int px,int py)
    :TIRO(px,py,7,8,25){
   nr=0;
}

T04::~T04(void){
}

void T04::anima(void){
   if(y<-30) morreu=1; else move(random(3)-1,-7);
   if(nr++>2){
       nr=0;
       new RASPAO(x,y+12);
   }
}


void T04::desenha(void){
   setcolor(MAGENTA);
   line(x+3,y,x,y+4);
   line(x+3,y,x+6,y+4);
   line(x,y+4,x+3,y+2);
   line(x+4,y+2,x+6,y+4);

   line(x+2,y+3,x+1,y+7);
   line(x+1,y+7,x+3,y+5);

   line(x+4,y+3,x+5,y+7);
   line(x+5,y+7,x+3,y+5);

}
