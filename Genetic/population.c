/**/

#include "population.h"

void updateFitness(organism *org, neuralnet *net, uint8_t expectedval)
{
	neuron **nptr;
	int16_t score;
	uint8_t correctValPicked=0, falsePositives=0;
	uint8_t i;
	
	//see which outputs the ANN picked, if they're right/wrong
	nptr = net->layer[LAYERS-1];
	for(i=0; i<CELLS_PER_LAYER[LAYERS-1]; ++i)
	{
		if ((*nptr)->activated == 1)
		{
			if (i == expectedval) correctValPicked = 1;
			else falsePositives++;
		}
		
		nptr++;
	}
	
	//score the ANN
	if ((correctValPicked==1) && (falsePositives==0)) score = 100;
	else score = (80*correctValPicked) - (40*falsePositives);
	if (score<0) score=0;
	
	//store the score in the organism struct
	org->fitness += score;
}

organism *rouletteSelect(population pop, uint32_t total_fitness)
{
	uint32_t i, fitsum=0, stoppt;
	
	stoppt = rand() % total_fitness;	//point at which the algorithm will stop, and the organism will be selected
	//printf("\tthe stop point is %d\n", stoppt);
	
	for (i=0; i<POPULATION_SIZE; ++i)
	{
		fitsum += pop[i].fitness;
		if (fitsum >= stoppt)
		{
			return &pop[i];
		}
	}
}

void procreate(organism *mother, organism *father, organism *child0, organism *child1)
{
	/*
		access an individual weight like this:
		lptr = *(mother->set.layer[i]);		//layer
		weight = **(lptr->wtbl)
	*/

	uint8_t i, j;
	bool swap = true;
	cellweights *momlptr, *dadlptr, *c0lptr, *c1lptr;	//pointers to each org's layer weight struct
	float **momwptr, **dadwptr, **c0wptr, **c1wptr;		//pointers to each org's weights

	//for now, we'll swap by layer
	for(i=0; i<LAYERS; ++i)
	{
		momlptr = *(mother->set.layer[i]);
		dadlptr = *(father->set.layer[i]);
		c0lptr = *(child0->set.layer[i]);
		c1lptr = *(child1->set.layer[i]);

		momwptr = momlptr->wtbl;
		dadwptr = dadlptr->wtbl;
		c0wptr = c0lptr->wtbl;
		c1wptr = c1lptr->wtbl;

		//copy parent's weights from the current layer
		for(j=0; j<CELLS_PER_LAYER[i]; ++j)
		{
			//do the nasty
			if (swap)
			{
				**c0wptr = **momwptr;
				**c1wptr = **dadwptr;
			}
			else
			{
				**c0wptr = **dadwptr;
				**c1wptr = **momwptr;
			}

			swap != swap;
			momwptr++;
			dadwptr++;
			c0wptr++;
			c1wptr++;
		}
	}

}







