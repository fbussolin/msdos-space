#include "raspao.h"

#include <stdlib.h>
#include <graphics.h>

RASPAO *RASPAO::primeiro=NULL;
RASPAO *RASPAO::ultimo=NULL;

RASPAO::RASPAO(int px,int py){
   abrangencia=2;
   for(int i=0;i<MAXraspao;i++){
      x[i]=px+random(abrangencia+1)-abrangencia/2;
      y[i]=py+random(abrangencia+1)-abrangencia/2;
   }
   contador=0;

   proximo=NULL;
   anterior=ultimo;
   if(primeiro==NULL) primeiro=this;
   if(ultimo!=NULL) ultimo->proximo=this;
   ultimo=this;
}

RASPAO::~RASPAO(void){
   apaga();
   RASPAO *atual=this;
   if(anterior!=NULL) anterior->proximo=proximo;
   if(proximo!=NULL) proximo->anterior=anterior;
   if(ultimo==atual) ultimo=anterior;
   if(primeiro==atual) primeiro=proximo;
}

void RASPAO::apaga(void){
   for(int i=0;i<MAXraspao;i++){
      putpixel(velx[i],vely[i],0);
   }
}

void RASPAO::desenha(void){
   for(int i=0;i<MAXraspao;i++){
      putpixel(velx[i],vely[i],random(2)?DARKGRAY:BROWN);
   }
}

void RASPAO::anima(void){
   apaga();
   abrangencia+=3;
   for(int i=0;i<MAXraspao;i++){
      velx[i]=x[i]+random(abrangencia+1)-abrangencia/2;
      vely[i]=y[i]+random(abrangencia+1)-abrangencia/2;
   }
   if(contador++>9) delete this; else desenha();
}

void RASPAO::animacoes(void){
   RASPAO *atual=primeiro;
   while(atual!=NULL){
      RASPAO *prox=atual->proximo;
      atual->anima();
      atual=prox;
   }
}

