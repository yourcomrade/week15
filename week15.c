/*
 * Assignment 15.1
 * Student name: Hoang Minh Le
 * Student number: 511907
 * Class: ETI1V.IE
 */


/******************************************************************************
*                                                                             *
*   Program : Playing Cards - exercise program displaying a fill deck of      *
*             play cards (52 cards).                                          *
*                                                                             *
*   Programmer : Carlos Varma (coe01)                                         *
*   Updated : Erik Karstens (eka08) 11-1-2021                                 *
*                                                                             *
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


/******************************************************************************
*                                                                             *
*   N.B. The enumerated type list starts at 0 by default, if you want it to   *
*   start at a different number you must assign it to the constants yourself. *
*   The rest of the list will have an auto-incremented number starting from   *
*   the number that you have set. So TWO == 2, THREE == 3, etc...             *
*                                                                             *
******************************************************************************/

typedef enum CARDSUITE {DIAMONDS, CLUBS, HEARTS, SPADES} CardSuit;
typedef enum CARDNUMBER {TWO=2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE} CardNumber;

typedef struct PLAYCARD
{
    CardNumber number;
    CardSuit   color;
} PlayCard;

#define NR_CARDS_IN_DECK  52

typedef struct DECK
{
    PlayCard card[NR_CARDS_IN_DECK];
} Deck;


/******************************************************************************
*                                                                             *
* Function prototypes                                                         *
*                                                                             *
******************************************************************************/

void showPlayingCard(PlayCard card);
void fillDeck(Deck * p_cardDeck);
void showDeck(Deck * p_cardDeck);
void swapCards(PlayCard * p_card1, PlayCard * p_card2);
void shuffleDeck(Deck * p_cardDeck);


/******************************************************************************
*                                                                             *
*   Function : void showPlayingCard(PlayCard card)                            *
*                                                                             *
*   Parameters : PlayCard card - A struct containing a playing card that must *
*                                be displayed.                                *
*                                                                             *
*   Return type : none                                                        *
*                                                                             *
*   Description : A function to display the given playing card. Both values   *
*                 from the struct must be displayed.                          *
*                                                                             *
******************************************************************************/

void showPlayingCard(PlayCard card)
{
    char cardColor[10] = "";
    char cardValue[10] = "";

    switch (card.color)
    {
        case DIAMONDS: strcpy(cardColor, "Diamonds");
        break;

        case CLUBS: strcpy(cardColor, "Clubs");
        break;

        case HEARTS: strcpy(cardColor, "Hearts");
        break;

        case SPADES: strcpy(cardColor, "Spades");
        break;
    }

    switch (card.number)
    {
        case TWO:       strcpy(cardValue, " 2"); break;
        case THREE:     strcpy(cardValue, " 3"); break;
        case FOUR:      strcpy(cardValue, " 4"); break;
        case FIVE:      strcpy(cardValue, " 5"); break;
        case SIX:       strcpy(cardValue, " 6"); break;
        case SEVEN:     strcpy(cardValue, " 7"); break;
        case EIGHT:     strcpy(cardValue, " 8"); break;
        case NINE:      strcpy(cardValue, " 9"); break;
        case TEN:       strcpy(cardValue, "10"); break;
        case JACK:      strcpy(cardValue, "JACK"); break;
        case QUEEN:     strcpy(cardValue, "QUEEN"); break;
        case KING:      strcpy(cardValue, "KING"); break;
        case ACE:       strcpy(cardValue, "ACE"); break;
    }

    printf("The selected card has color : %s \t", cardColor);
    printf("It's value is : %s\n", cardValue);
}


/******************************************************************************
*                                                                             *
*   Function : void fillDeck(Deck * p_cardDeck)                               *
*                                                                             *
*   Parameters : Deck * p_cardDeck - A pointer to the deck that must be       *
*                                    filled.                                  *
*                                                                             *
*   Return type : none                                                        *
*                                                                             *
*   Description : A function to fill the individual play cards in a deck.     *
*                                                                             *
******************************************************************************/

void fillDeck(Deck * p_cardDeck)
{

    /* This part must be created by the student */
    int index=0;
    for(int i=DIAMONDS;i<=SPADES;i++)
    {
        for(int j=TWO;j<=ACE;j++)
        {
            p_cardDeck->card[index].color=i;
            p_cardDeck->card[index].number=j;
            index++;
        }
    }


}


/******************************************************************************
*                                                                             *
*   Function : void showDeck(Deck * p_cardDeck)                               *
*                                                                             *
*   Parameters : Deck * p_cardDeck - A pointer to the deck that must be       *
*                                    displayed.                               *
*                                                                             *
*   Return type : none                                                        *
*                                                                             *
*   Description : A function to display the cards in a deck.                  *
*                                                                             *
******************************************************************************/

void showDeck(Deck * p_cardDeck)
{

    /* This part must be created by the student */
    for(int i=0;i<52;i++)
    {
        showPlayingCard(p_cardDeck->card[i]);
    }

}


/******************************************************************************
*                                                                             *
*   Function : void swapCards(PlayCard * p_card1, PlayCard * p_card2)         *
*                                                                             *
*   Parameters : PlayCard * p_card1 - A pointer to the first card.            *
*                PlayCard * p_card2 - A pointer to the second card.           *
*                                                                             *
*   Return type : none                                                        *
*                                                                             *
*   Description : A function to swap two cards.                               *
*                                                                             *
******************************************************************************/

void swapCards(PlayCard * p_card1, PlayCard * p_card2)
{
    PlayCard temp = *p_card1;
    *p_card1 = *p_card2;
    *p_card2 = temp;
}


/******************************************************************************
*                                                                             *
*   Function : void shuffleDeck(Deck * p_cardDeck)                            *
*                                                                             *
*   Parameters : Deck * p_cardDeck - A pointer to the deck that must be       *
*                                    shuffled.                                *
*                                                                             *
*   Return type : none                                                        *
*                                                                             *
*   Description : A function to shuffle the cards in a deck.                  *
*                                                                             *
******************************************************************************/

void shuffleDeck(Deck * p_cardDeck)
{
    printf("After shuffling:\n\n\n");
    srand(time(NULL));
    for(int i=0;i<52;i++)
    {
        int r=i+(rand()%(52-i));//random integer
        swapCards(&p_cardDeck->card[i] ,&p_cardDeck->card[r]);
    }

    /* Optional: this part must be created by the student */

}


/******************************************************************************
*                                                                             *
*   Function : int main(void)                                                 *
*                                                                             *
*   Parameters : none                                                         *
*                                                                             *
*   Return type : int - 0 (zero) to terminate the process                     *
*                                                                             *
*   Description : The main routine of the Play Cards listing application      *
*                                                                             *
******************************************************************************/

int main()
{
    /* seed the pseudo-random number generator */
    srand(time(NULL));

    /* declare the deck of cards */
    Deck cardDeck;

    /* fill the deck of cards with unique cards */
    fillDeck(&cardDeck);

    /* show the deck of cards */
    showDeck(&cardDeck);

    // optional:

    /* shuffle the deck of cards */
    shuffleDeck(&cardDeck);

    /* show the shuffled deck of cards */
    showDeck(&cardDeck);
    system("pause");

    return 0;
}
