#ifndef PLAYER_H
#include "game.h"
class Player : public sf::Sprite
{
public:
	Player();
	~Player();

	bool Update(Game &game,float elapsedTime);
	void Render(sf::RenderWindow &App);
	void DrecreaseHP(int amount);

	int getHP();
private:
	sf::Texture tex;
	float speed;
	int hp;
	bool alive;
};


#define PLAYER_H
#endif // ! PLAYER_H


