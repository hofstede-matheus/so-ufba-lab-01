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

void errorInvalidArgumentsNumberTreeCopy() {
    printf("treecopy: Quantidade de argumentos inválida! \n");
    printf("Use: treecopy <diretorioorigem> <diretoriodestino> \n");
    exit(EXIT_FAILURE);
}

void errorDestinationDirectoryAlreadyExists() {
    printf("treecopy: O diretório de destino já existe! \n");
    exit(EXIT_FAILURE);
}

void errorNotAFileOrFolder() {
    printf("treecopy: O arquivo atual não é uma diretório ou um arquivo regular! \n");
    exit(EXIT_FAILURE);
}

void errorCouldNotReadFile() {
    printf("treecopy: O arquivo não pôde ser lido! \n");
    exit(EXIT_FAILURE);
}

void errorCouldNotWriteFile() {
    printf("treecopy: Não foi possível criar o arquivo! \n");
    exit(EXIT_FAILURE);
}

void errorPermission() {
    printf("treecopy: Permissão negada! \n");
    exit(EXIT_FAILURE);
}

void errorFolderDoesNotExists() {
    printf("treecopy: O diretório de origem não existe! \n");
    exit(EXIT_FAILURE);
}

void errorMemory() {
    printf("treecopy: Sem memória sufuciente! \n");
    exit(EXIT_FAILURE);
}

void errorNotAFolder() {
    printf("treecopy: O diretório de origem não é um diretório! \n");
    exit(EXIT_FAILURE);
}

void errorCouldNotReadFolder() {
    printf("treecopy: O diretório não pôde ser lido! \n");
    exit(EXIT_FAILURE);
}

void errorFolderAlreadyExists() {
    printf("treecopy: O diretório de destino já existe! \n");
    exit(EXIT_FAILURE);
}

void errorCouldNotCreateFolder() {
    printf("treecopy: O diretório não pôde ser criado! \n");
    exit(EXIT_FAILURE);
}

void errorFileNotOpened() {
    printf("treecopy: O arquivo não foi aberto! \n");
    exit(EXIT_FAILURE);
}

void errorSegFault() {
    printf("treecopy: O endereço de memória não está acessível! \n");
    exit(EXIT_FAILURE);
}

void errorIsDir() {
    printf("treecopy: fd é um diretório! \n");
    exit(EXIT_FAILURE);
}
