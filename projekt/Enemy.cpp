#include "Enemy.h"



Enemy::Enemy(sf::Texture &tex)
{
	speed = 0.3;
	name = "Dragon";
	hp = 50;
	damage = 10;
	level = 1;

	//tex.loadFromFile("enemy.png");
	this->setTexture(tex);
	this->setTextureRect(sf::IntRect(0, 0, 100, 100));
}


Enemy::~Enemy()
{

}
void Enemy::Update(float ElapsedTime, sf::Vector2f playerPos) {
	if (hp > 0) {
		float x = this->getPosition().x;
		float y = this->getPosition().y;
		//Poruszanie siê wroga
		if (x <= playerPos.x) x += speed * ElapsedTime;
		else if (x >= playerPos.x) x -= speed * ElapsedTime;
		if (y <= playerPos.y) y += speed * ElapsedTime;
		else if (y >= playerPos.y) y -= speed * ElapsedTime;



		float targetX;

		this->setPosition(x, y);
	}
}
void Enemy::Render(sf::RenderWindow &App) {
	App.draw(*this);
}
std::string Enemy::getName() {
	return name;
}
float Enemy::getSpeed() {
	return speed;
}
int Enemy::getHp() {
	return hp;
}
int Enemy::getDamage() {
	return damage;
}
int Enemy::getLevel() {
	return level;
}

void Enemy::setSpeed(float set) {
	speed = set;
}
void Enemy::setHp(int set) {
	hp = set;
}
void Enemy::setDamage(int set) {
	damage = set;
}
void Enemy::setLevel(int set) {
	level = set;
}
void Enemy::setName(std::string name) {
	this->name = name;
}
void Enemy::DecreaseHP(int set) {
	hp -= set;
}