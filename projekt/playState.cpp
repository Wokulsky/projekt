#include "playState.h"

playState::playState(sf::RenderWindow &App){
	player = std::make_unique<Player>();
	elapsedTime = 0;
	shootBuffer = 0;
	weaponSlot = std::make_unique<Fireball>();
	isClickOnGameResult = false;
	font.loadFromFile("Capture_it.ttf");
	gameResultText.setPosition(255, 200);
	gameResultText.setColor(sf::Color::Red);
	gameResultText.setFont(font);

	for (int i = 0; i < ENEMY_NUMBER ; ++i) {
		float x = App.getSize().x - App.getSize().x / 3* (i+1);
		float y = App.getSize().y - App.getSize().y / 3*(i+1);
		enemiesVector.push_back(enemyFactory.getEnemy(EnemyFactory::enemyType::DRAGON));
		enemiesVector.at(i)->setPosition(x, y);
	}
	isAllEnemyDead = false;
	m_playerHUD = std::make_unique<HUD>();

}


playState::~playState(){

}
void playState::HandleEvent(Game& game) {
	if (isClickOnGameResult) {
		game.changeState(Game::gameStates::MAINMENU);
	}

}
void playState::Update(Game &game) {

	elapsedTime = frameClock.getElapsedTime().asMilliseconds();
	frameClock.restart();

	shootBuffer += shootClock.getElapsedTime().asMilliseconds();
	shootClock.restart();
	
	playerTime += playerClock.getElapsedTime().asMilliseconds();
	playerClock.restart();

	if (enemiesVector.size() != 0 && player->isAlive())
		ChecCollision();
	
	if (player->Update(game, elapsedTime, playerTime) && shootBuffer > weaponSlot->getFirerate()) {
		fireboltVector.push_back(std::unique_ptr<Firebolt>(new Firebolt(weaponSlot->getSprite().getPosition())));
		shootBuffer = 0;
	}
	
	weaponSlot->Update(game, player->getPosition());


	for (int i = 0; i < fireboltVector.size(); i++) {
		fireboltVector.at(i)->Update(elapsedTime, game);
		if (!fireboltVector.at(i)->isAlive()) {
			fireboltVector.erase(fireboltVector.begin() + i);
		}
	}

	for (int i = 0; i < enemiesVector.size(); ++i) {
		enemiesVector.at(i)->Update(elapsedTime, player->getPosition());
		if (!enemiesVector.at(i)->isAlive()) {
			enemiesVector.erase(enemiesVector.begin() + i);
		}
	}

	if (enemiesVector.size() == 0) {
		isAllEnemyDead = true;
		gameResultText.setString("YOUR SOUL IS RESCUE");
		gameResultText.setColor(sf::Color::White);
	}
	if (player->getHP() <= 0) {
		gameResultText.setString("YOUR SOUL IS MINE");
	}

}
void playState::ChecCollision() {
	static float hitBufferPlayer = 0;
	static float hitBufferEnemy = 0;
	//hitBuffer daje nam opóŸnienie - inaczej przy Ka¿dym pojedyñczym dotkniêciu hp spada do zera
	//			z prostego powodu - odejmowanie ¿ycia wykonuje siê przy ka¿dym wywo³aniu, teraz jednak po 1000
	
	for (int i = 0; i < enemiesVector.size(); ++i) {
		if (enemiesVector.at(i)->getHp() > 0 && player->isAlive()) {
			if (player->getGlobalBounds().intersects(enemiesVector.at(i)->getGlobalBounds()) && hitBufferPlayer <= 0) {
				player->DrecreaseHP(enemiesVector.at(i)->getDamage());
				std::cout << player->getHP() << std::endl;
				hitBufferPlayer = 250;
				m_playerHUD->decraseHP();
			}
		}
	}
	
	
	for (int i = 0; i < fireboltVector.size(); i++) {
		for (int i = 0; i < enemiesVector.size(); ++i) {
			if ( fireboltVector.at(i)->getGlobalBounds().intersects(enemiesVector.at(i)->getGlobalBounds()) && hitBufferEnemy <= 0 && enemiesVector.at(i)->isAlive()) {
				std::cout << "enemy get hit\n";
				enemiesVector.at(i)->DecreaseHP(fireboltVector.at(i)->getDamage());
				hitBufferEnemy = 500;
				fireboltVector.erase(fireboltVector.begin() + i);
				i++;
			}
		}
	}

	hitBufferEnemy--;
	hitBufferPlayer--;
}

void playState::Render(sf::RenderWindow &App){
	
	player->Render(App);
	weaponSlot->Render(App);
	sf::Vector2f mouse(sf::Mouse::getPosition(App));

	for (int i = 0; i < fireboltVector.size(); ++i) {
		fireboltVector.at(i)->Render(App);
	}

	for (int i = 0; i < enemiesVector.size(); ++i) {
		enemiesVector.at(i)->Render(App);
	}
	m_playerHUD->Render(App);
	if (!player->isAlive() || isAllEnemyDead) {

		App.draw(gameResultText);
	}
	
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && gameResultText.getGlobalBounds().contains(mouse)) {
		isClickOnGameResult = true;
	}
	//testEnemy.Render(App);
}