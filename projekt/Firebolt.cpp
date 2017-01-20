#include "Firebolt.h"



Firebolt::Firebolt(sf::Vector2f start_pos,sf::Texture &tex)
{
	damege = 15;
	speed = 0.5;
	alive = true;
	this->setTexture(tex);
	this->setPosition(start_pos);
	this->setTextureRect(sf::IntRect(0, 0, 48, 48));
	key = LastKey::Free;
}


Firebolt::~Firebolt()
{
}

bool Firebolt::Update(float ElapsedTime, Game& game){
	float x = this->getPosition().x;
	float y = this->getPosition().y;

	if (key != LastKey::Free) {
		switch (key) {
			case LastKey::Up:
				if (y < game.App.getSize().y)
					y = y - speed*ElapsedTime;
				else {
					alive = false;
					key = LastKey::Free;
				}break;
			case LastKey::Down:
				if (y < game.App.getSize().y)
					y = y + speed*ElapsedTime;
				else {
					alive = false;
					key = LastKey::Free;
				}break;
			case LastKey::Right:
				if (x < game.App.getSize().x)
					x = x + speed*ElapsedTime;
				else {
					alive = false;
					key = LastKey::Free;
				}break;
			case LastKey::Left:
				if (x < game.App.getSize().x)
					x = x - speed*ElapsedTime;
				else {
					alive = false;
					key = LastKey::Free;
				}break;
		}
	}
	else {

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			//if (x > game.App.getSize().x)
			x = x - speed*ElapsedTime;
			this->setTextureRect(sf::IntRect(0, 0, 48, 48));
			key = LastKey::Left;
		}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			//if (y < game.App.getSize().y)
				y = y - speed*ElapsedTime;
				this->setTextureRect(sf::IntRect(48, 0 , 48, 48));
			key = LastKey::Up;
		}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			//if (y < game.App.getSize().y)
				y = y + speed*ElapsedTime;
				this->setTextureRect(sf::IntRect(96, 0, 48, 48));
			key = LastKey::Down;
		}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			//if (x < game.App.getSize().x)
				x = x + speed*ElapsedTime;
				this->setTextureRect(sf::IntRect(144,0, 48, 48));
				key = LastKey::Right;
		}
		alive = true;
	}
	
	this->setPosition(x, y);
	return alive;
}
void Firebolt::Render(sf::RenderWindow& App) {
	App.draw(*this);
}
bool Firebolt::isAlive() {
	return alive;
}
int Firebolt::getDamage() {
	return damege;
}