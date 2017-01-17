#include "playState.h"



playState::playState(sf::RenderWindow &App){
	player = std::make_unique<Player>();
	elapsedTime = 0;
	weaponSlot = std::make_unique<Fireball>();
	fireboltVector = std::make_unique<std::vector<Firebolt>>();
}


playState::~playState(){

}
void playState::HandleEvent(Game& game) {

}
void playState::Update(Game &game) {
	elapsedTime = frameClock.getElapsedTime().asMilliseconds();
	frameClock.restart();

	shootBuffer += shootClock.getElapsedTime().asMilliseconds();
	shootClock.restart();
	if (player->Update(game, elapsedTime) && shootBuffer > weaponSlot->getFirerate()) {
		Firebolt newBolt(weaponSlot->getSprite().getPosition());
		fireboltVector->push_back(newBolt);
		shootBuffer = 0;
	}
	for (int i = 0; i < fireboltVector->size(); i++) {
		fireboltVector->at(i).Update(elapsedTime, game);
		if (!fireboltVector->at(i).isAlive()) {
			fireboltVector->erase(fireboltVector->begin() + i);
		}
	}

	weaponSlot->Update(game, player->getPosition());
	//
}
void playState::Render(sf::RenderWindow &App){
	player->Render(App);
	weaponSlot->Render(App);
	for (int i = 0; i < fireboltVector->size(); i++) {
		fireboltVector->at(i).Render(App);
	}
}