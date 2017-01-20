#include "player.h"



Player::Player()
{
	isFirst = true;
	speed = 0.5;
	alive = true;
	hp = 100;
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
	
	if (hp >= 0) {
		hp -= amount;
	}
	else alive = false;
	
}

bool Player::Update(Game &game,float elapsedTime,float playerTime) {

	
	bool shoot = false;

	if (alive) {
		float x = this->getPosition().x;
		float y = this->getPosition().y;


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			y = y - speed*elapsedTime;
			row = 2;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			y = y + speed*elapsedTime;
			row = 0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			x = x - speed*elapsedTime;
			row = 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
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