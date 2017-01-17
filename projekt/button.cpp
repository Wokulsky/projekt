#include "button.h"


button::button(sf::Vector2f position, std::string textStr)
{
	selected = false;
	clicked = false;
	//tex.loadFromFile("button.png");
	//spr.setTexture(tex);
	//Pozycja
	//spr.setTextureRect(sf::IntRect(0,0,spr.getGlobalBounds().width, spr.getGlobalBounds().height/2));
	//spr.setPosition(position);
	font.loadFromFile("Capture_it.ttf");
	
	text.setString(textStr);
	text.setFont(font);
	text.setPosition(position);
	

}
button::~button()
{
}
bool button::onHover(sf::RenderWindow &App) {
	std::string title = text.getString();
	sf::Vector2f mouse(sf::Mouse::getPosition(App));
	/*if ( sf::Mouse::getPosition(App).x >= spr.getPosition().x &&  sf::Mouse::getPosition(App).x < spr.getPosition().x + spr.getGlobalBounds().width &&
		sf::Mouse::getPosition(App).y >= spr.getPosition().x && sf::Mouse::getPosition(App).y <spr.getPosition().y + spr.getGlobalBounds().height) {
		spr.setTextureRect(sf::IntRect(0, spr.getGlobalBounds().height, spr.getGlobalBounds().width, spr.getGlobalBounds().height));
		selected = true;
	if (sf::Mouse::getPosition(App).x <= spr.getPosition().x ||  sf::Mouse::getPosition(App).x > spr.getPosition().x + spr.getGlobalBounds().width ||
		sf::Mouse::getPosition(App).y <= spr.getPosition().x || sf::Mouse::getPosition(App).y  > spr.getPosition().y + spr.getGlobalBounds().height) {

		selected = false;
		spr.setTextureRect(sf::IntRect(0, spr.getGlobalBounds().width, spr.getGlobalBounds().width, spr.getGlobalBounds().height));
		
	}
	}*/

	if (text.getGlobalBounds().contains(mouse)) {
		selected = true;
		std::cout << "Click on HOVER" << title << std::endl;
		return selected;
		//spr.setTextureRect(sf::IntRect(0, spr.getGlobalBounds().height, spr.getGlobalBounds().width, spr.getGlobalBounds().height));
	}
	else {
		selected = false;
		return selected;
		//spr.setTextureRect(sf::IntRect(0, spr.getGlobalBounds().width, spr.getGlobalBounds().width, spr.getGlobalBounds().height));
	}
	
}
bool button::onClick(sf::RenderWindow &App) {
	std::string title = text.getString();
	sf::Vector2f mouse(sf::Mouse::getPosition(App));
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && text.getGlobalBounds().contains(mouse)) {
		
		std::cout << "Click onClick" << title <<std::endl;
		clicked = true;
		return true;
	}else {
		//std::printf("not click on!\n");
		clicked = false;
		return false;
	}
}
void button::Render(sf::RenderWindow &App) {
	//App.draw(spr);
	App.draw(text);
}
void button::SetPosition(float x, float y) {
	//spr.setPosition(x, y);
	text.setPosition(x,y);
}
sf::Vector2f button::GetPosition() {
	return text.getPosition();
}