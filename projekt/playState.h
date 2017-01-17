#ifndef PLAYSTATE_H
#define PLAYSTATE_H
#include <memory>
#include "gamestates.h"
#include "player.h"
#include "Fireball.h"
#include "Firebolt.h"
class playState: public gameState
{
public:
	playState(sf::RenderWindow &App);
	~playState();

	void HandleEvent(Game &game);
	void Update(Game &game);
	void Render(sf::RenderWindow &App);

private:
	std::unique_ptr<Player> player;
	std::unique_ptr<Weapon> weaponSlot;
	std::unique_ptr<std::vector<Firebolt>> fireboltVector;
	sf::Clock frameClock;
	sf::Clock shootClock;
	float elapsedTime;
	float shootBuffer;

};

#endif // !PLAYSTATE_H



