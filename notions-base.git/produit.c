/* à compléter: entêtes */
#include <stdlib.h>

int main(void)
{
	printf("programme qui multiplie 2 nombres\n");
	int premNbr;
	printf("un premier nombre : ");
	scanf("%d",&premNbr);
	int secNbr;
	printf("\nUn deuxieme nombre : ");
	scanf("%d",&secNbr);
	printf("\n %d * %d = %d\n", premNbr, secNbr, premNbr*secNbr);
	return EXIT_SUCCESS;
}
