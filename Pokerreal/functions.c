#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "structs.h"
#include "functions.h"
#define HEART "\3"
#define DIAMOND "\4"
#define CLUB "\5"
#define SPADE "\6"

#define ANSI_COLOR_RESET   "\x1b[0m"
#define DIAMOND_COLOR_DARK_RED     "\x1b[31m"
#define CLUB_COLOR_DARK_WHITE     "\x1b[37m"
#define SPADE_COLOR_BRIGHT_WHITE     "\x1b[90m"
#define HEART_COLOR_BRIGHT_RED     "\x1b[91m"

const int cardAmount = 52;
const int handSize = 8;
extern int deckIndex;

// ASSIGN CARDS AND SPACE
CARD* dynamicSpace() {
	CARD* card = (CARD*)malloc(cardAmount * sizeof(CARD));
	if (card == NULL) {
		return NULL;
	}
	return card;
}
void assignRank(CARD* card) {
	//Give rank to all 52 cards
	int ranks = 1;
	for (int i = 0; i < cardAmount; i++) {
		(card + i)->rank = ranks;
		if (ranks == 12) {
			ranks = 0;
		}
		ranks++;
	}
}
void assignSuit(CARD* card) {
	//Give one of four suits to all cards
	char(*a[4]) = { HEART, DIAMOND, CLUB, SPADE };
	int j = 0;
	for (int i = 0; i < cardAmount; i++) {
		strcpy((card + i)->suit, a[j]);
		if ((i + 1) % 13 == 0) {
			j++;
		}
	}
}
void shuffleDeck(CARD* deck[], CARD* allCardsInOrder[]) {
	srand((unsigned)time(NULL));
	int randCard = 0;
	int randArray[52] = { 0 };

	for (int i = 0; i < 52; i++)
		randArray[i] = i;
	for (int i = 0; i < 52; i++) {
		int randNum = rand() % 52;
		if (randArray[randNum] == -1) {
			i--;
			continue;
		}
		randCard = randArray[randNum];
		deck[i] = allCardsInOrder[randCard];
		randArray[randNum] = -1;
	}

}


