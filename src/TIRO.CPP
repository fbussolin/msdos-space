#include "tiro.h"
#include "nave.h"
#include "explosao.h"
#include "raspao.h"

#include <stdlib.h>
#include <graphics.h>
#include <assert.h>

TIRO *TIRO::primeiro=NULL;
TIRO *TIRO::ultimo=NULL;

extern NAVE *nave;

TIRO::TIRO(int px,int py,char ptamx,char ptamy,char pforca,char pdir){
   x=px;
   y=py;
   tamx=ptamx;
   tamy=ptamy;
   forca=pforca;
   morreu=0;
   dono=ext_dono;
   dir=pdir;

   proximo=NULL;
   anterior=ultimo;
   if(primeiro==NULL) primeiro=this;
   if(ultimo!=NULL) ultimo->proximo=this;
   ultimo=this;
}

TIRO::~TIRO(void){
   apaga();
   TIRO *atual=this;
   if(anterior!=NULL)
      anterior->proximo=proximo;
   if(proximo!=NULL)
      proximo->anterior=anterior;
   if(ultimo==atual)
      ultimo=anterior;
   if(primeiro==atual)
      primeiro=proximo;
}

void TIRO::apaga(void){
   setfillstyle(1,0);
   bar(x-1,y-1,x+tamx+1,y+tamy+1);
}

void TIRO::desenha(void){
   setcolor(random(16));
   line(x,y,x,y+random(11));
}

void TIRO::move(int px,int py){
   apaga();
   x+=px;
   y+=py;
   if(verifica())
      desenha();
   else morreu=1;
}

void TIRO::anima(void){
   move(dir,-15);
   if(y<0) morreu=1;
}

void TIRO::animacoes(void){
   TIRO *atual=primeiro;
   while(atual!=NULL){
      TIRO *prox=atual->proximo;
      atual->anima();
      if(atual->morreu)
         delete atual;
      atual=prox;
   }
}

char TIRO::verifica(void){
   int potencia;
   NAVE *natual=NAVE::primeira;
   while(natual!=NULL){
      NAVE *prox=natual->proximo;
      if(x+tamx>=natual->x&&
	  x<=natual->x+natual->tamx&&
	  y<=natual->y&&
	  y+tamy>=natual->y-natual->tamy){

         if(dono) pontos++;

         potencia=natual->forca>forca?forca:natual->forca;
         forca-=potencia;
	 if((natual->forca-=potencia)<=0) {
	    if(natual==nave) nave=NULL;
	    natual->morre();
            assert(new EXPLOSAO(x,y)!=NULL);
	 }else{
            assert(new RASPAO(x,y)!=NULL);
         }
	 return forca>0;
      }
      natual=prox;
   }
   return 1;
}
