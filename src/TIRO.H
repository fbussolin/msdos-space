#ifndef __TIRO_H
#define __TIRO_H

extern int pontos,ext_dono;

class TIRO {
public:
   int x,y;
   char tamx,tamy,forca;
   char morreu,dono,dir;

   static TIRO *primeiro;
   static TIRO *ultimo;
   TIRO *anterior;
   TIRO *proximo;

   TIRO(int px,int py,char ptamx,char ptamy,char pforce,char=0);
   virtual ~TIRO(void);

   static void animacoes(void);

   void move(int px,int py);
   char verifica(void);

   virtual void apaga(void);
   virtual void desenha(void);
   virtual void anima(void);

};

#endif
