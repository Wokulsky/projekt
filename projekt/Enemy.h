#ifndef ENEMY_H
#define ENEMY_H

#include "game.h"
#include "Animation.h"
#include <memory>
#define BufferSize 450
class Enemy: public sf::Sprite
{
public:
	Enemy(sf::Texture &tex);
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

	void DecreaseHP(int set);
private:
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