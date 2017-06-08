#include "Fireball.h"



Fireball::Fireball()
{

	setFirerate(500);
	tex.loadFromFile("fire.png");
	spr.setTexture(tex);
}


Fireball::~Fireball()
{
}

void Fireball::Update(Game &game, sf::Vector2f playerPos) {
	//dopasuj do postaci
	float x = playerPos.x;
	float y = playerPos.y + 20;

	spr.setPosition(x, y);
}
void Fireball::Render(sf::RenderWindow &App) {
	App.draw(spr);
}

std::unique_ptr<Bolt> Fireball::getBolt()
{
	return std::unique_ptr<Bolt>(new Firebolt(getSprite().getPosition()));
}

std::string Fireball::getBoltNameTexture()
{
	return std::string();
}

std::string getBoltNameTexture()
{
	return "firebolt2.png";
}
