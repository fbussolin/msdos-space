#include <graphics.h>
#include <string.h>
#include "akey.h"
#include "fases1.h"
#include "fases.h"

extern int contador,fase,maxx,maxy,saida;
extern NAVE* nave;

#define e else
void novos_inimigos2(void){
   char aux;
   if(nave!=NULL){
      switch(fase){

         case 9:
            f5( 10)n02;e f1( 50)n03;e f3( 90)n04;e f1( 95)n16;e
            f5(100)n02;e f1(150)n21;e f1(160)n21;e f1(175)n03;e
            f5(200)n02;e f1(250)n16;e f1(275)n19;e
            f1(310)n15;
            break;

         case 10:
            f3( 10)n05;e f1( 50)n16;e f3( 75)n04;e
            f3(100)n05;e f1(150)n21;e f1(160)n21;e f1(170)n21;e f1(180)n21;e
            f1(200)n12;e f1(250)n12;e f1(260)n16;e
            f1(300)n30;e f1(310)n08;e f1(330)n09;e f2(340)n10;
            break;

         case 11:
            f1( 10)n07;e f1( 20)n07;e f1( 30)n07;e f3( 50)n04;e
            f1(100)n16;e f1(150)n22;e f1(175)n17;e
            f1(200)n03;e f1(210)n12;e f1(215)n12;e f1(220)n12;e f1(250)n19;e
            f1(300)n03;
            break;

         case 12:
            f3( 10)n13;e f1( 50)n16;e f1( 60)n07;e f1( 75)n21;e
            f1(100)n04;e f2(125)n04;e f1(175)n20;e
            f1(200)n17;e f1(210)n12;e f1(215)n12;e
            f1(300)n16;e f1(320)n15;
            break;

         case 13:
            f1( 10)n07;e f1( 20)n13;e f3( 30)n04;e f1( 50)n16;e f5( 75)n01;e
            f1(100)n02;e f2(150)n02;e f1(175)n23;e f1(190)n13;e
            f3(200)n02;e f4(250)n02;e f1(260)n21;e f1(270)n21;e
            f5(300)n02;e f1(310)n15;e f1(320)n08;
            break;

         case 14:
            f1( 10)n29;e f5( 20)n01;e f5( 30)n01;e f5( 40)n01;e
            f1(100)n16;e f1(110)n07;e f1(120)n07;e f1(130)n07;e
            f2(200)n05;e f2(250)n04;e f1(275)n22;e f1(280)n21;e
            f1(300)n17;
            break;

         case 15:
            f1( 10)n03;e f3( 50)n04;e f1( 75)n16;e f1( 90)n19;e
            f1(100)n07;e f5(125)n04;e f1(150)n22;e f1(155)n21;e f1(160)n21;e
            f1(200)n21;e f1(210)n21;e f1(220)n16;e f1(230)n12;e f1(250)n20;e
            f1(310)n15;e f2(320)n10;
            break;

         case 16:
            f1( 10)n16;e f3( 50)n04;e f1( 75)n16;e
            f1(100)n12;e f1(150)n27;e f3(175)n02;e
            f3(200)n02;e f3(225)n02;e f3(205)n02;e
            f1(300)n08;
            break;

         case 17:
            f1( 10)n16;e f4( 50)n04;e f4( 90)n04;e
            f1(100)n24;e f1(110)n21;e f1(115)n21;e f1(120)n21;e f1(125)n21;e
            f1(200)n16;e f1(210)n12;e f1(215)n12;e f1(220)n12;e f1(225)n12;e
            f1(310)n15;
            break;

         case 18:
            f1( 10)n13;e f1( 40)n13;e f1( 50)n03;e f3( 75)n04;e
            f1(100)n07;e f1(150)n29;e f1(190)n30;e
            f1(200)n22;e f3(250)n14;e f1(275)n16;
            break;

         case 19:
            f1( 10)n03;e f5( 50)n04;e f1( 75)n16;e
            f5(100)n21;e f2(150)n22;e
            f5(200)n04;e f3(250)n05;e
            f1(300)n08;e f1(310)n15;
            break;

         case 20:
            f1( 10)n20;e f1( 50)n19;e f3( 75)n12;e
            f1(100)n23;e f1(150)n24;e f1(175)n16;e
            f1(200)n21;e f3(250)n12;e f1(260)n01;e
            f1(320)n10;
            f1(330)n01;
            break;

         case 21:
            f1( 10)n03;e f1( 50)n16;e f5( 60)n01;e
            f1(100)n17;e f5(125)n13;e f1(150)n20;e
            f1(200)n19;e f1(210)n03;e f5(250)n04;e
            f5(275)n02;e f1(300)n08;e f1(350)n15;
            break;

         case 22:
            f5( 10)n05;e f5( 25)n02;e f1( 50)n07;e
            f5(100)n21;e f5(125)n04;e f5(150)n18;e f1(175)n16;e
            f5(200)n04;e f5(225)n04;e f5(250)n14;e
            f5(325)n04;
            break;

         case 23:
            f5( 10)n01;e f5( 25)n01;e f5( 50)n01;e f5( 75)n01;e
            f5(100)n01;e f5(125)n01;e f5(150)n01;e f1(175)n16;e
            f1(180)n23;e f5(200)n01;e f5(225)n02;e f5(250)n02;e f5(275)n02;e
            f1(300)n08;e f1(310)n15;e f1(320)n23;e f3(330)n11;e f1(330)n09;
           break;

         case 24:
            f1( 10)n21;e f1( 50)n21;e f1( 75)n21;e
            f1(100)n21;e f1(125)n23;e f1(150)n28;e f1(175)n24;e
            f1(200)n04;e f1(225)n05;e f1(250)n04;e f1(275)n05;e
            f1(300)n04;e f1(325)n05;e f1(350)n04;
           break;

         case 25:
            f5( 10)n01;e
            f5( 25)n02;e
            f2( 50)n03;e
            f5( 75)n04;e
            f5(100)n05;e
            f1(125)n07;e f1(150)n07;e f1(175)n07;e
            f1(200)n12;e f1(205)n12;e f1(210)n12;e f1(215)n12;e f1(220)n12;e
            f5(225)n13;e
            f5(250)n14;e
            f1(275)n16;e
            f1(300)n17;e
            f1(325)n18;e
            f1(350)n19;e
            f1(275)n20;e
            f5(300)n21;e
            f1(375)n22;e
            f1(400)n23;e
            f1(425)n24;e
            f1(450)n26;e
            f1(475)n27;e
            f1(500)n28;e
            f1(525)n29;e
            f1(550)n23;e
            f1(575)n24;e
            f1(600)n23;e
            f1(625)n24;e
            f5(650)n21;

            if(NAVE::primeira->proximo==NULL) contador=0, fase++;
            else contador=1;
            break;

         case 26:
            {
               char frase[]="  Caramba!!! Como e' que voce conseguiu?  ";
               maxy-=200;
               setfillstyle(1,0);
               outtextxy(maxx/2-textwidth(frase)/2,maxy/2,frase);
               strcpy(frase,"Meus parabens!");
               outtextxy(maxx/2-textwidth(frase)/2,maxy/2+30,frase);
               strcpy(frase,"Agora, para provar que voce e bom mesmo,");
               outtextxy(maxx/2-textwidth(frase)/2,maxy/2+40,frase);
               strcpy(frase,"faz tudo de novo, sem atirar...");
               outtextxy(maxx/2-textwidth(frase)/2,maxy/2+50,frase);
               strcpy(frase,"Pressione ENTER");
               outtextxy(maxx/2-textwidth(frase)/2,maxy/2+70,frase);
               while(!_pressed_keys_[kENTER]);
               saida=1;
               maxy+=200;
            }
            break;
      }
      upfase(550);
   }
}
