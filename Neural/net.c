/**/

#include "net.h"


void initializeNet(neuralnet *net)
{
	uint8_t i, j;
	neuron **nptr;
	
	//funcptrs
	net->load = &loadWeights;
	net->processInputs = &processInputs;
	net->processNet = &processNet;
	net->processCell = &processCell;
	
	for(i=0; i<LAYERS; ++i)
	{
		//allocate memory for each layer of ptrs
		net->layer[i] = malloc(CELLS_PER_LAYER[i] * sizeof(neuron *));
		
		//allocate + instantiate each neuron
		nptr = net->layer[i];
		for(j=0; j<CELLS_PER_LAYER[i]; ++j)
		{
			(*nptr) = malloc(sizeof(neuron));
			(*nptr)->init = &initNeuron;		//point the init funcptr to the function so we can call it
			(*nptr)->init((*nptr), i);
			
			nptr++;
		}
	}
}

void loadWeights(neuralnet *net, weightset *weights)
{
	neuron **curLayer;
	cellweights **curWtbl;
	uint8_t i, j;
	
	//initialize
	
	
	for(i=0; i<LAYERS; ++i)
	{
		curLayer = net->layer[i];
		curWtbl = weights->layer[i];
		
		for(j=0; j<CELLS_PER_LAYER[i]; ++j)
		{
			setWeights(*curLayer, *curWtbl);		//neuron *cell, cellweights *wtbl
			curLayer++;
			curWtbl++;
		}
	}
	
}

void processNet(neuralnet *net)
{
	uint8_t i, j;
	neuron **nptr;
	
	//note that the input layer is processed in a different function, so we index from layer 1
	for(i=1; i<LAYERS; ++i)
	{
		nptr = net->layer[i];	//point to the current layer
		
		for(j=0; j<CELLS_PER_LAYER[i]; ++j)
		{
			//printf("Processing cell (%d,%d):\n", i, j);
			processCell(*nptr, net);
			nptr++;
		}
	}
}


void processInputs(neuralnet *net, image *image)
{
	uint8_t i;
	neuron **nptr;
	float **fptr;
	
	nptr = net->layer[0];
	
	for(i=0; i<CELLS_PER_LAYER[0]; ++i)
	{
		fptr = ((*nptr)->weights);
		
		if (((**fptr) > 0) && (image->image[i/8][i%8] == '#')) (*nptr)->activated = 1;
		else (*nptr)->activated = 0;
		
		nptr++;
	}
	
	
}

void processCell(neuron *cell, neuralnet *net)
{
	float activationSum = 0;
	//float curweight;
	neuron **incell;
	float **wptr;
	uint8_t i;
	uint8_t inweights;
	
	
	//set the index to the first weight ptr
	wptr = cell->weights;
	
	//determine the number of input weights
	if (cell->layer == 0) inweights = 1;
	else inweights = CELLS_PER_LAYER[cell->layer-1];
	
	//printf("\tactivated weights: ");
	for(i=0; i<inweights; ++i)
	{
		//grab the addr of the input cell
		incell = net->layer[cell->layer-1];
		
		
		if ((*incell)->activated)
		{
			activationSum += (**wptr);		//add the (weight*activation) of the input cell
			//printf("%f,", **wptr);
		}
		
		incell++;	//point to the next input cell
		wptr++;		//point to the next weight
	}
	
	//set cell's activation
	//printf("\n\tactivation sum = %f\n", activationSum);
	if (activationSum >= 0) cell->activated = 1;
	else cell->activated = 0;
	//printf("\tcell activation = %d\n\n", cell->activated);
}

