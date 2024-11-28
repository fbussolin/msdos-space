#ifndef __NAVE_H
#define __NAVE_H

struct TipoN{
       int  tx,ty;
       int  ptos;
       int  forca;
       char coor[114];};

extern TipoN tipos[31];

struct GRUPO { char add;
               int x,y;
               char dirx,diry;
               char velx,vely;
             };

class NAVE {
public:
   static GRUPO formacao;

   int x,y;
   int tamx,tamy;
   char fig,lastfig,
        cor;
   int forca;
   static NAVE *primeira;
   static NAVE *ultima;
   NAVE *proximo,*anterior;

   NAVE(void);
   virtual ~NAVE(void);

   static void animacoes(void);

   void define(int px,int py,char pfig);
   void desenha(int=15);
   void apaga(void){desenha(0);}
   void dispara(int px,int py,char ptipo,char=0);
   void move(int px,int py);
   void morre(void);

   virtual void anima(void);
   virtual void bateu(void);
};

#endif
