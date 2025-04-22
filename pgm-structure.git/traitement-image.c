#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pgmio.h>
#include <math.h>

//pour compiler juste ce fichier fichier : gcc -std=c99 -Wall -Wextra -g -c -o traitement-image traitement-image.c -lnaivepgmio

//pour compiler fichier objet : 
//      gcc -std=c99 -Wall -Wextra -g -c -o traitement-image.o traitement-image.c
//      gcc -o executable traitement-image.o -lpgmio

void pgm_show(char *filename)
{
    //ouvre l'image en parametre avec le logiciel eog
    char name[80];
    sprintf(name, "eog %s", filename);
    system(name);
}

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

void pgm_solid(pgm_t_image *image, pgm_t_pixel color)
//remplissage de pixels avec des pixels unis
{
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
        //nombre total de pixels
    int surface = image->width*image->height;
    int vecteur = 0;
    int color = 0;

    //pour tous les pixels, on leurs attribut la couleur specifiée
    for (int i=0; i<surface; i++) {

        if (image->pixels[vecteur] > threshold) {
            color = 255;
        } else {
            color = 0;
        }
        
        image->pixels[vecteur] = color;
        vecteur++;
    }
}

void pgm_gradient(pgm_t_image *image) 
{
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

int main(void)
{

    //-------------------------------------------------------------------------------------------------Lecture image
    const char *filename = "guadalest.pgm";
    char *newName = "guadalest_copie.pgm";

    //lecture
    pgm_t_image *image = pgm_read(filename);
    if (image == NULL) {
            printf("Erreur : l'image n'as pas pu etre lue\n");
            return EXIT_FAILURE;
    }



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
    
    return EXIT_SUCCESS;
}