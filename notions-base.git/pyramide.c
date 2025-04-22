/* à compléter: entêtes */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#define BUFFER_LEN 64


void putchars(unsigned int repeat, char ch)
{
    for(int i=0; i<=repeat; i++) {
        putchar(ch);
    }
}

int main(void)
{
    int h;
    char premChar = ' ';
    char secChar = ' ';
	printf("quelle hauteur pour la pyramide ? : ");
    scanf("%d", &h);
    printf("quel caractère pour la pyramide ? ");
    scanf(" %c", &secChar);


    for (int i = 0; i < h; i++)
    {
        putchars(h-i,premChar);
        
        putchars(i*2,secChar);
        putchars(h-i,premChar);
        printf("\n");
    }
    

	return EXIT_SUCCESS;
}
