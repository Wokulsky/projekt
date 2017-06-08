#include "Dragon.h"



Dragon::Dragon()
{

	speed = 0.25;
	name = "Dragon";
	hp = 150;
	damage = 20;
	level = 1;
	row = 3;
	//tex.loadFromFile("enemy.png");
	my_tex.loadFromFile("enemy.png");
	this->setTexture(my_tex);
	this->setTextureRect(sf::IntRect(0, 0, 100, 100));
	animation = std::make_shared<Animation>(my_tex, sf::Vector2u(4, 4), 100.0);
	//Buffer by nie by³o nag³ych zmian kierunków 
	animationBuffer = 0;
	//Aby nie dominowa³y dwa kierunki
	flagAnimation = true;
}


Dragon::~Dragon()
{
}

void Dragon::Render(sf::RenderWindow & App)
{
	if (hp > 0)
		App.draw(*this);
}

void Dragon::Update(float ElapsedTime, sf::Vector2f playerPos){
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
			if (animationBuffer <= 0) {
				row = 1;
				animationBuffer = BufferSize;
				flagAnimation = false;
			}
		}
		if (y <= playerPos.y) {//GÓRA
			y += speed * ElapsedTime;

			if (animationBuffer <= 0 && !flagAnimation) {
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
