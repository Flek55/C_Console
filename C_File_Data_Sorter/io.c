#include "io.h"


void inputName(char* artistName) {
    printf("Enter name to be deleted: ");
    scanf("%s", artistName);
    strcat(artistName, "\n");
}

void showMenu() {
    printf("1. Add music\n");
    printf("2. List all music\n");
    printf("3. Delete music by artist\n");
    printf("4. Sort music by name\n");
    printf("5. Exit\n");
    printf("Input number: ");
}

int getFilePath(char* filePath) {
    return scanf("%s", filePath);
}

void printArtistNotFound() {
    printf("Artist not found!\n");
}

void reenterNumber() {
    printf("Input a number from 1 to 5!\n");
}

void printNextAction() {
    printf("\n");
}

void printMusicAdded() {
    printf("Music successfully added!\n");
}

void printMusicSortedByName() {
    printf("Music sorted by name!\n");
}

int readAction(int* action) {
    return scanf("%d", action) != 1;
}

int checkData(int data) {
    return data > 0;
}
