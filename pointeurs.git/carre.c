#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int carre_copie(int n)
{
    return n*n;
}

void carre_adresse(int *adr_n)
{
    *adr_n = *adr_n * *adr_n;
}

int main(void)
{
    printf("saisir un entier : ");
    int entier = 0;
    scanf("%d", &entier);
    printf("calcul du carré de l'entier sans pointeur :\n");
    int entier_bis = carre_copie(entier);
    printf("\tvaleur de la variable de base apres calcul : %d \n\tvaleur de la variable secondaire : %d\n", entier, entier_bis);


    printf("\ncalcul du carré de l'entier avec pointeur : \n");
    carre_adresse(&entier);
    printf("\tvaleur de la variable de base apres calcul : %d\n", entier);

    return EXIT_SUCCESS;
}