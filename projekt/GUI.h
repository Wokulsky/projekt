#ifndef GUI_H
#define GUI_H
#include <SFML\Graphics.hpp>

class GUI
{
public:
	
	virtual bool onHover(sf::RenderWindow &App) = 0;
	virtual bool onClick(sf::RenderWindow &App) = 0;
	virtual void Render(sf::RenderWindow &App) = 0;

	GUI();
	~GUI();
protected:
	bool selected;
	bool clicked;
};

#endif // !GUI_H



