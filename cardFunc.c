// cardFunc.c
/******************************************************************************/
/* PROGRAMMER:  Luis M. Herrnsdorf  
   ID: 5481644
   CLASS:       COP4338 U03   TT 7:50
   INSTRUCTOR:  William Feild
   ASSIGNMENT:  #3.   DUE Thursday 2/25
*/
/*DESCRIPTION: functions to most common manipulation of a deck of cards.
* create a deck, display a deck, shuffle a deck, deal a specific number of cards
* to specific number of players, and display hands. It also validate the user 
* input of cards and players. 
*/
/* 
  CERTIFICATION: I hereby certify that this collective work is my own and none
                 of it is the work of any other person or entity.
                    Luis Herrnsdorf
*/
/******************************************************************************/
#include "cardLib.h" //* definition for types and function prototype */
/******************************************************************************/

//Declaration of constants
/* Used for card's suit symbols */
const char suitType[suitsInDeck][suitsInDeck] = {{0xe2, 0x99, 0xa2, 0},
 {0xe2, 0x99, 0xa1, 0}, {0xe2, 0x99, 0xa4, 0}, {0xe2, 0x99, 0xa7, 0}};

/* Used to replace highest values on a card */
const char highCards[] = {'J', 'Q', 'K'};

/* Used to unset delt cards from deck */
const int NOCARDS = -1;
// End Declaration of constants

/******************************************************************************/

/*
* Function: verifyGame
* ---------------------
* Verify that the inputs are within the range
*
* numCards: int that sets the number of cards to be used in the game
* numPlayers: int that sets the number of players in the game
* return: False if numCards and numPlayers are not between 1 & 13 or
* if numCards * numPlayers is grater than 52.  Returns TRUE otherwise.
*
* side sffects: none.
*/
int verifyGame(int numCards, int numPlayers) {
   if ((numCards < MINCARD || numCards > cardsInSuit) || 
       (numPlayers < MINHAND || numPlayers > cardsInSuit)) {
      printf("%s\n", "The number of cards & players must be between 1 & 13");
      return FALSE;
   } else if (numCards * numPlayers > cardsInDeck) {
      printf("%s", "Your combination of cards & players exceeded");
      printf("%s\n", " the number of cards available");
      return FALSE;
   } else {
      return TRUE;
   }
}

/******************************************************************************/

/*
* Function: makeDeck
* -------------------
* Initialize the structure array of 53 cards.  Each card is a structure of two
* members value and suit.
* 
* deck: the array of 52 structures of type card.
* return: void
* side effects: This function modifies the array being passed by initializing 
* the members of the structure.
*/
void makeDeck(struct card deck[]) {
    int i = 0, j = 0, cardValue = 1, deckValue = cardsInSuit;

    for (; i < suitsInDeck; i++) {
         for (; j < deckValue; j++) {
            deck[j].value = cardValue;
            deck[j].suit = i;
            cardValue++;
         }
      deckValue += cardsInSuit;
      cardValue = 1;
   }
}

/******************************************************************************/

/*
* Function: shuffleDeck
* ----------------------
* Traversing the array of cards swapping the card at each position by another 
* card at a random position. 
*
* deck:  array of structures of type card.
* return: void
* side effects: This method modifies the array being passed.
*/
void shuffleDeck(struct card deck[]) {
   int i = 0, random = 0;
   struct card temp;
   time_t ranTime;
   srand((unsigned) time(&ranTime));

   for( ; i < cardsInDeck; i++)
   {
      random = rand() % 51;
      temp = deck[i];
      deck[i] = deck[random];
      deck[random] = temp;
   }
}

/******************************************************************************/

/*
* Function: printDeck
* --------------------
* Displays the deck of cards. It replaces the actual numeric value of the high 
* value cards (11, 12, 13) by their game symbol (J, Q, K) respectively.
*
* deck: an array of structures of type card.
* return: void 
* side effects: none
*/
void printDeck(struct card deck[]) {
   int i = 0, j = 0, cardValue = cardsInSuit;

   for (; i < suitsInDeck; i++) {
      for (; j < cardValue; j++) {
         if (deck[j].value >= JOKER)
            // for the three highest values, print the symbol
            printf("%2c",highCards[deck[j].value - JOKER]);
         else
            printf("%2d",deck[j].value);
         // print the suit symbol from suitType array
         printf("%s ", suitType[deck[j].suit]);
      }
   cardValue += cardsInSuit;
   printf("\n");
   }
}

/******************************************************************************/

/*
* Function: dealHand
* -------------------
* Distribute the cards of the deck to the players determined numCards, 
* numPlayers.  The cards are being saved to a 2D array. At the same time the 
* dealt cards are being set to '-1' in the deck to represent the card is not 
* in the deck anymore.
* 
* numCards: int that sets the number of cards to be used in the game.
* numPlayers: int that sets the number of players in the game.
* deck: an array of structures of type card.
* hands: 2D array to save the dealt cards.
* return: void
* side effects: It modifies the 2D array passed as parameter.
*/
void dealHand(int numCards, int numPlayers, struct card deck[], 
              struct card hands[][numCards]) {
   int i = 0, j = 0, r = 0;
   for (; i < numPlayers; i++) {
      for (j = 0; j < numCards; j++) {
         hands[i][j] = deck[r];
         deck[r].value = NOCARDS; // set dealt card to -1
         deck[r].suit = NOCARDS;
         r++;
      }
   }
}

/******************************************************************************/

/*
* Function: printHand
* --------------------
* This function displays the cards of each player. It replaces the  
* actual numeric value of the faces 1, 11, 12, and 13 but their symbol
* A, J, Q, and K respectively. This is done for display purposes only. 
* 
* numCards: int that sets the number of cards to be used in the game.
* numPlayers: int that sets the number of players in the game.
* hands: 2D array to display the dealt cards.
* return: void 
* side effects: None
*/
void printHand(int numCards, int numPlayers, 
               struct card hands[][numCards]) {
   int i = 1, j = 0, r = 0;

   for (; i <= numPlayers; i++) {
      if (i < JOKER - 1)
         printf("%s%d\t", "Player0",i);
      else
         printf("%s%d\t", "Player",i);
      for (j = 0; j < numCards; j++) {
         if (hands[r][j].value >= JOKER) {
            // for the three highest values, print the symbol
            printf("%2c",highCards[hands[r][j].value - JOKER]);
         }
         else {
            printf("%2d",hands[r][j].value);
         }
         // print the suit symbol from suitType array
         printf("%s ", suitType[hands[r][j].suit]);
      }
      r++;
      printf("\n");
   }
}
