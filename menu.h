
#ifndef MENU_H
#define MENU_H
#include <stdbool.h>


typedef struct 
{ 
    char name[20];
    int cardNumber;
} Card;


extern Card *cards;
extern int cardCount;


void PrintMenu();
void RemoteOpenDoor();
void ListAllCards();
void AddAndRemoveCards();
void ExittheProgram();
void ScanFakeCards();



#endif