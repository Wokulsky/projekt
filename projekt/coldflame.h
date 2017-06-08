#ifndef COLDFLAME_H
#define COLDFLAME_H
#include "weapon.h"
#include "Coldbolt.h"
class coldflame :public Weapon
{
public:
	coldflame();
	~coldflame();
	void Update(Game &game, sf::Vector2f playerPos) override;
	void Render(sf::RenderWindow &App) override;
	std::unique_ptr<Bolt> getBolt() override;
	std::string getBoltNameTexture() override;
};
#endif

