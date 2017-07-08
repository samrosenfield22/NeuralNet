/**/

#ifndef IMAGE_H
#define IMAGE_H

#include <stdint.h>

typedef struct _image image;

struct _image
{
	uint8_t value;
	char image[8][8];
};

//
extern image trainingset[];
extern image testset[];

#endif	//IMAGE_H