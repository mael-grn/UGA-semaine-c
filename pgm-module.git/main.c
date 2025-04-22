#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pgmio.h>
#include "traitement.h"
#include "allocation.h"
#include <time.h>
#include <sys/time.h>

//pour compiler fichier objet : 
//      gcc -std=c99 -Wall -Wextra -g -c -o main.o main.c
//      gcc -o executable allocation.o main.o traitement.o -lpgmio


void pgm_show(char *filename)
{
    //ouvre l'image en parametre avec le logiciel eog
    char name[80];
    sprintf(name, "eog %s", filename);
    system(name);
}

int main(void)
{
    //clock_t tempsDeb = clock();
    //printf("%lf\n", (double)tempsDeb/CLOCKS_PER_SEC);

    //utilisation de gettimeofday plutot que clock, car cock ne renvoi pas une valeur correct pour une raison inconnue
    struct timeval t1, t2;
    gettimeofday(&t1, NULL);

    
    for (int i=0; i<=100; i++) {

        //-------------------------------------------------------------------------------------------------Lecture image
        const char *filename = "guadalest.pgm";
        char *newName = "guadalest_copie.pgm";

        //lecture
        pgm_t_image *image = pgm_read(filename);
        



        //-------------------------------------------------------------------------------------------------Copie image
        //copie de l'image
        pgm_write(newName, image);


        

        //-------------------------------------------------------------------------------------------------image Unie
        size_t w =500;
        size_t h =500;
        pgm_t_image *imageUni = pgm_malloc(w, h);
        pgm_t_pixel colorUni = 42;
        char *nameUni = "my_image_uni.pgm";
        pgm_solid(imageUni, colorUni);
        pgm_write(nameUni, imageUni);
        pgm_free(imageUni);



        //-------------------------------------------------------------------------------------------------image dégradée
        pgm_t_image *ImageDeg = pgm_malloc(w, h);
        char *nameDeg = "my_image_deg.pgm";
        pgm_gradient(ImageDeg);
        pgm_write(nameDeg, ImageDeg);
        pgm_free(ImageDeg);
        


        //-------------------------------------------------------------------------------------------------image négative
        
        
        pgm_t_image imageNeg = *image;
        char *nameNeg = "guadalest_negatif.pgm";
        pgm_negative(&imageNeg);
        pgm_write(nameNeg, &imageNeg);



        //-------------------------------------------------------------------------------------------------image threshold

        pgm_t_image imageNB = *image;
        char *nameNB = "guadalest_NB.pgm";
        pgm_threshold(&imageNB, 127);
        pgm_write(nameNB, &imageNB);

        

        //-------------------------------------------------------------------------------------------------étapes de fin
        //ouvrir l'image
        //pgm_show(nameUni);
        //eviter les fuites memoires
        pgm_free(image);
    }

    //clock_t tempsFin = clock();

    gettimeofday(&t2, NULL);

    double elapsedtime = (t2.tv_sec - t1.tv_sec)*1000;

    printf("temps d'execution : %lf\n", elapsedtime);

    //printf("%lf\n", (double)tempsFin/CLOCKS_PER_SEC);
    //double tempsSec = (double) (tempsFin - tempsDeb)/CLOCKS_PER_SEC;
    //printf("\nDurée total déxecution : %lf\n", tempsSec);
    
    return EXIT_SUCCESS;
}