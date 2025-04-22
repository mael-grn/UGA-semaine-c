#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

void bin2dec(char bin[], char dec[])
{
    //alogrithme partagé par jules, car le mien ne fonctionnait pas (j'utilisais la fonction pow() de la librarie math, qui ne ne fonctionnait pas)
    int decimal =0;
    int length = strlen(bin);
    for (int i=length-1, base = 1; i >=0; i--, base*=2) {
        int bit = bin[i] - '0';
        decimal += bit*base;

    }
    sprintf(dec, "%d", decimal);
}

int main(void)
{
    char bin[64] = "0";
    printf("ecrir votre nombre : ");
    scanf("%s", &bin);
    char dec[64] = "0";
    bin2dec(bin, dec);
    printf("<%s>2 = <%s>10\n", bin, dec);
    return EXIT_SUCCESS;
}