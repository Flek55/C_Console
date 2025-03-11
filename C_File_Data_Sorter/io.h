#ifndef IO_H
#define IO_H
#include <stdio.h>
#include <string.h>

void inputName(char* artistName);
void reenterNumber();
void showMenu();
int readAction(int* action);
void printArtistNotFound();
int checkData(int data);
void printMusicAdded();
void printMusicSortedByName();
int getFilePath(char* filePath);
void printNextAction();

#endif // IO_H
