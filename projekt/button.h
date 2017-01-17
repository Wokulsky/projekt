#ifndef BUTTON_H
#define BUTTON_H
#include "GUI.h"
#include <iostream>
#include <string>
class button: public GUI{
public:

	button(sf::Vector2f position,std::string textStr);
	~button();

	bool onHover(sf::RenderWindow &App);
	bool onClick(sf::RenderWindow &App);
	void Render(sf::RenderWindow &App);

	void SetPosition(float x, float y);
	sf::Vector2f GetPosition();

private:
	sf::Texture tex;
	sf::Sprite spr;
	sf::Text text;
	sf::Font font;

};

#endif