// PRINT HAND
void printHand(const CARD* hand[], const int discards, const int score) {
	if (score != 0) {
		Sleep(5000);
	}
	system("cls");
	printInstructions();
	printf("Score  %d\n", score);
	printf("Discards  %d\n", discards);
	for (int i = 0; i < handSize; i++) {
		if (strcmp(hand[i]->suit, HEART) == 0) {
			setCardCollor(hand[i], 1);
		}
		else if (strcmp(hand[i]->suit, DIAMOND) == 0) {
			setCardCollor(hand[i], 2);
		}
		else if (strcmp(hand[i]->suit, CLUB) == 0) {
			setCardCollor(hand[i], 3);
		}
		else if (strcmp(hand[i]->suit, SPADE) == 0) {
			setCardCollor(hand[i], 4);
		}
	}

	putchar('\n');
	for (int i = 0; i < handSize; i++) {
		printf("%d.     ", i + 1);
	}
	printf("  %d. end round\n", 0);
}
void printInstructions() {
	printf("Poker hands\t\t\tBonus\n");
	printf("Royal Flush\t   100 X 8\t\t\t\n");
	printf("Four of a Kind\t   60 X 7\t\t\t\n");
	printf("Full House\t   40 X 4\t\t\t\n");
	printf("Flush\t\t   35 X 4\t\t\t\n");
	printf("Straight\t   30 X 4\t\t\t\n");
	printf("Three of a Kind\t   30 X 3\t\t\t\n");
	printf("Two pair\t   20 X 2\t\t\t\n");
	printf("Pair\t\t   10 X 2\t\t\t\n");
	printf("High Card\t   5 X 1\t\t\t\n");
	printf("\n\n");
}
void printCard(const int numOfCardsPlayed, CARD* playedHand[]) {
	sortPlayedHand(playedHand, numOfCardsPlayed);

	for (int i = 0; i < numOfCardsPlayed; i++) {
		if (strcmp(playedHand[i]->suit, HEART) == 0) {
			setCardCollor(playedHand[i], 1);
		}
		else if (strcmp(playedHand[i]->suit, DIAMOND) == 0) {
			setCardCollor(playedHand[i], 2);
		}
		else if (strcmp(playedHand[i]->suit, CLUB) == 0) {
			setCardCollor(playedHand[i], 3);
		}
		else if (strcmp(playedHand[i]->suit, SPADE) == 0) {
			setCardCollor(playedHand[i], 4);
		}
	}
}
void setCardCollor(const CARD* hand, const int color) {
	switch (color) {
	case 1: if (hand->rank < 10) {
		printf(HEART_COLOR_BRIGHT_RED     "%d%s     ", hand->rank, hand->suit);
	}
		  else if (hand->rank == 10) {
		printf(HEART_COLOR_BRIGHT_RED     "%c%s     ", 'J', hand->suit);
	}
		  else if (hand->rank == 11) {
		printf(HEART_COLOR_BRIGHT_RED     "%c%s     ", 'Q', hand->suit);
	}
		  else if (hand->rank == 12) {
		printf(HEART_COLOR_BRIGHT_RED     "%c%s     ", 'K', hand->suit);
	}
		  printf(ANSI_COLOR_RESET);
		  return;



	case 2: if (hand->rank < 10) {
		printf(DIAMOND_COLOR_DARK_RED     "%d%s     ", hand->rank, hand->suit);
	}
		  else if (hand->rank == 10) {
		printf(DIAMOND_COLOR_DARK_RED     "%c%s     ", 'J', hand->suit);
	}
		  else if (hand->rank == 11) {
		printf(DIAMOND_COLOR_DARK_RED     "%c%s     ", 'Q', hand->suit);
	}
		  else if (hand->rank == 12) {
		printf(DIAMOND_COLOR_DARK_RED     "%c%s     ", 'K', hand->suit);
	}
		  printf(ANSI_COLOR_RESET);
		  return;



	case 3: if (hand->rank < 10) {
		printf(CLUB_COLOR_DARK_WHITE     "%d%s     ", hand->rank, hand->suit);
	}
		  else if (hand->rank == 10) {
		printf(CLUB_COLOR_DARK_WHITE     "%c%s     ", 'J', hand->suit);
	}
		  else if (hand->rank == 11) {
		printf(CLUB_COLOR_DARK_WHITE     "%c%s     ", 'Q', hand->suit);
	}
		  else if (hand->rank == 12) {
		printf(CLUB_COLOR_DARK_WHITE     "%c%s     ", 'K', hand->suit);
	}
		  printf(ANSI_COLOR_RESET);
		  return;


	case 4: if (hand->rank < 10) {
		printf(SPADE_COLOR_BRIGHT_WHITE     "%d%s     ", hand->rank, hand->suit);
	}
		  else if (hand->rank == 10) {
		printf(SPADE_COLOR_BRIGHT_WHITE     "%c%s     ", 'J', hand->suit);
	}
		  else if (hand->rank == 11) {
		printf(SPADE_COLOR_BRIGHT_WHITE     "%c%s     ", 'Q', hand->suit);
	}
		  else if (hand->rank == 12) {
		printf(SPADE_COLOR_BRIGHT_WHITE     "%c%s     ", 'K', hand->suit);
	}
		  printf(ANSI_COLOR_RESET);
		  return;
	}
}


