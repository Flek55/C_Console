#ifndef FILES_H
#define FILES_H
#include <stdio.h>
#include <string.h>
#include "menuActions.h"

int isFileExist(const char* fileName);
FILE* openFileRMode(const char* fileName);

#endif // FILES_H
