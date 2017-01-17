#ifndef MAINMENUSTAT_H
#define MAINMENUSTAT_H
#include "gamestates.h"
#include "button.h"
#include <memory>

class mainMenuState: public gameState {
public:
	mainMenuState(sf::RenderWindow &App);
	~mainMenuState();
	void HandleEvent(Game &game);
	void Update(Game &game);
	void Render(sf::RenderWindow &App);
	
private:
	int count;
	std::shared_ptr<button> exitButton;
	std::shared_ptr<button> playButton;
	bool exitClicked, playClicked;
};

#endif // !MAINMENUSTAT_H



