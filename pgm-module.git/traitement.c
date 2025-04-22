#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pgmio.h>
#include <math.h>

#define SEUIL1_PIXEL(a, b) (((a)<(b))?0:255)
#define SEUIL2_PIXEL(a, b) (((a)<(b))?(a)=0:(a)=255)

#define DEBUG 0
#if DEBUG
#define AFF_FONCT printf("%s\n", __func__)
#else
#define AFF_FONCT
#endif

//pour compiler fichier objet : 
//      gcc -std=c99 -Wall -Wextra -g -c -o traitement.o traitement.c
//      gcc -o executable allocation.o main.o traitement.o -lpgmio

void pgm_solid(pgm_t_image *image, pgm_t_pixel color)
//remplissage de pixels avec des pixels unis
{
        AFF_FONCT;
    //nombre total de pixels
    int surface = image->width*image->height;
    int vecteur = 0;

    //pour tous les pixels, on leurs attribut la couleur specifiée
    for (int i=0; i<surface; i++) {
        image[0].pixels[vecteur] = color;

        //mise a jour de notre position
        vecteur++;
    }
}

void pgm_negative(pgm_t_image *image)
{
        AFF_FONCT;
    int surface = image->height*image->width;
    int vecteur = 0;
    pgm_t_pixel color = 0;

    //pour tous les pixels, on leurs attribut la couleur specifiée
    for (int i=0; i<surface; i++) {

        color = 255 - image->pixels[vecteur];
        
        image->pixels[vecteur] = color;

        //attribuer la couleur au pixel courant
        vecteur++;
    }
}

void pgm_threshold(pgm_t_image *image, pgm_t_pixel threshold)
{
        AFF_FONCT;
        //nombre total de pixels
    int surface = image->width*image->height;
    int vecteur = 0;
    int color = 0;

    //question 12 de l'unité 5


    //pour tous les pixels, on leurs attribut la couleur specifiée
    for (int i=0; i<surface; i++) {

        color = SEUIL1_PIXEL(image->pixels[vecteur], threshold);
        
        image->pixels[vecteur] = color;
        vecteur++;
    }
}

void pgm_gradient(pgm_t_image *image) 
{
        AFF_FONCT;
    //nombre total de pixels
    int width = image->width;
    int height = image->height;

    int x = 0;
    int y = 0;
    int vecteur = 0;
    pgm_t_pixel color = 0;

    //pour tous les pixels, on leurs attribut la couleur specifiée
    for (int i=0; i<width*height; i++) {

        color = x*255/image->width;
        
        image->pixels[vecteur] = color;

        //attribuer la couleur au pixel courant
        
        //quand on chande de ligne
        if (x==width) {
            y++;   
            x = 0;
        } else {
            x++;
        }

        //mise a jour de notre position
        vecteur = y * width + x;
    }
}

