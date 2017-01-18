#include "game.h"
#include "mainMenuState.h"
#include "playState.h"
Game::Game() {
	name = "Name";
	App.create(sf::VideoMode(800, 600), name, sf::Style::Close);
	App.setFramerateLimit(500);
	running = true;
}
void Game::Run() {
	while (App.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			App.close();
			running = false;
		}
		CurrentState->HandleEvent(*this);
	}

	CurrentState->Update(*this);
	App.clear();
	CurrentState->Render(App);
	App.display();
	//
}
bool Game::isRunning() {
	return running;
}
void Game::Stop() {
	running = false;
	App.close();
}
void Game::changeState(gameStates newState){
	switch (newState) {
	case(gameStates::MAINMENU):
		CurrentState = std::make_unique<mainMenuState>(App);
		break;
	case(gameStates::PLAY):
		CurrentState = std::make_unique<playState>(App);
		break;
	default:
		std::cout << "can't find game state" << std::endl;
		break;
	}
}
Game::~Game() {

}