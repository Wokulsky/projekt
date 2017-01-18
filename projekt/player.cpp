#include "player.h"



Player::Player()
{
	speed = 0.6;
	alive = true;
	hp = 100;
	tex.loadFromFile("Player.png");
	this->setTexture(tex);
	//this->setScale(2, 2);
	this->setTextureRect(sf::IntRect(0, 0, 55, 60));
}


Player::~Player()
{
}

void Player::DrecreaseHP(int amount) {
	
	if (hp >= 0) {
		hp -= amount;
	}
	else alive = false;
	
}

bool Player::Update(Game &game,float elapsedTime) {

	bool shoot = false;
	if (alive) {

		float x = this->getPosition().x;
		float y = this->getPosition().y;


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			y = y - speed*elapsedTime;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			y = y + speed*elapsedTime;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			x = x - speed*elapsedTime;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			x = x + speed*elapsedTime;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			//std::cout << "SHOOT\n";
			shoot = true;
		}
		else {
			shoot = false;
		}
		this->setPosition(x, y);
	}

	return shoot;
}
void Player::Render(sf::RenderWindow &App) {
	App.draw(*this);
}
int Player::getHP() {
	return hp;
}