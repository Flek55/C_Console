#include "myMusic.h"


int calculateResult() {
    enum ProgramStatus status = CORRECT;
    char fileName[LEN] = "Music.txt";
    int action = 0;
    doProgramLogic(action, fileName);
    return status;
}

void doProgramLogic(int action, char fileName[LEN]) {
    while (action != EXIT) {
        showMenu();
        if (scanf("%d", &action) != 1) {
            reenterNumber();
            getchar();
            clearInputBuffer();
        }
        printNextAction();
        switchFunc(action, fileName);
    }
}

void switchFunc(enum Action action, const char* fileName) {
    switch (action) {
    case ADD:
        addMusic(fileName);
        break;
    case LIST:
        listMusic(fileName);
        break;
    case DELETE:
        char artistName[LEN];
        inputName(artistName);
        deleteMusicByArtist(fileName, artistName);
        break;
    case SORT:
        sortMusicByName(fileName);
        break;
    default:
        break;
    }
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
