#include <stdlib.h>
#include "errors.h"
#include <stdio.h>

void errorNoSuchAFileOrDirectory(char * filename) {
    printf("filecopy: não foi possível abrir o arquivo %s: Arquivo ou diretório não existe. \n", filename);
    exit(EXIT_FAILURE);
}

void errorInvalidArgumentsNumber() {
    printf("Número de argumentos inválidos \n");
    exit(EXIT_FAILURE);
}