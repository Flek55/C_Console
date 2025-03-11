#include "files.h"


int isFileExist(const char* fileName) {
    FILE *file = openFileRMode(fileName);
    int is_open = (file != NULL);

    if (is_open)
        fclose(file);

    return is_open;
}

FILE* openFileRMode(const char* fileName) {
    return fopen(fileName, "r");
}
