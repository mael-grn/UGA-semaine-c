#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

void dec2bin(char bin[], char dec[])
{
    //convertir la chaine en int :
    int nbr = strtol(dec, NULL, 10);
    int rest = 0;
    
    while(nbr>0) {
        //calculer le reste de la division de notre nombre par deux
        rest = nbr%2;
        nbr=nbr/2;
        //placer le nombre recupéré au debut de la chaine
        char temp[64];
        strcpy(temp, bin);
        sprintf(bin, "%d", rest);
        strcat(bin, temp);
    }
    printf("<%s>10 = <%s>2\n", dec, bin);
}

int main(void)
{
    char dec[64] = "";
    char bin[64] = "";
    printf("ecrir votre nombre : ");
    scanf("%s", &dec);
    
    dec2bin(bin, dec);
    
    return EXIT_SUCCESS;
}