#ifndef PLAYSTATE_H
#define PLAYSTATE_H
#include <memory>
#include "gamestates.h"
#include "player.h"
#include "Fireball.h"
#include "Firebolt.h"
#include "Enemy.h"
class playState: public gameState
{
public:
	playState(sf::RenderWindow &App);
	~playState();

	void HandleEvent(Game &game) override;
	void Update(Game &game) override;
	void Render(sf::RenderWindow &App)override;

private:
	void ChecCollision();
	std::unique_ptr<Player> player;
	std::unique_ptr<Weapon> weaponSlot;
	std::unique_ptr<std::vector<Firebolt>> fireboltVector;
	std::unique_ptr<std::vector<Enemy>> enemiesVector;

	sf::Clock frameClock;
	sf::Clock shootClock;
	sf::Clock playerClock;
	//Enemy testEnemy;
	float elapsedTime;
	float shootBuffer;
	float playerTime;
	sf::Texture enemyTex;
	sf::Texture boltTex;

};

#endif // !PLAYSTATE_H



