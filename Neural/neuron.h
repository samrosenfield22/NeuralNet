/**/

#ifndef NEURON_H
#define NEURON_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

//#include "net.h"
#include "netparams.h"
#include "weights.h"

extern uint8_t CELLS_PER_LAYER[];

typedef struct _neuron neuron;

struct _neuron
{
	//parameters
	uint8_t layer;
	float **weights;
	
	//
	bool activated;
	
	//pointers to other neurons
	//neuron **inputs;
	//neuron **outputs;
	
	//function pointers
	void (*init)(neuron *, uint8_t);
	//void (*connect)(neuron *, neuron *);
	//void (*process)(neuron *, neuralnet *);
	void (*setweights)(neuron *, cellweights *);
};

//function prototypes
void initNeuron(neuron *, uint8_t);
//void connectNeurons(neuron *, neuron *);
//void processInputs(neuron *, neuralnet *);
void setWeights(neuron *, cellweights *);

//define undefined layer values
#ifndef LAYER1
	#define LAYER1 0
#endif
#ifndef LAYER2
	#define LAYER2 0
#endif
#ifndef LAYER3
	#define LAYER3 0
#endif
#ifndef LAYER4
	#define LAYER4 0
#endif
#ifndef LAYER5
	#define LAYER5 0
#endif
#ifndef LAYER6
	#define LAYER6 0
#endif
#ifndef LAYER7
	#define LAYER7 0
#endif
#ifndef LAYER8
	#define LAYER8 0
#endif
#ifndef LAYER9
	#define LAYER9 0
#endif


#endif	//NEURON_H