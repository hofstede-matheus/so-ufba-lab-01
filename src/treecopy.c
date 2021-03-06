#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>

#include <fcntl.h>
#include <errno.h>
#include <dirent.h>

#include "errors.h"

#define EXPECTED_ARGUMENTS 3 /* program name + 2 arguments */

#define TYPE_DIRECTORY 0
#define TYPE_FILE 1

#define BUFFER_SIZE 4096

int checkIfFileOrDirectory(const char *path) {
    struct stat path_stat;
    stat(path, &path_stat);

    if( S_ISDIR(path_stat.st_mode) ) return 0;
    else if ( S_ISREG(path_stat.st_mode) != 0 ) return 1;
    else return -1;
}

char * concatString(const char *str1, const char *str2) {   
    size_t s1, s2, s3, i = 0;
    char *a;

    s1 = strlen(str1);
    s2 = strlen(str2);
    s3 = s1+s2+1;
    a = malloc(s3);

    while(*str1 != '\0') {
        a[i] = *str1;
        str1++;
        i++;
    }
    while(*str2 != '\0') {
        a[i] = *str2;
        str2++;
        i++;
    }

    a[i] = '\0';
    return a;
}

void copyDirectory(char *sourcePath , const char *destinationPath ) {
    DIR *directory = opendir(sourcePath);

    if ( directory == NULL ) {
        switch (errno) {
            case EACCES:
                errorPermission();
                break;
            case ENOENT:
                errorFolderDoesNotExists();
                break;
            case ENOMEM:
                errorMemory();
                break;
            case ENOTDIR:
                errorNotAFolder();
                break;
            default:
                errorCouldNotReadFolder();
                break;
        }
    }

    if (mkdir(destinationPath, 0755) == -1) {
        switch (errno) {
            case EACCES:
                errorPermission();
                break;
            case EEXIST:
                errorFolderAlreadyExists();
                break;
            case ENOMEM:
                errorMemory();
                break;
            default:
                errorCouldNotCreateFolder();
                break;
        }
    }

    struct dirent *dptr = NULL;

    while( NULL != (dptr = readdir(directory)) ) {
        char *rootSource = concatString(sourcePath, "/");
        char *rootDestination = concatString(destinationPath, "/");

        char buf[BUFFER_SIZE];
        int sourceFile, destFile;
        size_t size;

        if ( strcmp(dptr->d_name, ".") && strcmp(dptr->d_name, "..") ) {
            char * currentPath = concatString(rootSource, dptr->d_name);

            switch (checkIfFileOrDirectory(currentPath)) {

                case TYPE_DIRECTORY:
                    copyDirectory(currentPath, concatString(rootDestination, dptr->d_name));
                    break;
                    
                case TYPE_FILE:
                    sourceFile = open(currentPath, O_RDONLY, 0);
                    destFile = open(concatString(rootDestination, dptr->d_name), O_CREAT | O_WRONLY , 0755);

                    if(sourceFile < 0) {
                        if(errno == EACCES);
                        else errorCouldNotReadFile();
                    }

                    if(destFile < 0) {
                        if(errno == EACCES);
                        else errorCouldNotWriteFile();
                    } 

                    while ((size = read(sourceFile, buf, BUFFER_SIZE)) > 0) {
                        if (size == -1) {
                            switch (errno) {
                            case EBADF:
                                errorFileNotOpened();
                                break;
                            case EFAULT:
                                errorSegFault();
                                break;
                            case EISDIR:
                                errorIsDir();
                            }
                        }
                        write(destFile, buf, size);
                    }

                    close(sourceFile);
                    close(destFile);
                    break;
                
                default:
                    errorNotAFileOrFolder();
                    break;
            }
            free(currentPath);
        }
        free(rootSource);
    }
}

int main( int argc, char ** argv ) {

    if (argc == EXPECTED_ARGUMENTS) {
        copyDirectory(argv[1], argv[2]);
    } else {
        errorInvalidArgumentsNumberTreeCopy();        
    }

   return EXIT_SUCCESS;
}