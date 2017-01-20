#ifndef ANIMATION_H
#define ANIMATION_H
#include "SFML\Graphics.hpp"
class Animation
{
public:
	Animation(sf::Texture &tex, sf::Vector2u imageCount, float switchTime);
	~Animation();
	//delta - czas pomiêdzy poprzednim framem a obecnym o to by 
	//			fps siê zgadza³y na ró¿ym sprzêcie
	void Update(int row, float deltaTime);
	//wektor przesuniêcia
	sf::IntRect uvRect;
private:
	//Vector2u - nigdy nie bêdzie ni¿ej ni¿ zero - koordynaty pojedynczej klatki (migawki w animacji)
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;
	//Czas ca³ej animacji
	float totalTime;
	//Jak ma zaj¹æ animacja
	float switchTime;
	
};

#endif // !ANIMATION_H



