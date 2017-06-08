#ifndef WEAPON_H
#define WEAPON_H
#include "game.h"
#include "Bolt.h"
class Weapon
{
public:
	/*weapon();
	~weapon();*/

	virtual void Update(Game &game, sf::Vector2f playerPos)=0;
	virtual void Render(sf::RenderWindow &App) = 0;
	virtual std::string getBoltNameTexture() = 0;
	virtual std::unique_ptr<Bolt> getBolt() = 0;

	sf::Sprite getSprite();
	float getFirerate();
	void setFirerate(float set);
	void setPosition(float x, float y);

	

protected:
	sf::Texture tex;
	sf::Sprite spr;
	float firerate;
};
#endif // !WEAPON_H



