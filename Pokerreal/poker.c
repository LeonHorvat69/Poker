#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#include "structs.h"
#include "functions.h"

#define MAX_HAND_SIZE 8

int deckIndex = 0;
int main() {
	CARD* card = NULL;
	CARD* allCardsInOrder[52] = { NULL };
	CARD* deck[52] = { NULL };

	card = dynamicSpace();
	assignRank(card);
	assignSuit(card);

	PLAYER_INFO playerInfo;
	PLAYER_INFO* playerInfoP = &playerInfo;
	STATISTICS statistics;
	STATISTICS* statisticsP = &statistics;


	for (int i = 0; i < 52; i++) {
		allCardsInOrder[i] = (card + i);
		playerInfo.deck[i] = (card + i);
	}
	

	playerInfo.cardsPlayed = 0;
	playerInfo.score = 0;
	playerInfo.statistics = statisticsP;
	statistics.stage = 1;
	statistics.round = 1;

	int discards = 3;
	shuffleDeck(playerInfoP->deck, allCardsInOrder);
	int startRound = 1;
	while (startRound == 1) {
		playerInfo.discards = discards;
		
		for (int i = 0; i < MAX_HAND_SIZE; i++) {
			playerInfoP->hand[i] = playerInfoP->deck[deckIndex];
			deckIndex++;
		}
		if (deckIndex > 40) {
			deckIndex = 0;
			shuffleDeck(playerInfoP->deck, allCardsInOrder);
		}
		
		printGame(playerInfoP, 0);
		playHand(playerInfoP);
		scoreHand(playerInfoP);

		if (statistics.round == 3) {



			statistics.round = 0;
			statistics.stage++;
		}
		statistics.round++;

		
	}





	



	return 0;
}

