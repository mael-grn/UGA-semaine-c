#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void permuter(int *adr_a, int *adr_b)
{
    int temp = *adr_a;
    *adr_a = *adr_b;
    *adr_b = temp;
}

int main(void)
{
    printf("saisir un premier entier : ");
    int premEnt = 0;
    scanf("%d", &premEnt);

    printf("saisir un second entier : ");
    int secEnt = 0;
    scanf("%d", &secEnt);

    printf("permutation des deux entier : \n\ta = %d, b = %d\n\tPermutation...\n", premEnt, secEnt);
    permuter(&premEnt, &secEnt);
    printf("\tMaintenant, a = %d et b = %d\n", premEnt, secEnt);
    return EXIT_SUCCESS;
}