// PLAYING HAND
void playHand(CARD* hand[], int* cardsPlayed, CARD* playedHand[], const CARD* deck[], const int score) {
	int numOfCardsPlayed = 0;
	int input = 0;
	int discards = 3;
	int check = 0;
	char keyInput[50];
	do {
	start: {
		do {
			printf("Input cards to play: ");
			check = fgets(keyInput, 40, stdin);
			if (keyInput[0] == '0') {
				input = 0;
				break;
			}
			input = atoi(keyInput);
			printf("\n");
			if (input == NULL || check == NULL) {
				memset(keyInput, '\0', 20);
				goto start;
			}
		} while (input < -8 || input > 8); }


	if (input == 0)
		break;
	else if (input < 0) { //used for discarding cards
		if (discards == 0) {
			printf("\n Used all discards!!!\n");
			continue;
		}
		hand[(input * -1) - 1] = deck[deckIndex];
		deckIndex++;
		discards--;
		printHand(hand, discards, score);
		continue;

	}

	for (int i = 0; i < numOfCardsPlayed; i++) {
		if (playedHand[i]->rank == hand[input - 1]->rank &&
			playedHand[i]->suit == hand[input - 1]->suit) {
			goto start; //Ako je karta vec u ruci iskoristena ponovo upisi input
		}
	}

	playedHand[numOfCardsPlayed] = hand[input - 1];
	numOfCardsPlayed++;
	//playedHand su karte koje se igraju i uzimaju se iz arraya hand sa indexom input (input - odabrana karta)
	} while (numOfCardsPlayed < 5);
	*cardsPlayed = numOfCardsPlayed;

	printCard(numOfCardsPlayed, playedHand);


}
void sortPlayedHand(CARD* playedHand[], const int numOfCardsPlayed) {
	int arraySorted = 0;
	int count = 0;
	while (arraySorted == 0) {
		for (int i = 0; i < numOfCardsPlayed - 1; i++) {
			if (playedHand[i]->rank > playedHand[i + 1]->rank) {
				arraySwitchPlace(playedHand, i, i + 1);
				count++;
			}
		}
		if (count == 0)
			arraySorted = 1;

		count = 0;
	}
}
void arraySwitchPlace(CARD* array[], int indexA, int indexB) {
	CARD* temp = array[indexA];
	array[indexA] = array[indexB];
	array[indexB] = temp;
}


