#include <string.h>
#include <graphics.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>
#include <assert.h>
#include <stdio.h>
#include <time.h>

#include "akey.h"

//#include "\flavio\cpp\lib\io\io.hpp"
#include "nave.h"
#include "fases.h"
#include "fases1.h"
#include "tiro.h"
#include "explosao.h"
#include "raspao.h"

int ext_dono=0;
int maxx,maxy;

NAVE *nave;

void dispara(char);

int fase=0,pontos=0;

char potencia,misseis;
int contador,saida;

char fim_frase[]="Fim do Jogo",
     pausa[]="Pausa";

char repeater,goodisp;

void main(void){
   int gD=DETECT,gM;
   initgraph(&gD,&gM,"\\ling\\tc\\bgi\\");

   maxx=getmaxx();
   maxy=getmaxy();

   randomize();

   setcolor(15);

   set_new_int9();

   int last_pts=1000;
   for(;;){

      do{
         gotoxy(1,1);printf("%02d %4d",fase+1,pontos);
         clock_t clocki=clock();

         assert(new RASPAO(random(maxx),random(maxy)));
         if(!random(10)) assert(new EXPLOSAO(random(maxx),random(maxy)));

         EXPLOSAO::animacoes();
         RASPAO::animacoes();
         TIRO::animacoes();

//	 key=inkey();

         gotoxy(44,1);printf("Space (c)1993 Moacir Flavio Goncalves");

         while(((clock()-clocki)/CLK_TCK)<.009);
      }while(!_pressed_keys_[kSPACE]&&!_pressed_keys_[kESC]);
      gotoxy(44,1);printf("                                     ");
      if(_pressed_keys_[kESC]){
         break;
      }

      nave=new NAVE;

      nave->define(maxx/2,maxy-10,0);

      char dir=0;

      saida=0;


      char lastforca=0,lastmisseis=0;
      contador=0;
      repeater=7;
      goodisp=0;
      potencia=0;
      misseis=15;
      pontos=0;
      int imppontos=0;
      fase=0;

      do{
         clock_t clocki=clock();

         if(imppontos<pontos){
            if(nave==NULL){
               imppontos=pontos;
            }else{
               imppontos+=1+(pontos-imppontos)/10;
            }
         }

         gotoxy(1,1);printf("%02d %4d",fase+1,imppontos);
         if(pontos>last_pts){
            last_pts+=750;
            nave->forca+=3;
            misseis+=3;
            if(potencia<30) potencia++;
         }

         if(contador<50){
            int a,b;
            char frase[9]="Fase ";
            strcpy(frase+5,ecvt(fase+1,2,&a,&b));
            setfillstyle(1,0);
            bar(maxx/2-textwidth(frase)/2,maxy/2-contador+1,maxx/2+textwidth(frase)/2,maxy/2+textheight(frase));
            if(contador<49){
               if(fase<9) frase[6]=0;
               outtextxy(maxx/2-textwidth(frase)/2,maxy/2-contador,frase);
            }
         }

         if(_pressed_keys_[kESC]) saida=1;
         else if(_pressed_keys_[kP]){
            outtextxy(maxx/2-textwidth(pausa)/2,maxy/2,pausa);
            char sair=0;
            while(!sair)sair=_pressed_keys_[kSPACE];
            setfillstyle(1,0);
            bar(maxx/2-textwidth(pausa)/2,maxy/2-contador+1,maxx/2+textwidth(pausa)/2,maxy/2+textheight(pausa));
         }

         if(nave!=NULL){
            static int ePress=0,uPress=0,dPress=0;
            if(_pressed_keys_[kLARROW]) dir=1;
            if(_pressed_keys_[kRARROW]) dir=-1;
            if(_pressed_keys_[kUARROW]){
              if(!uPress){
                 uPress=1;
                 if(misseis){
                    misseis--;
                    ext_dono=1;
                    nave->dispara(nave->x+15,nave->y-37,6,dir*15);
                    ext_dono=0;
                 }
              }
            }else{
               uPress=0;
            }
            if(misseis&&_pressed_keys_[kDARROW]){
              if(!dPress){
                 dPress=1;
                 ext_dono=1;
                 if(misseis)misseis--,nave->dispara(nave->x+15,nave->y-45,6);
                 if(misseis)misseis--,nave->dispara(nave->x+35,nave->y-40,6);
                 if(misseis)misseis--,nave->dispara(nave->x- 5,nave->y-40,6);
                 if(misseis)misseis--,nave->dispara(nave->x+55,nave->y-35,6);
                 if(misseis)misseis--,nave->dispara(nave->x-25,nave->y-35,6);

                 ext_dono=0;
              }
            }else{
               dPress=0;
            }
            if(ePress) ePress--;
            int tecla;
            tecla=_pressed_keys_[kSPACE] ?1:
                  _pressed_keys_[kCOMMA] ?2:
                  _pressed_keys_[kPERIOD]?3:
                  _pressed_keys_[kSLASH] ?4:0;
            if(tecla){
              if(!ePress){
                 static pos=0,antdir=0,sep=0;
                 int posatual=pos;
                 ePress=repeater+1;
                 if(tecla==1){
                    posatual=sep?-dir*pos:-dir*4;
                 }else if(tecla==2){
                    posatual=-4;
                 }else if(tecla==3){
                    posatual=0;
                 }else{
                    posatual=4;
                 }
                 dispara(posatual);
                 sep=!sep;
                 if(dir==0){
                    pos=0;
                    antdir=0;
                 }else{
                    if(dir!=antdir){
                       antdir=dir;
                       pos=3;
                    }else if(pos<7){
                       pos++;
                    }
                 }
              }
            }else{
               ePress=0;
            }
          }
         if(dir){
            if(dir>0){
               dir--;
               if(nave->x>10) nave->move(-10,0);
            }else{
               dir++;
               if(nave->x<maxx-30) nave->move(10,0);
            }
         }
         if(lastforca!=nave->forca){
            lastforca=nave->forca;
            setfillstyle(1,0);
            bar(0,maxy-3,maxx,maxy-2);
         }
         if(lastmisseis!=misseis){
            lastmisseis=misseis;
            setfillstyle(1,0);
            bar(0,maxy,maxx,maxy);
         }
         if(nave!=NULL){
            setfillstyle(1,15);
            for(int i=0;i<nave->forca;i++){
               bar(i*3,maxy-3,i*3+1,maxy-2);
            }
            for(i=0;i<misseis;i++){
               bar(i*5,maxy,i*5+3,maxy);
            }
         }
         contador++;
         if(fase<9) novos_inimigos();
         else novos_inimigos2();

         TIRO::animacoes();

         NAVE::animacoes();

         TIRO::animacoes();
         EXPLOSAO::animacoes();
         RASPAO::animacoes();
         if(nave==NULL){
            static tofim=0;
            outtextxy(maxx/2-textwidth(fim_frase)/2,maxy/2,fim_frase);
            if(tofim++>200){
               tofim=0;
               saida=1;
            }
         }

         while(((clock()-clocki)/CLK_TCK)<.009);

      }while(!saida&&NAVE::primeira!=NULL);
      setfillstyle(1,0);
      bar(maxx/2-textwidth(fim_frase)/2,maxy/2
         ,maxx/2+textwidth(fim_frase)/2,maxy/2+textheight(fim_frase));
      while(NAVE::primeira!=NULL){
         assert(new EXPLOSAO(NAVE::primeira->x,NAVE::primeira->y)!=NULL);
         NAVE::primeira->morre();
      }

      while(_pressed_keys_[kESC]);

   }
   restorecrtmode();

   set_old_int9();

}

