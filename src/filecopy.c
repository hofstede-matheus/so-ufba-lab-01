#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define EXPECTED_ARGUMENTS 3 /* program name + 2 arguments */

void errorNoSuchAFileOrDirectory(char * filename) {
    printf("filecopy: não foi possível abrir o arquivo %s: Arquivo ou diretório não existe. \n", filename);
    exit(EXIT_FAILURE);
}

int main( int argc, const char ** argv ) {
    char buf;
    int sourcefile, destfile, n;

    if (argc == EXPECTED_ARGUMENTS) {
        printf("OK \n");

        sourcefile = open(argv[1], O_RDONLY);

        if (sourcefile == -1) {
            errorNoSuchAFileOrDirectory(argv[1]);
        }

    } else {
        printf("Número de argumentos inválidos \n");
        exit (EXIT_FAILURE);
    }

   return 0;
}

