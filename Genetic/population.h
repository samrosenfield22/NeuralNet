/**/

#ifndef POPULATION_H
#define POPULATION_H

#include "../Neural/net.h"

#include "organism.h"
#include "geneparams.h"


typedef organism population[POPULATION_SIZE];

//func prototypes
void updateFitness(organism *, neuralnet *, uint8_t);
organism *rouletteSelect(population, uint32_t);
void procreate(organism *, organism *, organism *, organism *);


#endif	//POPULATION_H