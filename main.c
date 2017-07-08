/**/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "Neural/neuron.h"
#include "Neural/net.h"
#include "Neural/weights.h"

#include "Genetic/population.h"
#include "Genetic/geneparams.h"

#include "Images/imgdef.h"

int main(void)
{
	
	neuralnet ann;
	time_t t;
	population pop, newpop;
	organism *mother, *father;
	uint8_t i, j;
	uint32_t total_fitness;
	uint16_t generation = 0;
	
	//uint8_t mylayers[] = LAYERVALS;
	//printf("%d\n", mylayers[2]);
	//return 0;
	
	//seed the rng
	srand((unsigned) time(&t));
	
	//build the neural net
	ann.init = &initializeNet;
	ann.init(&ann);
	
	//generate a population of random weight sets
	for(i=0; i<POPULATION_SIZE; ++i) initializeWeightSet(&pop[i].set);
	
	
	while(1)
	{
		printf("starting generation %d\n", generation);
		total_fitness = 0;
		
		//for each set of net weights,
		for(i=0; i<POPULATION_SIZE; ++i)
		{
			//load the weights into the net
			ann.load(&ann, &pop[i].set);
			
			//clear the fitness score
			pop[i].fitness = 0;
			
			//for each training image,
			for(j=0; j<30; ++j)
			{
				//input it into the net
				ann.processInputs(&ann, &trainingset[j]);
				
				//process it through the net
				ann.processNet(&ann);
				
				//evaluate the outputs and update the score
				updateFitness(&pop[i], &ann, trainingset[j].value);
			}
			
			printf("training set %d has fitness %d\n", i, pop[i].fitness);
			total_fitness += pop[i].fitness;
		}
		
		//until we have a full new population of weight sets,
		for(i=0; i<POPULATION_SIZE; ++i)
		{
		
			//select/combine pairs using a weighted random process
			mother = father + 1;	//just make them different so we don't skip the loop
			while(mother != father)
			{
				mother = rouletteSelect(pop, total_fitness);
				father = rouletteSelect(pop, total_fitness);
			}
			//procreate(mother, father, &newpop[i], &newpop[i+1]);

			//mutate the new organism
			//mutate(newpop[i]);
			//mutate(newpop[i+1]);
		}


		//replace prev generation with new generation
		for(i=0; i<POPULATION_SIZE; ++i) pop[i] = newpop[i];
	
		//do it again
		printf("total fitness for gen %d:\t%d\n", generation, total_fitness);
		generation++;
		getchar();
	}
	
	
	
	
	
	
	return 0;
}