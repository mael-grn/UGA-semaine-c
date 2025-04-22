/* à compléter: entêtes */
#include <stdlib.h>

int main(int argc, char *argv[])
{
	/* à compléter: corps de main */
	if (argc < 2)
	{
		return 1;
	}

	for (int i=1; i< argc; i++) {
		printf("%s ", argv[i]);
	}
	printf("\n");
	return EXIT_SUCCESS;
}
