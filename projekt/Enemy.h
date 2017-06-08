#ifndef ENEMY_H
#define ENEMY_H

#include "game.h"
#include "Animation.h"
#include <memory>
#define BufferSize 450
class Enemy: public sf::Sprite
{
public:

	virtual void Update(float ElapsedTime, sf::Vector2f playerPos) = 0;
	virtual  void Render(sf::RenderWindow &App) = 0;
	float getSpeed();
	int getHp();
	int getDamage();
	int getLevel();
	std::string getName();
	bool isAlive();
	void setName(std::string name);
	void setSpeed(float set);
	void setHp(int set);
	void setDamage(int set);
	void setLevel(int set);
	void DecreaseHP(int set);

protected:
	//sf::Texture tex;
	std::string name;
	float speed;
	int hp;
	int damage;
	int level;
	std::shared_ptr<Animation> animation;
	int row;
	int animationBuffer;
	bool flagAnimation;
};

#endif