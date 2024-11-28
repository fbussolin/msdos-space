#include "fases.h"

extern NAVE *nave;
extern int fase,maxx,maxy;
extern int contador;

#define e else

void novos_inimigos(void){
   char aux;

   if(nave!=NULL){

      switch (fase){
         case 0:
            f1( 10)n01;e f2( 50)n01;e
            f3(100)n01;e f4(150)n01;e f1(175)n16;e
            f3(200)n01;e f3(250)n01;e
            f3(300)n01;e f3(350)n01;e
            f1(360)n09;e f1(370)n10;e f1(390)n11;
            break;

         case 1:
            f3( 10)n01;e f1( 20)n02;e f2( 50)n01;e f2( 70)n02;e
            f1(100)n01;e f3(120)n02;e f1(175)n18;e f4(170)n02;e
            f5(200)n02;e f4(150)n02;e
            f4(300)n02;e f4(350)n02;
            break;

         case 2:
            f1( 10)n03;e f3( 50)n01;e f5( 90)n02;e
            f1(100)n03;e f1(150)n16;e f5(190)n01;e
            f1(200)n03;e f1(250)n18;e f5(290)n02;e
            f1(300)n15;
            break;

         case 3:
            f1( 10)n04;e f2( 50)n04;e
            f3(100)n04;e f4(150)n04;e f1(175)n17;e
            f5(200)n04;e f3(250)n02;e
            f1(300)n03;e f5(350)n02;e f1(375)n08;
            break;

         case 4:
            f3( 10)n01;e f5( 50)n02;e f1( 90)n05;e
            f2(110)n05;e f3(150)n05;e f1(175)n18;e
            f4(200)n05;e f1(250)n03;e f1(275)n16;e
            f1(300)n10;
            break;

         case 5:
            f1( 10)n07;e f5( 50)n02;e
            f1(100)n07;e f5(150)n02;e f1(175)n19;e
            f1(200)n07;e f5(250)n02;e f1(275)n16;e
            f1(300)n08;e f1(310)n10;
            break;

         case 6:
            f1( 10)n12;e f5( 50)n01;e
            f3(100)n04;e f1(150)n20;e f1(175)n16;e
            f5(200)n04;e f5(250)n01;e
            f1(300)n15;
            break;

         case 7:
            f1( 10)n13;e f1( 50)n12;e f1( 80)n12;e
            f3(100)n13;e f1(150)n17;e f1(160)n20;e
            f3(200)n13;e f1(250)n19;e f1(190)n07;e
            f1(300)n10;
            break;

         case 8:
            f1( 10)n07;e f1( 50)n07;e
            f1(100)n07;e f1(150)n26;e
            f3(200)n04;e f3(250)n05;e
            f1(300)n08;
            break;

     }

     upfase(500);
   }
}

