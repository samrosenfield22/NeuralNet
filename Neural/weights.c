/**/

#include "weights.h"
#include "neuron.h"

void initializeWeightSet(weightset *weights)
{
	uint8_t i, j, k;
	cellweights **wtbl_ptr;		//double ptr to a weight table
	float **wptr;				//double ptr to a value in the table
	uint8_t inweights;
	
	//initialize each layer
	for(i=0; i<LAYERS; ++i)
	{
		weights->layer[i] = malloc(CELLS_PER_LAYER[i] * sizeof(cellweights *));		//allocate for each wtbl pointer
		wtbl_ptr = weights->layer[i];		//wtbl_ptr points to float ptrs
		
		for(j=0; j<CELLS_PER_LAYER[i]; ++j)
		{
			
			//allocate for each weight table structure
			(*wtbl_ptr) = malloc(sizeof(cellweights));
			
			//find the number of input weights to the current cell
			if (i==0) inweights = 1;
			else inweights = CELLS_PER_LAYER[i-1];
			
			//allocate for each input weight ptr
			(*wtbl_ptr)->wtbl = malloc(inweights * sizeof(float *));
			wptr = (*wtbl_ptr)->wtbl;
			
			//allocate & give random values to each input weight
			for(k=0; k<inweights; ++k)
			{
				(*wptr) = malloc(sizeof(float));
				**wptr = getRand();
				//printf("Assigned weight %f to cell (%d,%d), input %d\n", **wptr, i, j, k);
				wptr++;
			}
			
			wtbl_ptr++;
		}
	}
}

void initializeWeightTable(cellweights *wtbl)
{
	
}

float getRand()
{	
	return ((float)rand()/(RAND_MAX>>1) - 1);
}
