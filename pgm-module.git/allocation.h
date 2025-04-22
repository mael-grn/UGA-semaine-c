#ifndef ALLOCATION_H_ 
#define ALLOCATION_H_

//INDEPENDANT

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pgmio.h>
#include <math.h>

pgm_t_image *pgm_malloc(size_t width, size_t height);
void pgm_free(pgm_t_image *image);

#endif  /*ALLOCATION_H_ */