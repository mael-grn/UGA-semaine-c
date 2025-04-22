#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <naivepgmio.h>
#include <math.h>

//pour compiler juste ce fichier fichier : gcc -std=c99 -Wall -Wextra -g -c -o traitement-image traitement-image.c -lnaivepgmio

//pour compiler fichier objet : 
//      gcc -std=c99 -Wall -Wextra -g -c -o traitement-image.o traitement-image.c
//      gcc -o executable traitement-image.o -lnaivepgmio

void pgm_show(char *filename)
{
    //ouvre l'image en parametre avec le logiciel eog
    char name[80];
    sprintf(name, "eog %s", filename);
    system(name);
}

pgm_t_pixel *pgm_malloc(int width, int height)
{
    //alloue l'espace necessaire pour une image
    int surface = width*height;
    pgm_t_pixel *image = malloc(surface+1);
    return image;
}

void pgm_solid(pgm_t_pixel *pixels, int width, int height, pgm_t_pixel color)
//remplissage de pixels avec des pixels unis
{
    //nombre total de pixels
    int surface = width*height;

    int x = 0;
    int y = 0;
    int vecteur = 0;

    //pour tous les pixels, on leurs attribut la couleur specifiée
    for (int i=0; i<surface; i++) {
        
        pixels[vecteur] = color;

        //attribuer la couleur au pixel courant
        //pour un peut plus de fantaisie :
        //pixels[vecteur] = rand() % 255 + 1;

        vecteur++;
    }
}

void pgm_negative(pgm_t_pixel *pixels, int width, int height)
{
    //nombre total de pixels
    int surface = width*height;

    int x = 0;
    int y = 0;
    int vecteur = 0;
    pgm_t_pixel color = 0;

    //pour tous les pixels, on leurs attribut la couleur specifiée
    for (int i=0; i<surface; i++) {

        color = 255 - pixels[vecteur];
        
        pixels[vecteur] = color;

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

void pgm_threshold(pgm_t_pixel *pixels, int width, int height, pgm_t_pixel threshold)
{
        //nombre total de pixels
    int surface = width*height;

    int x = 0;
    int y = 0;
    int vecteur = 0;
    pgm_t_pixel color = 0;

    //pour tous les pixels, on leurs attribut la couleur specifiée
    for (int i=0; i<surface; i++) {

        if (pixels[vecteur] > threshold) {
            color = 255;
        } else {
            color = 0;
        }
        
        pixels[vecteur] = color;

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

void pgm_gradient(pgm_t_pixel *pixels, int width, int height) 
{
    //nombre total de pixels
    int surface = width*height;

    int x = 0;
    int y = 0;
    int vecteur = 0;
    pgm_t_pixel color = 0;

    //pour tous les pixels, on leurs attribut la couleur specifiée
    for (int i=0; i<surface; i++) {

        color = x*255/width;
        
        pixels[vecteur] = color;

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

int main(void)
{
    //variables
    size_t w;
    size_t h;
    const char *filename = "guadalest.pgm";
    char *newName = "guadalest_copie.pgm";

    //lecture de l'image presente dans le dossier
    pgm_t_pixel *image = pgm_naiveread(filename, &w, &h);
    if (image == NULL) {
        printf("Erreur : l'image n'as pas pu etre lue");
        return EXIT_FAILURE;
    }

    //copie de l'image
    pgm_naivewrite(newName, image, w, h);


    //creation d'une nouvelle image unie
    pgm_t_pixel *pixelsUni = pgm_malloc(w, h);
    pgm_t_pixel colorUni = 42;
    char *nameUni = "my_image_uni.pgm";
    pgm_solid(pixelsUni, w, h, colorUni);
    pgm_naivewrite(nameUni, pixelsUni, w, h);
    free(pixelsUni);

    //creation d'une nouvelle image degradée
    pgm_t_pixel *pixelsDeg = pgm_malloc(w, h);
    char *nameDeg = "my_image_deg.pgm";
    pgm_gradient(pixelsDeg, w, h);
    pgm_naivewrite(nameDeg, pixelsDeg, w, h);
    free(pixelsDeg);
    
    //creation d'une image negatif
    pgm_t_pixel *imageNeg = image;
    char *nameNeg = "guadalest_negatif.pgm";
    pgm_negative(imageNeg, w, h);
    pgm_naivewrite(nameNeg, imageNeg, w, h);

    //creation d'une image noir/blanc
    pgm_t_pixel *imageNB = image;
    char *nameNB = "guadalest_NB.pgm";
    pgm_threshold(imageNB, w, h, 127);
    pgm_naivewrite(nameNB, imageNB, w, h);

    //ouvrir l'image avec une application
    pgm_show(nameUni);

    //eviter les fuites memoires
    free(image);
    
    return EXIT_SUCCESS;
}