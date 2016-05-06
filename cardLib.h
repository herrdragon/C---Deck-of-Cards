// cardLib.h
/******************************************************************************/
/* PROGRAMMER:  Luis M. Herrnsdorf  
   ID: 5481644
   CLASS:       COP4338 U03   TT 7:50
   INSTRUCTOR:  William Feild
   ASSIGNMENT:  #3.   DUE Thursday 2/25
*/
/*DESCRIPTION: header file contains common constants, declarations, prototypes 
* and type declarations that are used by deckOfCards.c and cardFunc.c.
*/
/* 
  CERTIFICATION: I hereby certify that this collective work is my own and none
                 of it is the work of any other person or entity.
                    Luis Herrnsdorf
*/
/******************************************************************************/

#include <stdio.h>
#include <stdlib.h>  /* for atoi() & rand()*/
#include <time.h>    /* for time() */

#define cardsInDeck 52 //used to check total cards in deck
#define cardsInSuit 13 //used to control max # of cards
#define JOKER       11 //used to control highest cards
#define MINCARD		 1 //used to control min # of cards
#define MINHAND 	 1 //used to control min # of players
#define suitsInDeck  4 //used to control min # of suits used
#define NOERRORS     0 //no errors found
#define FALSE        0 //used to return 0 from functions
#define TRUE         1 //used to return 1 from functions

// especify the structure a a card
struct card {int value; int suit;};

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
int verifyGame(int numCards, int numPlayers);

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
void makeDeck(struct card deck[]);

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
void shuffleDeck(struct card deck[]);

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
void printDeck(struct card deck[]);

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
              struct card hands[][numCards]);

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
void printHand(int numCards, int numPlayers, struct card hands[][numCards]);
