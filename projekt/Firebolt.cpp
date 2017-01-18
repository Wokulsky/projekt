#include "Firebolt.h"



Firebolt::Firebolt(sf::Vector2f start_pos,sf::Texture &tex)
{
	damege = 15;
	speed = 0.5;
	alive = true;
	this->setTexture(tex);
	this->setPosition(start_pos);
	//this->setTextureRect(sf::IntRect(0, 0, 55, 60));
}


Firebolt::~Firebolt()
{
}

bool Firebolt::Update(float ElapsedTime, Game& game){
	float x = this->getPosition().x;
	float y = this->getPosition().y;
	if (y < game.App.getSize().y ) 
		y = y + speed*ElapsedTime;
	else alive = false;
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