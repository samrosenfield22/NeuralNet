/**/

#ifndef ORGANISM_H
#define ORGANISM_H

#include "../Neural/net.h"


typedef struct _organism organism;
//typedef struct _population population;

struct _organism
{
	//set of weights for each connection in a neural net (genetic material of the organism)
	weightset set;
	
	//organism's given fitness score
	uint16_t fitness;
	
	//function ptrs
	void (*getFitness)(organism *);
	void (*mutate)(organism *);
};

//func prototypes
void getFitness(organism *);
void mutate(organism *);


#endif	//ORGANISM_H