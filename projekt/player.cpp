#include "player.h"



Player::Player()
{
	isFirst = true;
	speed = 0.5;
	alive = true;
	hp = 200;
	tex.loadFromFile("Player.png");
	this->setTexture(tex);
	animation = std::make_shared<Animation>(tex,sf::Vector2u(4,4),0.0);
	this->setTextureRect(sf::IntRect(0, 0, 55, 60));
	int row = 0;
}


Player::~Player()
{
}
void Player::DrecreaseHP(int amount) {
	
	if (alive) 
		hp = hp - amount;
	if (hp <= 0) alive = false;
	
}

bool Player::isAlive()
{
	if ( alive )
		return true;
	else return false;
}

bool Player::Update(Game &game,float elapsedTime,float playerTime) {

	
	bool shoot = false;

	if (alive) {
		float x = this->getPosition().x;
		float y = this->getPosition().y;


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			if ( y - speed*elapsedTime > 0 )
				y = y - speed*elapsedTime;
			row = 2;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			if ( y + speed*elapsedTime < 540 )
				y = y + speed*elapsedTime;
			row = 0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			if ( x - speed*elapsedTime > 0)
				x = x - speed*elapsedTime;
			row = 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			if ( x + speed*elapsedTime < 740 )
				x = x + speed*elapsedTime;
			row = 3;
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
	//animacja zwraca wektor przesuniêcia
	animation->Update(row, playerTime);
	this->setTextureRect(animation->uvRect);
		
	return shoot;
}
void Player::Render(sf::RenderWindow &App) {
	App.draw(*this);
}
int Player::getHP() {
	return hp;
}