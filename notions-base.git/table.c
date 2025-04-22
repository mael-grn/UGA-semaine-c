/* à compléter: entêtes */
#include <stdlib.h>

int main(void)
{
	printf("programme qui affiche la table de multiplication d'un nombre\n");
	int nbr;
	printf("choisir votre nombre :");
	scanf("%d",&nbr);
	
    for (int i=0;i<10; i++) 
    {
        printf("\n %d * %d = %d\n", nbr, i, nbr*i);
    }
	return EXIT_SUCCESS;
}