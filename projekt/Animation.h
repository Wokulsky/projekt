#ifndef ANIMATION_H
#define ANIMATION_H
#include "SFML\Graphics.hpp"
class Animation
{
public:
	Animation(sf::Texture &tex, sf::Vector2u imageCount, float switchTime);
	~Animation();
	//delta - czas pomi�dzy poprzednim framem a obecnym o to by 
	//			fps si� zgadza�y na r�ym sprz�cie
	void Update(int row, float deltaTime);
	//wektor przesuni�cia
	sf::IntRect uvRect;
private:
	//Vector2u - nigdy nie b�dzie ni�ej ni� zero - koordynaty pojedynczej klatki (migawki w animacji)
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;
	//Czas ca�ej animacji
	float totalTime;
	//Jak ma zaj�� animacja
	float switchTime;
	
};

#endif // !ANIMATION_H



