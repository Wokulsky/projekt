#include "playState.h"

playState::playState(sf::RenderWindow &App){
	player = std::make_unique<Player>();
	elapsedTime = 0;
	shootBuffer = 0;
	weaponSlot = std::make_unique<Fireball>();
	isClickOnGameResult = false;
	enemyTex.loadFromFile("enemy.png");
	boltTex.loadFromFile("firebolt2.png");
	font.loadFromFile("Capture_it.ttf");
	gameResultText.setColor(sf::Color::Red);
	gameResultText.setFont(font);
	fireboltVector = std::make_unique<std::vector<Firebolt>>();
	enemiesVector = std::make_unique<std::vector<Enemy>>();
	for (int i = 1; i <= ENEMY_NUMBER ; ++i) {
		float x = App.getSize().x - App.getSize().x / 3*i;
		float y = App.getSize().y - App.getSize().y / 3*i;
		Enemy newEnemy(enemyTex);
		newEnemy.setPosition(x,y);
		enemiesVector->push_back(newEnemy);
	}
	isAllEnemyDead = false;
	m_playerHUD = std::make_unique<HUD>();
	//enemiesVector->push_back(testEnemy);
	
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

	ChecCollision();
	
	if (player->Update(game, elapsedTime, playerTime) && shootBuffer > weaponSlot->getFirerate()) {
		Firebolt newBolt(weaponSlot->getSprite().getPosition(),boltTex);
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

	std::vector<Enemy>::iterator it_enemy;
	int deadEnemy = 0;
	for (it_enemy = enemiesVector->begin(); it_enemy != enemiesVector->end(); ++it_enemy) {
		it_enemy->Update(elapsedTime, player->getPosition());
		if (it_enemy->getHp() <= 0)
			deadEnemy++;
	}
	if (deadEnemy == ENEMY_NUMBER) {
		isAllEnemyDead = true;
		gameResultText.setString("YOUR SOUL IS RESCUE");
		gameResultText.setPosition(255, 200);
		gameResultText.setColor(sf::Color::Blue);
	}
	if (player->getHP() <= 0) {
		gameResultText.setString("YOUR SOUL IS MINE");
		gameResultText.setPosition(255, 200);
	}

	//testEnemy.Update(elapsedTime, player->getPosition());
	//std::cout << "Player position: " << player->getPosition().x << " " << player->getPosition().y << " \n";
}
void playState::ChecCollision() {
	static float hitBufferPlayer = 0;
	static float hitBufferEnemy = 0;
	std::vector<Enemy>::iterator it_enemy;
	//hitBuffer daje nam opóŸnienie - inaczej przy Ka¿dym pojedyñczym dotkniêciu hp spada do zera
	//			z prostego powodu - odejmowanie ¿ycia wykonuje siê przy ka¿dym wywo³aniu, teraz jednak po 1000
	for (it_enemy = enemiesVector->begin(); it_enemy != enemiesVector->end(); ++it_enemy) {
		if (it_enemy->getHp() > 0 && player->isAlive()) {
			if (player->getGlobalBounds().intersects(it_enemy->getGlobalBounds()) && hitBufferPlayer <= 0) {
				player->DrecreaseHP(it_enemy->getDamage());
				std::cout << player->getHP() << std::endl;
				hitBufferPlayer = 250;
				m_playerHUD->decraseHP();
			}
		}

	}
	std::vector<Firebolt>::iterator it_bolt;
	for (it_bolt = fireboltVector->begin(); it_bolt != fireboltVector->end(); ++it_bolt) {
		for (it_enemy = enemiesVector->begin(); it_enemy != enemiesVector->end(); ++it_enemy) {
			if (it_bolt->getGlobalBounds().intersects(it_enemy->getGlobalBounds()) && hitBufferEnemy <= 0) {
				std::cout << "enemy get hit\n";
				it_enemy->DecreaseHP(it_bolt->getDamage());
				hitBufferEnemy = 500;
			}

		}
	}
	hitBufferEnemy--;
	hitBufferPlayer--;
}

void playState::Render(sf::RenderWindow &App){
	player->Render(App);
	weaponSlot->Render(App);
	std::vector<Firebolt>::iterator it_bolt;
	sf::Vector2f mouse(sf::Mouse::getPosition(App));

	for (it_bolt = fireboltVector->begin(); it_bolt != fireboltVector->end(); ++it_bolt) {
		it_bolt->Render(App);
	}

	std::vector<Enemy>::iterator it_enemy;
	for (it_enemy = enemiesVector->begin() ; it_enemy != enemiesVector->end(); ++it_enemy) {
		it_enemy->Render(App);
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