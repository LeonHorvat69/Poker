#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#include "structs.h"
#include "functionDef.h"

#define MAX_HAND_SIZE 8

int deckIndex = 0;
int main() {
	int score = 0;
	int discardStartCount = 3;
	int numOfCardsPlayed = 0;
	int* numOfCardsPlayedP = NULL;
	numOfCardsPlayedP = &numOfCardsPlayed;

	CARD* card = NULL;
	CARD* allCardsInOrder[52] = { NULL };
	CARD* deck[52] = { NULL };
	CARD* hand[MAX_HAND_SIZE];
	CARD* playedHand[5] = { NULL };

	card = dynamicSpace();
	assignRank(card);
	assignSuit(card);

	for (int i = 0; i < 52; i++) {
		allCardsInOrder[i] = (card + i);
		deck[i] = (card + i);
	}

	int startRound = 1;
	while (startRound == 1) {
		shuffleDeck(deck, allCardsInOrder);
		for (int i = 0; i < MAX_HAND_SIZE; i++) {
			hand[i] = deck[deckIndex];
			deckIndex++;
		}

		printHand(hand, discardStartCount, score);
		playHand(hand, numOfCardsPlayedP, playedHand, deck, score);
		score = scoreHand(playedHand, numOfCardsPlayed, score);
	}


	
	

	


	
	return 0;
}

