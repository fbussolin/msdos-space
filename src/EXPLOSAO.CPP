#include "explosao.h"

#include <stdlib.h>
#include <graphics.h>

EXPLOSAO *EXPLOSAO::primeiro=NULL;
EXPLOSAO *EXPLOSAO::ultimo=NULL;

EXPLOSAO::EXPLOSAO(int px,int py){
   if(px<10){
      contador=-random(50);
      px=-px;
   }else{
      contador=-random(6);
   }
   for(int i=0;i<MAXexplosao;i++){
      x1[i]=px+random(21)-10;
      y1[i]=py+random(21)-10;
      velx[i]=random(11)-5;
      vely[i]=random(11)-5;
      x2[i]=x1[i]+5*velx[i];
      y2[i]=y1[i]+5*vely[i];
   }

   proximo=NULL;
   anterior=ultimo;
   if(primeiro==NULL) primeiro=this;
   if(ultimo!=NULL) ultimo->proximo=this;
   ultimo=this;
}

EXPLOSAO::~EXPLOSAO(void){
   apaga();
   EXPLOSAO *atual=this;
   if(anterior!=NULL) anterior->proximo=proximo;
   if(proximo!=NULL) proximo->anterior=anterior;
   if(ultimo==atual) ultimo=anterior;
   if(primeiro==atual) primeiro=proximo;
}


void EXPLOSAO::desenha(int cor){
   if(cor) cor=random(2)?LIGHTBLUE:DARKGRAY;
   setcolor(cor);
   for(int i=0;i<MAXexplosao;i++){
      line(x1[i],y1[i],x2[i],y2[i]);
   }
}

void EXPLOSAO::anima(void){
   apaga();
   for(int i=0;i<MAXexplosao;i++){
      x1[i]+=velx[i];
      y1[i]+=vely[i];
      x2[i]+=velx[i]/1.5;
      y2[i]+=vely[i]/1.5;
   }
   if(contador++>10) delete this; else desenha();
}

void EXPLOSAO::animacoes(void){
   EXPLOSAO *atual=primeiro;
   while(atual!=NULL){
      EXPLOSAO *prox=atual->proximo;
      atual->anima();
      atual=prox;
   }
}

