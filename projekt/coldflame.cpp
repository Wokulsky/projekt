#include "coldflame.h"

coldflame::coldflame(){
	setFirerate(100);
	tex.loadFromFile("cold_flame.png");
	spr.setTexture(tex);
}


coldflame::~coldflame()
{

}

void coldflame::Update(Game & game, sf::Vector2f playerPos){
	float x = playerPos.x;
	float y = playerPos.y + 20;
	spr.setPosition(x, y);
}

void coldflame::Render(sf::RenderWindow & App){
	App.draw(spr);
}

std::unique_ptr<Bolt> coldflame::getBolt()
{
	return std::unique_ptr<Bolt>(new Coldbolt(getSprite().getPosition()));
}

std::string coldflame::getBoltNameTexture()
{
	return "coldbolt.png";
}
