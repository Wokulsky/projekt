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
