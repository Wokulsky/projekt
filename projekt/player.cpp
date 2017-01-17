#include "player.h"



Player::Player()
{
	speed = 0.5;
	hp = 100;
	tex.loadFromFile("Player.png");
	this->setTexture(tex);
	//this->setScale(2, 2);
	this->setTextureRect(sf::IntRect(0, 0, 55, 60));
}


Player::~Player()
{
}

void Player::Update(Game &game,float elapsedTime) {
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
	this->setPosition(x, y);
}
void Player::Render(sf::RenderWindow &App) {
	App.draw(*this);
}