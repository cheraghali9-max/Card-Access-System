
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "menu.h"
#include "saveinput.h"

Card *cards = NULL;
int cardCount = 0;

void addCard();
void removeCard();

void PrintMenu()
{
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
        {
            RemoteOpenDoor();
            int enterCard;
            if (!GetInputInt("Enter a Card Number:", &enterCard))
                break;

            bool foundCard = false;
            for (int i = 0; i < cardCount; i++)
            {
                if (cards[i].cardNumber == enterCard)
                {

                    printf("%d. Name: %s | Card Number: %d\n", i + 1, cards[i].name, cards[i].cardNumber);

                    foundCard = true;
                    printf("Green Door opened\n");
                    return;
                }
            }

            if (!foundCard)
            {
                printf("RED: Card not foundn\n");

                break;
            }
            else
            {
                printf("Please scan a card ");
            }
            break;

        case 2:
            ListAllCards();
            if (cardCount == 0)
            {

                printf("No card found in the system\n");
                break;
            }
            else
            {
                printf("List of Cards\n");
                for (int i = 0; i < cardCount; i++)
                {
                    printf("%d.Name:%s | | | Card Number:%d\n", i + 1, cards[i].name, cards[i].cardNumber);
                }
            }
        }

        case 3:

            int subMenu;
            while (true)
            {
                printf("1: Add a new card in the system\n");
                printf("2: Remove a card from system\n");
                printf("3: Return to the main menu\n");

                if (!GetInputInt("Select an option: ", &subMenu))
                    continue;

                if (subMenu == 1)
                {
                    addCard();
                }
                else if (subMenu == 2)
                {
                    removeCard();
                }
                else if (subMenu == 3)
                {
                    break;
                }
                else
                {
                    printf("Invalid Option");
                }
            }
            break;

        case 4:
            ExittheProgram();
            printf("Exitting the program........");
            return;
            break;

        case 5:
        {
            int enterCardNumber;

            if (!GetInputInt("Enter card number to check::", &enterCardNumber))
            {
                printf("Please enter a valid number:\n");
                break;
            }

            bool foundFakeCard = false;
            for (int i = 0; i < cardCount; i++)
            {
                if (cards[i].cardNumber == enterCardNumber)
                {
                    printf("The card number exist in the systemn::");
                    foundFakeCard = true;
                    break;
                }
            }
            if (!foundFakeCard)
            {
                printf("FAKE CARD. No such card in system");
                break;
            default:
                printf("ERROR: select correctly\n");
                break;
            }
        }
        }
    }
}

//====================//
void addCard()
{
    char name[20];
    int cardNum;

    if (GetInput("Enter card owner name: ", name, sizeof(name)) != INPUT_RESULT_OK)
    {
        printf("Invalid name.\n");
        return;
    }

    if (!GetInputInt("Enter card number: ", &cardNum))
        return;
    {

        for (int i = 0; i < cardCount; i++)
        {
            if (cards[i].cardNumber == cardNum)
            {
                printf("The Card already exist in the system\n");
                return;
            }
        }
    }

    Card *temp = realloc(cards, (cardCount + 1) * sizeof(Card));
    if (temp == NULL)
    {
        printf("ERROR: Failed to allocate memory!");
        return;
    }

    cards = temp;
    strcpy(cards[cardCount].name, name);
    cards[cardCount].cardNumber = cardNum;
    cardCount++;

    printf("Card added to the system: %s %d\n", name, cardNum);
}

//===============///
void removeCard()
{
    if (cardCount == 0)
    {
        printf("No cards to remove.");
        return;
    }

    int cardNumber;
    if (!GetInputInt("Enter card number to remove: ", &cardNumber))
        return;

    int foundCard = -1;
    for (int i = 0; i < cardCount; i++)
    {
        if (cards[i].cardNumber == cardNumber)
        {
            foundCard = i;
            break;
        }
    }

    if (foundCard == -1)
    {
        printf("Card not found:\n");
        return;
    }

    for (int i = foundCard; i < cardCount - 1; i++)
    {
        cards[i] = cards[i + 1];
    }
    cardCount--;

    if (cardCount == 0)
    {
        free(cards);
        cards = NULL;
    }
    else
    {
        Card *temp = realloc(cards, cardCount * sizeof(Card));
        if (temp != NULL)
        {
            cards = temp;
        }
    }

    printf("Card number %d removed from the system.\n", cardNumber);
}

void RemoteOpenDoor(void)
{
    printf("Remote open door\n");
}
void ListAllCards(void)
{
    printf("List all cards\n");
}
void AddAndRemoveCards(void)
{
    printf("Add or remove cards\n");
}
void ExittheProgram(void)
{
    printf("Exit program\n");
}
void ScanFakeCards(void)
{
    printf("Check for fake cards\n");
}
