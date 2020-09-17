#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "errors.h"

#define EXPECTED_ARGUMENTS 3 /* program name + 2 arguments */


int main( int argc, char ** argv ) {
    char buffer;
    int sourcefile, destfile, n;

    if (argc == EXPECTED_ARGUMENTS) {
        printf("OK \n");

        sourcefile = open(argv[1], O_RDONLY);

        if (sourcefile == -1) {
            errorNoSuchAFileOrDirectory(argv[1]);
        }

    } else {
        errorInvalidArgumentsNumber();
    }

   return EXIT_SUCCESS;
}

