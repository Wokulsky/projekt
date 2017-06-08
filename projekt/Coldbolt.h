#ifndef COLD_BOLT_H
#define COLD_BOLT_H
#include "Bolt.h"
class Coldbolt :public Bolt
{
public:
	Coldbolt(sf::Vector2f start_pos);
	~Coldbolt();
	bool Update(float ElapsedTime, Game& game) override;
	void Render(sf::RenderWindow& App) override;
	void ChangeTexture(sf::Texture &tex) override;
private:
	sf::Texture mytexture;
};

#endif // !COLD_BOLT_H



