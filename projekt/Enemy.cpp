#include "Enemy.h"



Enemy::Enemy(sf::Texture &tex)
{
	speed = 0.25;
	name = "Dragon";
	hp = 150;
	damage = 20;
	level = 1;
	row = 3;
	//tex.loadFromFile("enemy.png");
	this->setTexture(tex);
	this->setTextureRect(sf::IntRect(0, 0, 100, 100));
	animation = std::make_shared<Animation>(tex, sf::Vector2u(4, 4), 100.0);
	//Buffer by nie by³o nag³ych zmian kierunków 
	animationBuffer = 0;
	//Aby nie dominowa³y dwa kierunki
	flagAnimation = true;
}


Enemy::~Enemy()
{

}
void Enemy::Update(float ElapsedTime, sf::Vector2f playerPos) {
	if (hp > 0) {
		float x = this->getPosition().x;
		float y = this->getPosition().y;
		//Poruszanie siê wroga
		if (x <= playerPos.x) {//PRAWO
			x += speed * ElapsedTime;
			if (animationBuffer <= 0 && flagAnimation) {
				row = 2;
				animationBuffer = BufferSize;
				flagAnimation = false;
			}
		}
		else if (x >= playerPos.x) {//LEWO
			x -= speed * ElapsedTime;
			if (animationBuffer <= 0){
				row = 1;
				animationBuffer = BufferSize;
				flagAnimation = false;
			}
		}
		if (y <= playerPos.y) {//GÓRA
			y += speed * ElapsedTime;

			if (animationBuffer <= 0 && !flagAnimation){
				animationBuffer = BufferSize;
				row = 0;
				flagAnimation = true;
			}
			 
		}
		else if (y >= playerPos.y) {//DÓ£
			y -= speed * ElapsedTime;
			if (animationBuffer <= 0) { 
				row = 3; 
				animationBuffer = BufferSize;
				flagAnimation = true;
			}
				
		}

		animationBuffer--;

		float targetX;

		this->setPosition(x, y);

		animation->Update(row, ElapsedTime);
		this->setTextureRect(animation->uvRect);
		this->setScale(1.3, 1.3);

	}
}
void Enemy::Render(sf::RenderWindow &App) {
	if(hp > 0)
		App.draw(*this);
}
std::string Enemy::getName() {
	return name;
}
bool Enemy::isAlive()
{
	return hp > 0;
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