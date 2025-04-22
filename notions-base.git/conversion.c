/* à compléter: entêtes */
#include <stdlib.h>
#include <stdio.h>

float celsius(float fahrenheit)
{

    float calc = (5.0/9.0) * (fahrenheit-32);
    return calc;
}

int main(void)
{
	printf("programme qui affiche la table de conversion en celsius\n");
	printf("----------------------\n");
    printf("Fahrenheit \tCelsius\n");
    printf("----------------------\n");
    for (int i=0; i<=200; i+=20) 
    {
        float result = celsius(i);
        printf(" %d \t\t%.1f\n", i, result);
    }
	return EXIT_SUCCESS;
}