#include "hud.h"



HUD::HUD()
{
	font.loadFromFile("Capture_it.ttf");
	m_PlayerHPtext = std::make_shared<sf::Text>();
	m_PlayerHPtext->setFont(font);
	m_PlayerHPtext->setColor(sf::Color::Red);
	m_PlayerHPtext->setCharacterSize(20);

	m_PlayerHPtext->setString("100");
	m_TopHudTex.loadFromFile("playerHP_bar.png");
	m_TopHud.setTexture(m_TopHudTex);
	m_TopHud.setTextureRect(sf::IntRect(0, 0, 220, 119));
	move_variable = 0;
	m_TopHud.setPosition(0, 481);


}


HUD::~HUD()
{
}

void HUD::setPlayerHP(int value)
{
//	m_PlayerHPStrStr.str << value;
	m_PlayerHPtext->setString(m_PlayerHPStrStr.str());
	m_PlayerHPStrStr.str("");
}

void HUD::Render(sf::RenderWindow & App)
{
	App.draw(m_TopHud);
}

void HUD::decraseHP()
{
	if (move_variable < 10) {
		move_variable++;
		m_TopHud.setTextureRect(sf::IntRect(220 * move_variable, 0, 220, 119));
	}

	
}
