#ifndef FIREBOLT_H
#define FIREBOLT_H

#include "Bolt.h"

class Firebolt: public Bolt
{
public:
	Firebolt(sf::Vector2f start_pos);
	~Firebolt();
	bool Update(float ElapsedTime, Game& game) override;
	void Render(sf::RenderWindow& App) override;
	void ChangeTexture(sf::Texture &tex) override;

private:
	sf::Texture mytexture;

};

#endif // !FIREBOLT_H



