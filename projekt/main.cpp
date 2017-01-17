#include "mainMenuState.h"
#include <iostream>

int main() {

	Game game;
	game.changeState(Game::gameStates::MAINMENU);
	while (game.isRunning()) {
		game.Run();
	}

}