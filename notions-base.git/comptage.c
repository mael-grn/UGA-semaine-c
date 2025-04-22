#define _POSIX_C_SOURCE 200809L  // getline in POSIX.1-2008

/* à compléter: entêtes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/*
 * readline() reads an entire line from stream and stores at most one less than
 * size characters into the buffer pointed to by buffer.
 * A terminating null byte ('\0') is stored after the last character in the
 * buffer.
 *
 * On success, readline() returns the number of characters read, excluding the
 * terminating null byte ('\0').
 *
 * The function returns -1 on failure to read a line (including end-of-file
 * condition).
 */
static ssize_t readline(char *buffer, size_t size, FILE *stream)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	ssize_t ncopied = -1;

	nread = getline(&line, &len, stream);
	if (nread != -1) {
		// copy at most size - 1 bytes
		ncopied = nread < (ssize_t)size - 1 ? nread : (ssize_t)size - 1;
		memcpy(buffer, line, ncopied);
		// terminating null byte
		buffer[size] = '\0';
	}
	free(line);

	return ncopied;
}

int main(void)
{
	printf("Saisir une phrase : ");
	char buffer[64];
	ssize_t nread;
	nread = readline(buffer, 64, stdin);
	int nbrLow = 0;
	int nbrUp = 0;

    //creation d'un tableau de int de 128 élements 
    int charCount[128] = {0};

    //ajout de chaque lettre du buffer à ce tableau, à l'index correspondant à son code ascii. le compteur correspondant à cet index est incrementé
	for (ssize_t i=0; i<nread; i++) 
    {
		char unChar = buffer[i];
        charCount[(unsigned char) unChar]++;
	}

    //affichage de tous les éléments dont le compteur est superieur à 1, soit toutes les caracteres dont le nombre d'occurence est superieur à 1
    for (int i = 0; i<128; i++) {
        if (charCount[i]>0)
        {
            printf("%c: \t%d\n", i, charCount[i]);
        }
    }
	return EXIT_SUCCESS;
}
