#ifndef BOLT_H
#define BOLT_H
#include "game.h"
enum LastKey { Free, Down, Up, Left, Right };
class Bolt : public sf::Sprite
{
public:
	virtual bool Update(float ElapsedTime, Game& game) = 0;
	virtual void Render(sf::RenderWindow& App) = 0;
	virtual void ChangeTexture(sf::Texture &tex) = 0;
	bool isAlive();
	int getDamage();

protected:

	int damege;
	float speed;
	bool alive;
	LastKey key;

};

#endif // BOLT_H


