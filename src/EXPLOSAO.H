#ifndef __EXPLOSAO_H
#define __EXPLOSAO_H

#include <stdlib.h>

#define MAXexplosao 10
class EXPLOSAO {
public:
   int x1[MAXexplosao],y1[MAXexplosao],
       x2[MAXexplosao],y2[MAXexplosao];
   char velx[MAXexplosao],vely[MAXexplosao];
   char contador;

   static EXPLOSAO *primeiro;
   static EXPLOSAO *ultimo;
   EXPLOSAO *anterior;
   EXPLOSAO *proximo;

   EXPLOSAO(int px,int py);
   virtual ~EXPLOSAO(void);

   static void animacoes(void);

   void apaga(void){desenha(0);}
   void desenha(int=15);

   virtual void anima(void);

};

#endif
