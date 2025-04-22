/* à compléter: entêtes */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define BUFFER_LEN 64

int main(void)
{
	char orig[BUFFER_LEN] = "bonjour";
	// = {0}; is the universal zero initializer, C99 Standard 6.7.8.21
	char mirror[BUFFER_LEN] = {0};  // fill buffer with 0 (a.k.a. '\0')

	/* à compléter: corps de main */
	//int i = const char* orig;
	int origlen =strlen(orig);
	
	int j = origlen-1;

	for (int i=0; i<origlen; i++)
	{
		mirror[j] = orig[i];
		j--;
	}

	printf("%s inversé donne %s\n", orig, mirror);

	return EXIT_SUCCESS;
}
