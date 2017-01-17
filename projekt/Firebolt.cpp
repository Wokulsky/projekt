#include "Firebolt.h"



Firebolt::Firebolt(sf::Vector2f start_pos)
{
	tex.loadFromFile("firebolt.png");
	spr.setTexture(tex);
	spr.setPosition(start_pos);
}


Firebolt::~Firebolt()
{
}

void Firebolt::Update(float ElapsedTime, Game& game){
	float x = spr.getPosition().x;
	float y = spr.getPosition().y;

	x = x + speed*ElapsedTime;
}
void Firebolt::Render(sf::RenderWindow& App) {
	App.draw(spr);
}
bool Firebolt::isAlive() {
	return alive;
}
