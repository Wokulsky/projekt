#ifndef DRAGON_H
#define DRAGON_H

#include "Enemy.h"
class Dragon :
	public Enemy
{
public:
	Dragon();
	~Dragon();
	void Render(sf::RenderWindow &App) override;
	void Update(float ElapsedTime, sf::Vector2f playerPos) override;
private:

};

#endif // !DRAGON_H



