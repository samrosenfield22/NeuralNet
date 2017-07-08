/**/

#ifndef WEIGHTS_H
#define WEIGHTS_H

#include <stdlib.h>
#include <stdint.h>

#include "netparams.h"



typedef struct _weightset weightset;
typedef struct _cellweights cellweights;

struct _weightset
{
	cellweights **layer[LAYERS];	//note that "struct _cellweights" is totally unnecessary! 
	//the wtbl could be a *float
	//so this whole thing could be a ***[] (or maybe just a **[])

	//wtbl **layer[LAYERS];
	
	//func ptrs
	void (*init)(weightset *);
	//void (*initTbl)(cellweights *);
};

struct _cellweights
{
	float **wtbl;
};


//netweight member func prototypes
void initializeWeightSet(weightset *);
//void initializeWeightTable(cellweights *);
//void populateRandomWeightTable(weightset *);

//other func prototypes
float getRand(void);





#endif	//WEIGHTS_H