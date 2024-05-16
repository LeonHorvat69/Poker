#pragma once

// ASSIGN CARDS AND SPACE
CARD* dynamicSpace();
void assignRank(CARD* card);
void assignSuit(CARD* card);
void shuffleDeck(CARD* deck[], CARD* allCardsInOrder[]);

// PRINT HAND
void printHand(const CARD* hand[], const int discards, const int score);
void printInstructions();
void printCard(const int numOfCardsPlayed, CARD* playedHand[]);
void setCardCollor(const CARD* hand, const int color);

// PLAYING HAND
void playHand(CARD* hand[], int* cardsPlayed, CARD* playedHand[], const CARD* deck[], const int score);
void sortPlayedHand(CARD* playedHand[], const int numOfCardsPlayed);
void arraySwitchPlace(CARD* array[], int indexA, int indexB);

// SCORING
int scoreHand(const CARD* playedHand[], const int numOfCardsPlayed, int score);
int calculateChips(const CARD* playedHand[], const int numOfCardsPlayed, int* cardChips);
int calculateMult(const CARD* playedHand[], const int numOfCardsPlayed);
char* handType(const CARD* playedHand[], const int numOfCardsPlayed);
int* sameRankCount(const CARD* playedHand[], const int numOfCardsPlayed);
int arrayGetSingleNumber(const int* sameRankList, const int numOfCardsPlayed);
