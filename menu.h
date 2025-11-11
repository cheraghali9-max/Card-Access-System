
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


void PrintMenu(void);
void RemoteOpenDoor(void);
void ListAllCards(void);
void AddAndRemoveCards(void);
void ExittheProgram(void);
void ScanFakeCards(void);

#endif