// SCORING
int scoreHand(const CARD* playedHand[], const int numOfCardsPlayed, int score) {
	int cardChips = 0;  //Chips earned from cards rank
	int handTypeChips = calculateChips(playedHand, numOfCardsPlayed, &cardChips); //Chips earned from hand type
	int mult = calculateMult(playedHand, numOfCardsPlayed);
	printf("\n\n");
	printf("\tChips  X  Multiplier   Chip Bonus\n");
	printf("          %d     ", handTypeChips);
	printf("      %d ", mult);
	printf("\t  +%d \n", cardChips);
	printf("\n\n");
	printf("\t          Score: %d ", mult * (handTypeChips + cardChips));
	score += mult * (handTypeChips + cardChips);
	return score;
}
int calculateChips(const CARD* playedHand[], const int numOfCardsPlayed, int* cardChips) {
	long int handTypeChips = 0;
	char* handValue = handType(playedHand, numOfCardsPlayed);
	for (int i = 0; i < numOfCardsPlayed; i++) {
		*cardChips += playedHand[i]->rank;
	}
	if (strcmp(handValue, "Royal Flush") == 0) {
		handTypeChips = 100;
	}
	else if (strcmp(handValue, "Four of a Kind") == 0) {
		handTypeChips = 60;
	}
	else if (strcmp(handValue, "Full House") == 0) {
		handTypeChips = 40;
	}
	else if (strcmp(handValue, "Flush") == 0) {
		handTypeChips = 35;
	}
	else  if (strcmp(handValue, "Straight") == 0) {
		handTypeChips = 30;
	}
	else  if (strcmp(handValue, "Three of a Kind") == 0) {
		handTypeChips = 30;
	}
	else  if (strcmp(handValue, "Two Pair") == 0) {
		handTypeChips = 20;
	}
	else  if (strcmp(handValue, "One Pair") == 0) {
		handTypeChips = 10;
	}
	else  if (strcmp(handValue, "High Card") == 0) {
		handTypeChips = 5;
	}
	else  if (strcmp(handValue, "Empty hand") == 0) {
		handTypeChips = 0;
	}
	return handTypeChips;
}
int calculateMult(const CARD* playedHand[], const int numOfCardsPlayed) {
	char* handValue = handType(playedHand, numOfCardsPlayed);
	puts(handValue); //Shows played hand type
	if (strcmp(handValue, "Royal Flush") == 0) {
		return 8;
	}
	else if (strcmp(handValue, "Four of a Kind") == 0) {
		return 7;
	}
	else if (strcmp(handValue, "Full House") == 0) {
		return 4;
	}
	else if (strcmp(handValue, "Flush") == 0) {
		return 4;
	}
	else  if (strcmp(handValue, "Straight") == 0) {
		return 4;
	}
	else  if (strcmp(handValue, "Three of a Kind") == 0) {
		return 3;
	}
	else  if (strcmp(handValue, "Two Pair") == 0) {
		return 2;
	}
	else  if (strcmp(handValue, "One Pair") == 0) {
		return 2;
	}
	else  if (strcmp(handValue, "High Card") == 0) {
		return 1;
	}
	else  if (strcmp(handValue, "Empty hand") == 0) {
		return 0;
	}
	else exit(-1);
}
char* handType(const CARD* playedHand[], const int numOfCardsPlayed) {
	int rankNum = arrayGetSingleNumber(sameRankCount(playedHand, numOfCardsPlayed), numOfCardsPlayed);
	int sameSuit = 0;

	if (numOfCardsPlayed == 0) {
		return "Empty hand";
	}
	if (numOfCardsPlayed == 1) {
		return "High Card";
	}
	if ((strcmp(playedHand[0]->suit, playedHand[1]->suit) == 0) && (strcmp(playedHand[1]->suit, playedHand[2]->suit) == 0) &&
		(strcmp(playedHand[2]->suit, playedHand[3]->suit) == 0) && (strcmp(playedHand[3]->suit, playedHand[4]->suit) == 0)) {
		sameSuit = 1;
	}
	else sameSuit = 0;


	if ((playedHand[1]->rank == playedHand[0]->rank + 1 && playedHand[2]->rank == playedHand[0]->rank + 2 &&
		playedHand[3]->rank == playedHand[0]->rank + 3 && playedHand[4]->rank == playedHand[0]->rank + 4) && sameSuit == 1)
		return "Royal Flush";

	else if (rankNum == 4)
		return "Four of a Kind";

	else if (rankNum == 32)
		return "Full House";



	else if (sameSuit == 1)
		return "Flush";

	else if (playedHand[1]->rank == playedHand[0]->rank + 1 && playedHand[2]->rank == playedHand[0]->rank + 2 &&
		playedHand[3]->rank == playedHand[0]->rank + 3 && playedHand[4]->rank == playedHand[0]->rank + 4)
		return "Straight";

	else if (rankNum == 3)
		return "Three of a Kind";

	else if (rankNum == 22)
		return "Two Pair";

	else if (rankNum == 2)
		return "One Pair";

	else return "High Card";
}
int* sameRankCount(const CARD* playedHand[], const int numOfCardsPlayed) {
	int arr[5] = { 0 };
	int sameRank = 0;
	for (int i = 0; i < numOfCardsPlayed; i++) {
		for (int j = 0; j < numOfCardsPlayed; j++) {
			if ((playedHand[i]->rank == playedHand[j]->rank) && i != j) {
				sameRank++;
				arr[i] += sameRank;
			}
		}
	}
	return arr;
}
int arrayGetSingleNumber(const int* sameRankList, const int numOfCardsPlayed) {
	int arr[5] = { 0 };
	int numOfValues = 0;
	for (int i = 0; i < numOfCardsPlayed; i++) {
		if (sameRankList[i] != 0) {
			numOfValues++;
			arr[i] = sameRankList[i];
		}
	}
	if (numOfValues == 5) {
		return 32;
	}
	else if (numOfValues == 4) {
		if ((arr[0] > 1 && arr[1] > 1 && arr[2] > 1 && arr[3] > 1) ||
			(arr[1] > 1 && arr[2] > 1 && arr[3] > 1 && arr[4] > 1)) {
			return 4;
		}
		else return 22;
	}
	else if (numOfValues == 3) {
		return 3;
	}
	else if (numOfValues == 2) {
		return 2;
	}
	else return 1;
}



