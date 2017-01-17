#ifndef FIREBOLT_H
#define FIREBOLT_H

#include "game.h"
class Firebolt
{
public:
	Firebolt(sf::Vector2f start_pos);
	~Firebolt();
	void Update(float ElapsedTime, Game& game);
	void Render(sf::RenderWindow& App);

	bool isAlive();
private:
	sf::Texture tex;
	sf::Sprite spr;
	float speed;
	bool alive;
};

#endif // !FIREBOLT_H



