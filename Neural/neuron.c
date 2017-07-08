/**/

#include "neuron.h"

uint8_t CELLS_PER_LAYER[] = {LAYER0, LAYER1, LAYER2, LAYER3, LAYER4, LAYER5, LAYER6, LAYER7, LAYER8, LAYER9};

void initNeuron(neuron *cell, uint8_t layer)
{
	float **wptr;		//weight ptr
	uint8_t i;
	
	//check function arguments
	if (layer > LAYERS-1)
	{
		printf("Error! Invalid layer given to initNeuron()\n");
		return;
	}
	
	//point function pointers to their functions
	//cell->connect = &connectNeurons;
	//cell->process = &processInputs;
	cell->setweights = &setWeights;
	
	//initialize params
	cell->layer = layer;
	
	//initialize i/o
	if (layer != 0)
	{
		//cell->inputs = malloc(CELLS_PER_LAYER[layer-1] * sizeof(neuron *));
		cell->weights = malloc(CELLS_PER_LAYER[layer-1] * sizeof(float *));
		
		//allocate all the weights, set them to 0
		wptr = cell->weights;
		for(i=0; i<CELLS_PER_LAYER[layer-1]; i++)
		{
			(*wptr) = malloc(sizeof(float));
			**wptr = 0;
			wptr++;
		}
	}
	else
	{
		cell->weights = malloc(sizeof(float *));
		*(cell->weights) = malloc(sizeof(float));
	}
	/*if (layer != LAYERS)
	{
		//cell->outputs = malloc(CELLS_PER_LAYER[layer+1] * sizeof(neuron *));
	}
	else
	{
		//cell->outputs = NULL;
	}*/
	
}

/*void connectNeurons(neuron *a, neuron *b)
{
	
}*/

void setWeights(neuron *cell, cellweights *wtbl)
//void setWeights(neuron *cell, wtbl *wtbl)
{
	float **wptr;						//points to the cell's weight structure
	float **local_wtbl = wtbl->wtbl;	//points to the weights to be loaded
	uint8_t i;
	
	//printf("setting weights...\n");
	
	wptr = cell->weights;
	
	//printf("Cell on layer %d has %d weights to set\n", (cell->layer), CELLS_PER_LAYER[(cell->layer)-1]);
	
	for(i=0; i<CELLS_PER_LAYER[cell->layer-1]; ++i)
	{
		//**wptr = **weights;
		**wptr = **local_wtbl;
		wptr++; local_wtbl++;
	}
	
}

/*void processInputs(neuron *cell, neuralnet *net)	//the whole net -- or the whole previous layer -- needs to be an arg
{
	
}*/








