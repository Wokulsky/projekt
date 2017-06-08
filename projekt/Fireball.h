#ifndef FIRE_H
#define FIRE_H

#include "weapon.h"
#include "Firebolt.h"
class Fireball: public Weapon
{
public:
	Fireball();
	~Fireball();
	void Update(Game &game, sf::Vector2f playerPos) override;
	void Render(sf::RenderWindow &App) override;
	std::unique_ptr<Bolt> getBolt() override;
	std::string getBoltNameTexture() override;

private:

};


#endif // !FIRE_H





