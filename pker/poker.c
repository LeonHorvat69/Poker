#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

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
	statistics.round = 1;

	shuffleDeck(playerInfoP->deck, allCardsInOrder);
	int startRound = 1;




	int choice = printMenu();
	while (choice != 4) {
		if (choice == 2) {
			printGameInstructions();
			choice = printMenu();
		}
		if (choice == 3) {
			int highScore = 0;
			FILE* fp = fopen("score.txt", "r");
			if (fscanf(fp, "%d", &highScore) == NULL) {
				perror("ERROR: ");
				exit(-1);

			}
			printf("High score is %d", highScore);
			Sleep(5000);
			fclose(fp);
		}


		while (choice == 1) {
			playerInfo.discards = 3;

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
				saveScore(playerInfo.score);
				playerInfo.score = 0;
				break;
			}
			statistics.round++;
		}
		choice = printMenu();
	}

	free(card);
	card = NULL;
	return 0;
}

