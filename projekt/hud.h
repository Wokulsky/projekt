#ifndef HUD_H
#define HUD_H
#include <memory>
#include "game.h"
#include <sstream>
class HUD
{
public:
	HUD();
	~HUD();

	void setPlayerHP(int value);
	void Render(sf::RenderWindow &App);
	void decraseHP();

private:
	std::shared_ptr<sf::Text> m_PlayerHPtext;
	std::stringstream m_PlayerHPStrStr;
	sf::Font font;
	sf::Texture m_TopHudTex;
	sf::Sprite m_TopHud;
	int move_variable;
	int m_PlayerHP;
};

#endif // !HUD_H

