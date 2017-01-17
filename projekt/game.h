#ifndef GAME_H
#define GAME_H

#include <SFML\Graphics.hpp>
#include <memory>
#include <iostream>

class gameState;
class mainMenuState;
class playState;

class Game {
public:
	enum class gameStates{MAINMENU,PLAY};
	Game();
	~Game();
	void Run();
	void Stop();
	bool isRunning();
	void changeState(gameStates newState);
	sf::RenderWindow App;

	
private:

	
	sf::Event event;
	bool running;
	// name - GameName
	std::string name;
	//zobacz !!
	std::unique_ptr<gameState> CurrentState;
};

#endif // GAME_H

