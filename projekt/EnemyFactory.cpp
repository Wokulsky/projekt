#include "EnemyFactory.h"



EnemyFactory::EnemyFactory()
{
}


EnemyFactory::~EnemyFactory()
{
}

std::unique_ptr<Enemy> EnemyFactory::getEnemy(enemyType type)
{

	switch (type) {
	case enemyType::DRAGON :
		return std::unique_ptr<Dragon>(new Dragon());
		break;
	}
	return std::unique_ptr<Dragon>(new Dragon());
	
}

