#ifndef PLAYER_H
#include "game.h"
class Player : public sf::Sprite
{
public:
	Player();
	~Player();

	bool Update(Game &game,float elapsedTime);
	void Render(sf::RenderWindow &App);


private:
	sf::Texture tex;
	float speed;
	int hp;
};


#define PLAYER_H
#endif // ! PLAYER_H


