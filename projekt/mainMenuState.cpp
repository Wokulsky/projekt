#include "mainMenuState.h"

mainMenuState::mainMenuState(sf::RenderWindow &App)
{
	exitClicked = false;
	playClicked = false;
	exitButton = std::make_shared<button>(sf::Vector2f(200, 200), "Exit");
	exitButton->SetPosition(20, App.getSize().y - 50);
	playButton = std::make_shared<button>(sf::Vector2f(100,100), "Play");
	playButton->SetPosition(20, exitButton->GetPosition().y - 50 );
//	spr.setPosition(sf::Vector2f(250, 50));
	
}

mainMenuState::~mainMenuState()
{
}
void mainMenuState::Update(Game &game) {
	//exitButton->onHover(game.App);
	exitClicked = exitButton->onClick(game.App);
	//playButton->onHover(game.App);
	playClicked = playButton->onClick(game.App);
}
void mainMenuState::Render(sf::RenderWindow &App) {
	exitButton->Render(App);
	playButton->Render(App);
	//App.draw(spr);
}
void mainMenuState::HandleEvent(Game &game) {
	if (exitClicked) {
		game.Stop();
	}
	else if (playClicked) {
		game.changeState(Game::gameStates::PLAY);
	}
}
