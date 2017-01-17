#include "weapon.h"

sf::Sprite Weapon::getSprite() {
	return spr;
}
float Weapon::getFirerate() {
	return firerate;
}

void Weapon::setFirerate(float set) {
	firerate = set;
}
void Weapon::setPosition(float x, float y) {
	spr.setPosition(x, y);
}

/*


weapon::weapon()
{
}


weapon::~weapon()
{
}

void weapon::Update(Game &game) {


}

void weapon::Render(sf::RenderWindow &App) {


}*/
