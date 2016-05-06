//deckOfCards.c
/******************************************************************************/
#include <stdio.h>
#include "cardlib.h"  /* definition for types and function prototype */
/******************************************************************************/
/* DOCUMENTATION */

/* PROGRAMMER:  Miguel Herrnsdorf  */

/* DESCRIPTION: This program generates and display of a deck of cards and of 
hands of cards.  The numbers of cards & players are entered via the command-line
arguments.  Input will be the number of cards/hand and the number of hands 
(in this order and separated by one space).  The number of cards & hands are 
from 1 to 13.  The program will display the original deck, the shuffled deck of 
cards and each of the hands of cards. */

/* SPECIFICATIONS: Write algorithms and programs to generate a display of a deck 
of cards and of hands of cards. */

/* INPUT: Accept input via the command-line arguments. Validate command-line 
input. Input will be the number of cards/hand and the number of hands (players).
*/

/* COMPILATION: gcc deckOfCards.c cardFunc.c -o playcards.out */

/* EXECUTE: ./playcards.out number1 number2 */

/* 
  CERTIFICATION: I hereby certify that this collective work is my own and none
                 of it is the work of any other person or entity.
                    Luis Herrnsdorf
*/

/* START PSEUDO CODE
int main(int argc, char *argv[]) {
	convert strings argv[1] to integers
	convert strings argv[2] to integers

	if (inputsAreValid(argv[1], argv[2])){

		struct arrayOfCards;
		struct arrayOfHands;
		
		printf("%s\n","New Deck");
		makeDeck(arrayOfCards);
		printDeck(arrayOfCards);
		
		printf("%s\n","Shuffled Deck");
		shuffleDeck(arrayOfCards);
		printDeck(arrayOfCards);
		
		printf("%s\n","Dealt Hands");
		dealHand(argv[1], argv[2], deck, arrayOfHands);
		printHand(argv[1], argv[2], arrayOfCards, arrayOfHands);
	} 
   return 0;
}
 END PSEUDO CODE */
/******************************************************************************/
int main(int argc, char *argv[]) {
	// declare constants
	const int numCards = atoi(argv[1]); /* convert strings to integers */
	const int numPlayers = atoi(argv[2]);

	if (verifyGame(numCards, numPlayers)){ /* validate user input */

		struct card deck[cardsInDeck]; /* create array of cards */

		//create a 2D array of hands by cards
		struct card hands[numPlayers][numCards]; 
		
		printf("%s\n","New Deck");
		makeDeck(deck);
		printDeck(deck);
		
		printf("%s\n","Shuffled Deck");
		shuffleDeck(deck);
		printDeck(deck);
		
		printf("%s\n","Dealt Hands");
		dealHand(numCards, numPlayers, deck, hands);
		printHand(numCards, numPlayers, hands);

		int lastCard = numCards * numPlayers;
		printf("%s", "Last dealt card of the shuffled deck ");
		printf("%s%d%s\n", "was the ", lastCard, "th card");
	} 
	else {
		; // future use
	}
   return NOERRORS;
}
