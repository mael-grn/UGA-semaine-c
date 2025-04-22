#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[])
{
    
    
    if (argc != 4)
    {
        printf("erreur");
        return EXIT_FAILURE;
    }

    int premNbr = atoi(argv[1]);
    int secNbr = atoi(argv[3]);
    char op = *argv[2];
    if(op == 'x') 
    {
        printf("%d x %d = %d\n", premNbr, secNbr, premNbr*secNbr);
    } else if(op == '/')
    {
        printf("%d / %d = %d\n", premNbr, secNbr, premNbr/secNbr);
    } else if(op == '-')
    {
        printf("%d - %d = %d\n", premNbr, secNbr, premNbr-secNbr);
    } else if(op == '+')
    {
        printf("%d + %d = %d\n", premNbr, secNbr, premNbr+secNbr);
    } else {
        printf("erreur");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}