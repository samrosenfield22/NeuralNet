/*
	configuration file for the ANN
*/

#ifndef NETPARAMS_H
#define NETPARAMS_H


//define the number of layers (should this include net i/o?)
#define LAYERS 4

//define the number of neurons on each layer
//#define CELLS_PER_LAYER[4] {64, 32, 4, 10}
//extern uint8_t CELLS_PER_LAYER[4];
//#define INLAYER 64
//#define OUTLAYER 10

#define LAYER0 64
#define LAYER1 32
#define LAYER2 20
#define LAYER3 10
//#define LAYER4 0
//#define LAYER5 0
//#define LAYER6 0
//#define LAYER7 0
//#define LAYER8 0
//#define LAYER9 0

#define LAYERVALS {64, 32, 20, 10}




#endif	//NETPARAMS_H