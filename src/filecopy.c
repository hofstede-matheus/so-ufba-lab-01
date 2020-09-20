#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "errors.h"

#define EXPECTED_ARGUMENTS 3 /* program name + 2 arguments */
#define BUFFER_SIZE 4096 /* buffer 4MB */

void copyFile(char *src_Path , char *dst_Path){
    int src_File, dst_File, n, endOfFile;
    unsigned char buffer[4096];

    src_File = open(src_Path, O_RDONLY);
    dst_File = open(dst_Path, O_CREAT | O_WRONLY);
    
    if(src_File == -1){
        errorNoSuchAFileOrDirectory(src_Path);
    }

    while(1){
        endOfFile = read(src_File, buffer, BUFFER_SIZE);
        if (endOfFile == -1){
            printf("Error reading file. \n");
            exit(1);
        }

        n = endOfFile;

        if(n == 0)
            break;

        endOfFile = write(dst_File, buffer, n);

        if(endOfFile == -1){
            printf("Error writing to file.\n");
            exit(1);
        }
    }

    close(src_File);
    close(dst_File);
}

int main( int argc, char ** argv){

    if (argc == EXPECTED_ARGUMENTS) {
        printf("OK \n");

        copyFile(argv[1], argv[2]);
    } else {
        errorInvalidArgumentsNumber();
    }

   return EXIT_SUCCESS;
}

