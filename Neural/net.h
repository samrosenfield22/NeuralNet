/**/

#ifndef NET_H
#define NET_H

#include "neuron.h"
#include "netparams.h"
#include "weights.h"

#include "../Images/imgdef.h"

typedef struct _neuralnet neuralnet;

struct _neuralnet
{
	neuron **layer[LAYERS];
	
	//function pointers
	void (*init)(neuralnet *);
	void (*load)(neuralnet *, weightset *);
	void (*processInputs)(neuralnet *, image *);
	void (*processNet)(neuralnet *);
	void (*processCell)(neuron *, neuralnet *);
};


//func prototypes
void initializeNet(neuralnet *);
void loadWeights(neuralnet *, weightset *);
void processInputs(neuralnet *, image *);
void processNet(neuralnet *);
void processCell(neuron *, neuralnet *);





#endif	//NET_H