#define m(x) (goodisp>=x?5:0)
void dispara(char dir){
   static char cont=0;//,proxmissil=0;
   ext_dono=1;
//   if(proxmissil++>5){
//      proxmissil=0;
//      nave->dispara(nave->x+15,nave->y-37,6);
//   }
   if(!potencia){                                 //      .
      nave->dispara(nave->x+13,nave->y-34,m(1),dir);

   }else if(potencia==1){                         //     .
      if(++cont>1) cont=0;                        //       .
      if(cont==0){
         nave->dispara(nave->x+25,nave->y-34,m(2),dir);
      }else{
         nave->dispara(nave->x+ 5,nave->y-33,m(3),dir);
      }

   }else if(potencia==2){                         //     . .
      nave->dispara(nave->x+25,nave->y-34,m(4),dir);
      nave->dispara(nave->x+ 5,nave->y-33,m(5),dir);

   }else if(potencia==3){                         //      .
      nave->dispara(nave->x+15,nave->y-34,m(1),dir);  //     .
      if(++cont>1) cont=0;                        //       .
      if(cont==0){
         nave->dispara(nave->x+25,nave->y-33,m(2),dir);
      }else{
         nave->dispara(nave->x+ 5,nave->y-33,m(3),dir);
      }

   }else if(potencia==4){                         //      .
      if(++cont>1) cont=0;                        //     . .
      if(cont==0){
         nave->dispara(nave->x+15,nave->y-34,m(1),dir);
      }else{
         nave->dispara(nave->x+25,nave->y-33,m(2),dir);
         nave->dispara(nave->x+5,nave->y-33,m(3),dir);
      }

   }else if(potencia==5){                         //     ..
      if(++cont>1) cont=0;                        //      ..
      nave->dispara(nave->x+15,nave->y-34,m(1),dir);
      if(cont==0){
         nave->dispara(nave->x+10,nave->y-33,m(2),dir);
      }else{
         nave->dispara(nave->x+20,nave->y-33,m(3),dir);
      }

   }else if(potencia==6){                         //     . .
      if(++cont>1) cont=0;                        //     ...
      if(cont==0){
         nave->dispara(nave->x+15,nave->y-34,m(1),dir);
      }
      nave->dispara(nave->x+10,nave->y-33,m(2),dir);
      nave->dispara(nave->x+20,nave->y-33,m(3),dir);

   }else if(potencia==7){                         //     ...
      nave->dispara(nave->x+15,nave->y-34,m(1),dir);
      nave->dispara(nave->x+10,nave->y-33,m(2),dir);
      nave->dispara(nave->x+20,nave->y-33,m(3),dir);

   }else if(potencia==8){                        //       .
      if(++cont>2) cont=0;                       //      . .
      if(cont==0){                               //     .   .
         nave->dispara(nave->x+15,nave->y-34,m(1),dir);
      }else if(cont==1){
         nave->dispara(nave->x+10,nave->y-33,m(2),dir);
         nave->dispara(nave->x+20,nave->y-33,m(3),dir);
      }else{
         nave->dispara(nave->x+ 5,nave->y-32,m(4),dir);
         nave->dispara(nave->x+25,nave->y-32,m(5),dir);
      }

   }else if(potencia==9){                        //      ...
      if(++cont>1) cont=0;                       //     .   .
      if(cont==0){
         nave->dispara(nave->x+15,nave->y-34,m(1),dir);
         nave->dispara(nave->x+10,nave->y-33,m(2),dir);
         nave->dispara(nave->x+20,nave->y-33,m(3),dir);
      }else{
         nave->dispara(nave->x+ 5,nave->y-32,m(4),dir);
         nave->dispara(nave->x+25,nave->y-32,m(5),dir);
      }

   }else if(potencia==10){                       //      . .
      if(++cont>2) cont=0;                       //    . .
      if(cont==0){                               //        . .
         nave->dispara(nave->x+10,nave->y-33,m(2),dir);
         nave->dispara(nave->x+20,nave->y-33,m(3),dir);
      }else if(cont==1){
         nave->dispara(nave->x   ,nave->y-31,m(6),dir);
         nave->dispara(nave->x+10,nave->y-33,m(2),dir);
      }else{
         nave->dispara(nave->x+20,nave->y-34,m(1),dir);
         nave->dispara(nave->x+30,nave->y-31,m(7),dir);
      }

   }else if(potencia==11){                       //     .   .
      if(++cont>2) cont=0;                       //    .  .
      if(cont==0){                               //       .  .
         nave->dispara(nave->x+ 5,nave->y-32,m(4),dir);
         nave->dispara(nave->x+25,nave->y-32,m(5),dir);
      }else if(cont==1){
         nave->dispara(nave->x   ,nave->y-31,m(6),dir);
         nave->dispara(nave->x+15,nave->y-34,m(1),dir);
      }else{
         nave->dispara(nave->x+15,nave->y-34,m(1),dir);
         nave->dispara(nave->x+30,nave->y-31,m(7),dir);
      }

   }else if(potencia==12){                       //      . .
      if(++cont>2) cont=0;                       //     . . .
      if(cont==0){                               //    .     .
         nave->dispara(nave->x+10,nave->y-33,m(2),dir);
         nave->dispara(nave->x+20,nave->y-33,m(3),dir);
      }else if(cont==1){
         nave->dispara(nave->x+ 5,nave->y-32,m(4),dir);
         nave->dispara(nave->x+15,nave->y-34,m(1),dir);
         nave->dispara(nave->x+25,nave->y-32,m(5),dir);
      }else{
         nave->dispara(nave->x   ,nave->y-31,m(6),dir);
         nave->dispara(nave->x+30,nave->y-31,m(7),dir);
      }

   }else if(potencia==13){                       //     .. .
      if(++cont>1) cont=0;                       //      . ..
      nave->dispara(nave->x+10,nave->y-33,m(2),dir);
      nave->dispara(nave->x+20,nave->y-33,m(3),dir);
      if(cont==0){
         nave->dispara(nave->x+ 5,nave->y-32,m(4),dir);
      }else{
         nave->dispara(nave->x+25,nave->y-32,m(5),dir);
      }

   }else if(potencia==14){                       //    .  ..
      if(++cont>1) cont=0;                       //      ..  .
      nave->dispara(nave->x+15,nave->y-34,m(1),dir);
      if(cont==0){
         nave->dispara(nave->x   ,nave->y-31,m(6),dir);
         nave->dispara(nave->x+20,nave->y-33,m(3),dir);
      }else{
         nave->dispara(nave->x+10,nave->y-33,m(2),dir);
         nave->dispara(nave->x+30,nave->y-31,m(7),dir);
      }

   }else if(potencia==15){                       //    ...
      if(++cont>1) cont=0;                       //        ...
      if(cont==0){
         nave->dispara(nave->x   ,nave->y-31,m(6),dir);
         nave->dispara(nave->x+ 5,nave->y-32,m(4),dir);
         nave->dispara(nave->x+10,nave->y-33,m(2),dir);
      }else{
         nave->dispara(nave->x+20,nave->y-33,m(3),dir);
         nave->dispara(nave->x+25,nave->y-32,m(5),dir);
         nave->dispara(nave->x+30,nave->y-31,m(7),dir);
      }

   }else if(potencia==16){                       //    .  .  .
      if(++cont>1) cont=0;                       //     . . .
      nave->dispara(nave->x+15,nave->y-34,m(1),dir);
      if(cont==0){
         nave->dispara(nave->x   ,nave->y-31,m(6),dir);
         nave->dispara(nave->x+30,nave->y-31,m(7),dir);
      }else{
         nave->dispara(nave->x+ 5,nave->y-32,m(4),dir);
         nave->dispara(nave->x+25,nave->y-32,m(5),dir);
      }

   }else if(potencia==17){                       //    .  .  .
      if(++cont>1) cont=0;                       //     .. ..
      if(cont==0){
         nave->dispara(nave->x   ,nave->y-31,m(6),dir);
         nave->dispara(nave->x+15,nave->y-34,m(1),dir);
         nave->dispara(nave->x+30,nave->y-31,m(7),dir);
      }else{
         nave->dispara(nave->x+ 5,nave->y-32,m(4),dir);
         nave->dispara(nave->x+10,nave->y-33,m(2),dir);
         nave->dispara(nave->x+20,nave->y-33,m(3),dir);
         nave->dispara(nave->x+25,nave->y-32,m(5),dir);
      }

   }else if(potencia==18){                       //     . . .
      if(++cont>1) cont=0;                       //    . . . .
      if(cont==0){
         nave->dispara(nave->x+ 5,nave->y-32,m(4),dir);
         nave->dispara(nave->x+15,nave->y-34,m(1),dir);
         nave->dispara(nave->x+25,nave->y-32,m(5),dir);
      }else{
         nave->dispara(nave->x   ,nave->y-31,m(6),dir);
         nave->dispara(nave->x+10,nave->y-33,m(2),dir);
         nave->dispara(nave->x+20,nave->y-33,m(3),dir);
         nave->dispara(nave->x+30,nave->y-31,m(7),dir);
      }

   }else if(potencia==19){                       //     .. ..
      nave->dispara(nave->x+ 5,nave->y-32,m(4),dir);
      nave->dispara(nave->x+10,nave->y-33,m(2),dir);
      nave->dispara(nave->x+20,nave->y-33,m(3),dir);
      nave->dispara(nave->x+25,nave->y-32,m(5),dir);

   }else if(potencia==20){                       //       ....
      if(++cont>1) cont=0;                       //    ....
      nave->dispara(nave->x+15,nave->y-34,m(1),dir);
      if(cont==0){
         nave->dispara(nave->x+20,nave->y-33,m(3),dir);
         nave->dispara(nave->x+25,nave->y-32,m(5),dir);
         nave->dispara(nave->x+30,nave->y-31,m(7),dir);
      }else{
         nave->dispara(nave->x   ,nave->y-31,m(6),dir);
         nave->dispara(nave->x+ 5,nave->y-32,m(4),dir);
         nave->dispara(nave->x+10,nave->y-33,m(2),dir);
      }

   }else if(potencia==21){                       //      . ...
      if(++cont>1) cont=0;                       //    ... .
      nave->dispara(nave->x+10,nave->y-33,m(2),dir);
      nave->dispara(nave->x+20,nave->y-33,m(3),dir);
      if(cont==0){
         nave->dispara(nave->x+25,nave->y-32,m(5),dir);
         nave->dispara(nave->x+30,nave->y-31,m(7),dir);
      }else{
         nave->dispara(nave->x   ,nave->y-31,m(6),dir);
         nave->dispara(nave->x+ 5,nave->y-32,m(4),dir);
      }

   }else if(potencia==22){                       //     . . ..
      if(++cont>1) cont=0;                       //    .. . .
      nave->dispara(nave->x+ 5,nave->y-32,m(4),dir);
      nave->dispara(nave->x+15,nave->y-34,m(1),dir);
      nave->dispara(nave->x+25,nave->y-32,m(5),dir);
      if(cont==0){
         nave->dispara(nave->x+30,nave->y-31,m(7),dir);
      }else{
         nave->dispara(nave->x   ,nave->y-31,m(6),dir);
      }

   }else if(potencia==23){                       //    . . . .
      nave->dispara(nave->x   ,nave->y-31,m(6),dir);
      nave->dispara(nave->x+10,nave->y-33,m(2),dir);
      nave->dispara(nave->x+20,nave->y-33,m(3),dir);
      nave->dispara(nave->x+30,nave->y-31,m(7),dir);

   }else if(potencia==24){                       //    . . . .
      if(++cont>1) cont=0;                       //    . ... .
      nave->dispara(nave->x   ,nave->y-31,m(6),dir);
      nave->dispara(nave->x+10,nave->y-33,m(2),dir);
      nave->dispara(nave->x+20,nave->y-33,m(3),dir);
      nave->dispara(nave->x+30,nave->y-31,m(7),dir);
      if(cont==0){
         nave->dispara(nave->x+15,nave->y-34,m(1),dir);
      }

   }else if(potencia==25){                       //     .. ..
      if(++cont>1) cont=0;                       //    .. . ..
      nave->dispara(nave->x+ 5,nave->y-32,m(4),dir);
      nave->dispara(nave->x+25,nave->y-32,m(5),dir);
      if(cont==0){
         nave->dispara(nave->x+10,nave->y-33,m(2),dir);
         nave->dispara(nave->x+20,nave->y-33,m(3),dir);
      }else{
         nave->dispara(nave->x   ,nave->y-31,m(6),dir);
         nave->dispara(nave->x+15,nave->y-34,m(1),dir);
         nave->dispara(nave->x+30,nave->y-31,m(7),dir);
      }

   }else if(potencia==26){                       //     .....
      nave->dispara(nave->x+ 5,nave->y-32,m(4),dir);
      nave->dispara(nave->x+10,nave->y-33,m(2),dir);
      nave->dispara(nave->x+15,nave->y-34,m(1),dir);
      nave->dispara(nave->x+20,nave->y-33,m(3),dir);
      nave->dispara(nave->x+25,nave->y-32,m(5),dir);

   }else if(potencia==27){                       //    . ... .
      nave->dispara(nave->x   ,nave->y-31,m(6),dir);
      nave->dispara(nave->x+10,nave->y-33,m(2),dir);
      nave->dispara(nave->x+15,nave->y-34,m(1),dir);
      nave->dispara(nave->x+20,nave->y-33,m(3),dir);
      nave->dispara(nave->x+30,nave->y-31,m(7),dir);

   }else if(potencia==28){                       //    .. . ..
      nave->dispara(nave->x   ,nave->y-31,m(6),dir);
      nave->dispara(nave->x+ 5,nave->y-32,m(4),dir);
      nave->dispara(nave->x+15,nave->y-34,m(1),dir);
      nave->dispara(nave->x+25,nave->y-32,m(5),dir);
      nave->dispara(nave->x+30,nave->y-31,m(7),dir);

   }else if(potencia==29){                       //    ... ...
      nave->dispara(nave->x   ,nave->y-31,m(6),dir);
      nave->dispara(nave->x+ 5,nave->y-32,m(4),dir);
      nave->dispara(nave->x+10,nave->y-33,m(2),dir);
      nave->dispara(nave->x+20,nave->y-33,m(3),dir);
      nave->dispara(nave->x+25,nave->y-32,m(5),dir);
      nave->dispara(nave->x+30,nave->y-31,m(7),dir);

   }else{                                      //    .......
      nave->dispara(nave->x   ,nave->y-31,m(6),dir);
      nave->dispara(nave->x+ 5,nave->y-32,m(4),dir);
      nave->dispara(nave->x+10,nave->y-33,m(2),dir);
      nave->dispara(nave->x+15,nave->y-34,m(1),dir);
      nave->dispara(nave->x+20,nave->y-33,m(3),dir);
      nave->dispara(nave->x+25,nave->y-32,m(5),dir);
      nave->dispara(nave->x+30,nave->y-31,m(7),dir);

   }
   ext_dono=0;
}
