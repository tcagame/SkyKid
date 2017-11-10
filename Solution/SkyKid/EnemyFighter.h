#pragma once
#include "Enemy.h"
class EnemyFighter : public Enemy {
public:
	EnemyFighter( const Vector &pos, const int chip_size );
	virtual ~EnemyFighter( );
};

