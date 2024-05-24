#pragma once

// ASSIGN CARDS AND SPACE
CARD* dynamicSpace();
void assignRank(CARD* card);
void assignSuit(CARD* card);
void shuffleDeck(CARD* deck[], CARD* allCardsInOrder[]);

// PRINT HAND
void printGame(const PLAYER_INFO* playerInfo, const int discardUsed);
void printInstructions();
void FindCardSuit(const PLAYER_INFO* playerInfo);
void printCardColor(const CARD* hand, const int ChoseColor);

// PLAYING HAND
void playHand(PLAYER_INFO* playerInfo);
void sortPlayedHand(PLAYER_INFO* playerInfo);
inline void arraySwitchPlace(CARD* array[], const int indexA, const int indexB);
inline void arraySwitchPlaceInt(int* array, const int indexA, const int indexB);
int getInput();

// SCORING
void scoreHand(PLAYER_INFO* playerInfo);
int calculateChips(const PLAYER_INFO* playerInfo, int* cardChips);
int calculateMult(const PLAYER_INFO* playerInfo);
char* handType(const PLAYER_INFO* playerInfo);
int* sameRankCount(playerInfo, tempArray);
int arrayGetSingleNumber(const PLAYER_INFO* playerInfo, const int* sameRankList);

int printMenu();
int printGameInstructions();
void saveScore(int score);
void saveScore(const int score);