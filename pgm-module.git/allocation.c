#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pgmio.h>
#include <math.h>

//pour compiler fichier objet : 
//      gcc -std=c99 -Wall -Wextra -g -c -o allocation.o allocation.c
//      gcc -o executable allocation.o main.o traitement.o -lpgmio


pgm_t_image *pgm_malloc(size_t width, size_t height)
{
    //alloue l'espace necessaire pour une image
    pgm_t_image *image = malloc(sizeof (pgm_t_image));
    if (image == NULL) {
    // Gestion de l'erreur si l'allocation échoue
    perror("Erreur lors de l'allocation de l'image");
    exit(EXIT_FAILURE);
    }

    image->width = width;
    image->height = height;

    image->pixels = malloc(sizeof(pgm_t_pixel) * width * height);
    if (image->pixels == NULL) {
        // Gestion de l'erreur si l'allocation échoue
        perror("Erreur lors de l'allocation des pixels de l'image");
        free(image);  // Libère l'image partiellement allouée
        exit(EXIT_FAILURE);
    }
    return image;
}

void pgm_free(pgm_t_image *image)
{
    free(image->pixels);
    free(image);
}