/*
Handles a complete game including arena, players
*/

#ifndef GAME_H
#define GAME_H

#include "Arena.h"
#include "Player.h"

class Game
{
protected:
	static const int MAX_PLAYERS = 4;
	int numPlayers;
	Arena* arena;
	Player* player[MAX_PLAYERS];
};

#endif
