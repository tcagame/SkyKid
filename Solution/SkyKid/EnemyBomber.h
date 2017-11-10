#pragma once
#include "Enemy.h"
class EnemyBomber : public Enemy {
public:
	EnemyBomber( const Vector &pos, const int chip_size );
	virtual ~EnemyBomber( );
};

