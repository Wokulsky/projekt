#include "playState.h"



playState::playState(sf::RenderWindow &App){
	player = std::make_unique<Player>();
	elapsedTime = 0;
	weaponSlot = std::make_unique<Fireball>();
}


playState::~playState(){

}
void playState::HandleEvent(Game& game) {

}
void playState::Update(Game &game) {
	elapsedTime = frameClock.getElapsedTime().asMilliseconds();
	frameClock.restart();
	player->Update(game,elapsedTime);
	weaponSlot->Update(game, player->getPosition());
	//
}
void playState::Render(sf::RenderWindow &App){
	player->Render(App);
	weaponSlot->Render(App);
	
}