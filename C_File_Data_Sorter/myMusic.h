#ifndef MYMUSIC_H
#define MYMUSIC_H
#include "myMusicConst.h"
#include "menuActions.h"
#include "io.h"
#include <stdio.h>

int calculateResult();
void clearInputBuffer();
void doProgramLogic (int action, char* fileName);
void switchFunc(enum Action action, const char* fileName);



#endif // MYMUSIC_H
