#ifndef __FASES_H
#define __FASES_H

#include <stdlib.h>
#include <assert.h>

void novos_inimigos(void);

#include "nave.h"
#include "n01.h"
#include "n02.h"
#include "n03.h"
#include "n04.h"
#include "n05.h"
#include "n07.h"
#include "n08.h"
#include "n09.h"
#include "n10.h"
#include "n11.h"
#include "n12.h"
#include "n13.h"
#include "n14.h"
#include "n15.h"
#include "n16.h"
#include "n17.h"
#include "n18.h"
#include "n19.h"
#include "n20.h"
#include "n21.h"
#include "n22.h"
#include "n23.h"
#include "n24.h"
#include "nmae.h"
#include "nmae2.h"

#define f1(n) if(contador==n)
#define f2(n) if(contador==n)for(aux=0;aux<2;aux++)
#define f3(n) if(contador==n)for(aux=0;aux<3;aux++)
#define f4(n) if(contador==n)for(aux=0;aux<4;aux++)
#define f5(n) if(contador==n)for(aux=0;aux<5;aux++)
#define upfase(n) if(contador==(n)) contador=0,fase++

#define n01 assert(new N01!=NULL)
#define n02 assert(new N02!=NULL)
#define n03 assert(new N03!=NULL)
#define n04 assert(new N04!=NULL)
#define n05 assert(new N05!=NULL)
#define n07 assert(new N07!=NULL)
#define n08 assert(new N08(random(maxx-30),-1)!=NULL)
#define n09 assert(new N09(random(maxx-30),-1)!=NULL)
#define n10 assert(new N10(random(maxx-30),-1)!=NULL)
#define n11 assert(new N11(random(maxx-30),-1)!=NULL)
#define n12 assert(new N12!=NULL)
#define n13 assert(new N13!=NULL)
#define n14 assert(new N14!=NULL)
#define n15 assert(new N15(random(maxx-30),-1)!=NULL)
#define n16 assert(new N16!=NULL)
#define n17 assert(new N17!=NULL)
#define n18 assert(new N18!=NULL)
#define n19 assert(new N19!=NULL)
#define n20 assert(new N20!=NULL)
#define n21 assert(new N21!=NULL)
#define n22 assert(new N22!=NULL)
#define n23 assert(new N23!=NULL)
#define n24 assert(new N24!=NULL)
#define n26 assert(new NMAE(26)!=NULL)
#define n27 assert(new NMAE(27)!=NULL)
#define n28 assert(new NMAE(28)!=NULL)
#define n29 assert(new NMAE2(29)!=NULL)
#define n30 assert(new NMAE2(30)!=NULL)

#endif