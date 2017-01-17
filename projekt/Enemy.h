#ifndef ENEMY_H
#define ENEMY_H
#include "game.h"
class Enemy: public sf::Sprite
{
public:
	Enemy();
	~Enemy();
	void Update(float ElapsedTime, sf::Vector2f playerPos);
	void Render(sf::RenderWindow &App);
	float getSpeed();
	int getHp();
	int getDamage();
	int getLevel();
	std::string getName();

	void setName(std::string name);
	void setSpeed(float set);
	void setHp(int set);
	void setDamage(int set);
	void setLevel(int set);

private:
	sf::Texture tex;
	//sf::Sprite spr;

	std::string name;
	float speed;
	int hp;
	int damage;
	int level;
};

#endif