#ifndef MENUACTIONS_H
#define MENUACTIONS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "io.h"
#include "myMusicConst.h"


typedef struct Music {
    char Name[LEN];
    char Artist[LEN];
    int Duration;
    int Rank;
} Music;

void addMusic(const char* fileName);
void listMusic(const char* fileName);
void deleteMusicByArtist(const char* fileName, const char* artistName);
void sortMusicByName(const char* fileName);
int countLines(FILE* file) ;
int checkCondition(int action);
Music* createMusicArr(int n);
void swap(Music* p1, Music* p2);
void removeMusicFromList(int structCount, Music* arr, const char* artistName);

#endif // MENUACTIONS_H
