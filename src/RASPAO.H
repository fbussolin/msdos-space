#ifndef __RASPAO_H
#define __RASPAO_H

#include <stdlib.h>

#define MAXraspao 10
class RASPAO {
public:
   int x[MAXraspao],y[MAXraspao];
   int velx[MAXraspao],vely[MAXraspao];
   char contador,abrangencia;

   static RASPAO *primeiro;
   static RASPAO *ultimo;
   RASPAO *anterior;
   RASPAO *proximo;

   RASPAO(int px,int py);
   virtual ~RASPAO(void);

   static void animacoes(void);

   void apaga(void);
   void desenha(void);

   virtual void anima(void);

};

#endif
