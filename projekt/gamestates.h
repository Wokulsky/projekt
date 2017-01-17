#ifndef GAMESTATES_H
#define GAMESTATES_H
#include "game.h"

class Game;

class gameState{
public:

	virtual void HandleEvent(Game &game) = 0;
	virtual void Update(Game &game) = 0;
	virtual void Render(sf::RenderWindow &App) = 0;

private:

};
#endif // !GAMESTATE_H
