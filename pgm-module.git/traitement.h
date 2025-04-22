#ifndef TRAITEMENT_H_ 
#define TRAITEMENT_H_

//INDEPENDANT

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pgmio.h>
#include <math.h>



void pgm_solid(pgm_t_image *image, pgm_t_pixel color);
void pgm_negative(pgm_t_image *image);
void pgm_threshold(pgm_t_image *image, pgm_t_pixel threshold);
void pgm_gradient(pgm_t_image *image);

#endif  /*TRAITEMENT_H_*/ 