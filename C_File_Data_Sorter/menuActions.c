#include "menuActions.h"


void addMusic(const char* fileName) {

    FILE* file = fopen(fileName, "a");

    Music tmp = {};

    getchar();
    printf("Input music name: ");
    fgets(tmp.Name, LEN, stdin);

    printf("Input artist name: ");
    fgets(tmp.Artist, LEN, stdin);

    int temp = 0;
    while(temp == 0) {
        printf("Input music duration: ");
        if((scanf("%d", &tmp.Duration) == 1) && checkData(tmp.Duration)) {
            temp = 1;
        } else {
            printf("Invalid input. Please try again.\n");
            while(getchar() != '\n');
        }
    }
    temp = 0;
    while(temp == 0) {
        printf("Input music rank: ");
        if((scanf("%d", &tmp.Rank) == 1) && checkData(tmp.Rank)) {
            temp = 1;
        } else {
            printf("Invalid input. Please try again.\n");
            while(getchar() != '\n');
        }
    }
    fputs(tmp.Name, file);
    fputs(tmp.Artist, file);
    fprintf(file, "%d\n",tmp.Duration);
    fprintf(file, "%d\n",tmp.Rank);
    fclose(file);
    printMusicAdded();
    printNextAction();
}

void listMusic(const char* fileName) {
    FILE* file = fopen(fileName, "r");
    int structCount = countLines(file) / FOUR;
    if (structCount == 0) {

    } else {
        for (int i = 0; i < structCount; i++) {
            char tmp[LEN];
            fgets(tmp, LEN, file);
            printf("Music name: %s", tmp);
            fgets(tmp, LEN, file);
            printf("Artist: %s", tmp);
            fgets(tmp, LEN, file);
            printf("Duration: %s", tmp);
            fgets(tmp, LEN, file);
            printf("Rank: %s\n", tmp);
        }
    }
    fclose(file);
    printNextAction();
}

void deleteMusicByArtist(const char* fileName, const char* artistName) {
    FILE* file = fopen(fileName, "r");

    int structCount = countLines(file) / FOUR;
    int flag = 0;


    Music* arr = createMusicArr(structCount);


    for (int i = 0; i < structCount; i++) {
        fgets(arr[i].Name, LEN, file);
        fgets(arr[i].Artist, LEN, file);
        fscanf(file, "%d", &arr[i].Duration);
        fscanf(file, "%d", &(arr + i)->Rank);
        if (strcmp(arr[i].Artist, artistName) == 0)
            flag = 1;
    }
    fclose(file);
    if (!flag) {
        printArtistNotFound();
    } else {
        for (int i = 0; i < structCount; i++) {
            if (strcmp(arr[i].Artist, artistName) == 0) {
                for (int k = i; k < structCount ; k++) {
                    arr[k] = arr[k + 1];
                    structCount--;
                    i--;
                }
            }
        }

        FILE* fileO = fopen(fileName, "w");

        for (int i = 0; i < structCount; i++) {
            fputs(arr[i].Name, fileO);
            fputs(arr[i].Artist, fileO);
            fprintf(fileO, "%d\n", arr[i].Duration);
            fprintf(fileO, "%d\n", arr[i].Rank);
        }
        fclose(fileO);
        printf("Music deleted!\n");
    }
    free(arr);
    printNextAction();
}



void sortMusicByName(const char* fileName) {
    FILE* file = fopen(fileName, "r");

    int structCount = countLines(file) / FOUR;

    Music* arr = createMusicArr(structCount);

    for (int i = 0; i < structCount; i++) {
        fgets(arr[i].Name, LEN, file);
        fgets(arr[i].Artist, LEN, file);
        fscanf(file, "%d\n", &((arr) + i)->Duration);
        fscanf(file, "%d\n", &((arr) + i)->Rank);
    }
    fclose(file);
    for (int i = 0; i < structCount; i++) {
        for (int j = i; j < structCount - 1 - i; j++) {
            if (strcmp(arr[j].Name, arr[j + 1].Name) > 0) {
                swap(arr + j, arr + j + 1);
            }
        }
    }


    FILE* fileO = fopen(fileName, "w");

    for (int i = 0; i < structCount; i++) {
        fputs(arr[i].Name, fileO);
        fputs(arr[i].Artist, fileO);
        fprintf(fileO, "%d\n", arr[i].Duration);
        fprintf(fileO, "%d\n", arr[i].Rank);
    }
    fclose(fileO);
    free(arr);
    printMusicSortedByName();
    printNextAction();
}


int countLines(FILE* file) {
    rewind(file);
    int line_count = 0;
    char c;

    do {
        c = getc(file);

        if (c == '\n')
            line_count++;
    }
    while (c != EOF);
    rewind(file);
    c = getc(file);

    if (c != EOF && line_count == 0)
        line_count++;
    rewind(file);
    return line_count;
}

void swap(Music* p1, Music* p2) {
    Music temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

Music* createMusicArr(int n) {
    return (Music*)calloc(n, sizeof(Music));
}
