#ifndef DRAGON_H
#define DRAGON_H

#include "Enemy.h"
class Dragon :
	public Enemy
{
public:
	Dragon(sf::Texture &tex);
	~Dragon();
	void Render(sf::RenderWindow &App) override;
	void Update(float ElapsedTime, sf::Vector2f playerPos) override;
};

#endif // !DRAGON_H



