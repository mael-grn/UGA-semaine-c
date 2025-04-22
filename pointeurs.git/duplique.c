#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


char *copier_chaine(char *str)
{
    size_t lenght = strlen(str);

    char *chaine = malloc( lenght+1);
    strcpy(chaine, str);
    
    return chaine;
}

int main(void)
{
    char chaine[64] = "";
    printf("saisir une chaine : ");
    scanf("%s", &chaine);
    char *chaineBis;
    chaineBis = copier_chaine(chaine);
    printf("\nla chaine de base : %s\nla chaine copiée : %s\n", chaine, chaineBis);
    free(chaineBis);
    return EXIT_SUCCESS;
}