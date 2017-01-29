#ifndef PLAYER_H
#include "game.h"
#include "Animation.h"
#include <memory>
class Player : public sf::Sprite
{
public:
	Player();
	~Player();

	bool Update(Game &game,float elapsedTime, float playerTime);
	void Render(sf::RenderWindow &App);
	void DrecreaseHP(int amount);
	bool isAlive();
	int getHP();
private:
	std::shared_ptr<Animation> animation;
	sf::Texture tex;
	float speed;
	int hp;
	bool alive;
	bool isFirst;
	int row ;
};


#define PLAYER_H
#endif // ! PLAYER_H


