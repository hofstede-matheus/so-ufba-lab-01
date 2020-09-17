#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "errors.h"

#define EXPECTED_ARGUMENTS 3 /* program name + 2 arguments */

int main( int argc, char ** argv ) {
   if (argc == EXPECTED_ARGUMENTS) {
        printf("OK \n");
    } else {
        errorInvalidArgumentsNumber();        
    }

   return EXIT_SUCCESS;
}