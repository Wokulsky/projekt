#ifndef FIREBOLT_H
#define FIREBOLT_H

#include "game.h"
class Firebolt: public sf::Sprite
{
public:
	Firebolt(sf::Vector2f start_pos, sf::Texture &tex);
	~Firebolt();
	bool Update(float ElapsedTime, Game& game);
	void Render(sf::RenderWindow& App);

	bool isAlive();
	int getDamage();
private:

	int damege;
	float speed;
	bool alive;
};

#endif // !FIREBOLT_H



