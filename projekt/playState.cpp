#include "playState.h"



playState::playState(sf::RenderWindow &App){
	player = std::make_unique<Player>();
	elapsedTime = 0;
	shootBuffer = 0;
	weaponSlot = std::make_unique<Fireball>();
	//firebolt -> shotsVector
	fireboltVector = std::make_unique<std::vector<Firebolt>>();
	enemiesVector = std::make_unique<std::vector<Enemy>>();
	enemiesVector->push_back(testEnemy);
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
	
	ChecCollision();
	
	if (player->Update(game, elapsedTime) && shootBuffer > weaponSlot->getFirerate()) {
		Firebolt newBolt(weaponSlot->getSprite().getPosition());
		fireboltVector->push_back(newBolt);
		shootBuffer = 0;
	}
	weaponSlot->Update(game, player->getPosition());
	for (int i = 0; i < fireboltVector->size(); i++) {
		fireboltVector->at(i).Update(elapsedTime, game);
		if (!fireboltVector->at(i).isAlive()) {
			fireboltVector->erase(fireboltVector->begin() + i);
		}
	}

	testEnemy.Update(elapsedTime, player->getPosition());


	//
}
void playState::ChecCollision() {
	static float hitBufferPlayer = 0;
	if (player->getGlobalBounds().intersects(testEnemy.getGlobalBounds())) {
		player->DrecreaseHP(testEnemy.getDamage());
		hitBufferPlayer = 500;
	}
	hitBufferPlayer--;
}

void playState::Render(sf::RenderWindow &App){
	player->Render(App);
	weaponSlot->Render(App);
	for (int i = 0; i < fireboltVector->size(); i++) {
		fireboltVector->at(i).Render(App);
	}
	for (int i = 0;i < enemiesVector->size(); ++i) {
		enemiesVector->at(i).Render(App);
	}
	testEnemy.Render(App);
}