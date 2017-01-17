#ifndef PLAYSTATE_H
#define PLAYSTATE_H
#include <memory>
#include "gamestates.h"
#include "player.h"
#include "Fireball.h"
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
	sf::Clock frameClock;
	float elapsedTime;

};

#endif // !PLAYSTATE_H



