#ifndef ERRORS_H   // guardas de cabeçalho, impedem inclusões cíclicas
#define ERRORS_H

void errorNoSuchAFileOrDirectory(char * filename);
void errorInvalidArgumentsNumber();
void errorInvalidArgumentsNumberTreeCopy();
void errorNotAFileOrFolder();
void errorCouldNotReadFile();
void errorCouldNotWriteFile();
void errorPermission();
void errorFolderDoesNotExists();
void errorMemory();
void errorNotAFolder();
void errorCouldNotReadFolder();
void errorFolderAlreadyExists();
void errorCouldNotCreateFolder();
void errorFileNotOpened();
void errorSegFault();
void errorIsDir();

#endif