#ifndef FACTORY_H
#define FACTORY_H

#include "Dragon.h"

class EnemyFactory
{
public:
	
	enum class enemyType{DRAGON};
	EnemyFactory();
	~EnemyFactory();
	std::unique_ptr<Enemy>getEnemy(enemyType type);

};

#endif // !FACTORY_H

