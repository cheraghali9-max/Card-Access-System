
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "menu.h"
#include "saveinput.h"


Card *cards = 0;
int cardCount = 0;



void PrintMenu() {
    char choice[6];
    int select;
    
    while (true)
    {
        printf("\n=========Amin Menu========\n");
    printf(" 1: Remote Open Door\n");
    printf(" 2: Listing All The Cards\n");
    printf(" 3: Remove or Add a  Card\n");
    printf(" 4: Exit\n");
    printf(" 5: Test and Check Fake Cards\n");
    printf("***************************************\n");

    if (!GetInputInt("Select a Meu List\n", &select))
    continue;

   

    switch (select)
    {
    case 1:
        RemoteOpenDoor();
        printf("Green: Door Opened\n");
        break;

    case 2:
        ListAllCards();

         printf("List a Card here\n");
        break;
    
    case 3:
        AddAndRemoveCards();
        break;
    
    case 4:
        ExittheProgram();
        break;
    
    case 5:
        ScanFakeCards();
        break;

    
    default:
        printf("ERROR: Select correctly\n");
    }
    
    }

    
}



