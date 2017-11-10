#pragma once
#include "Enemy.h"

class EnemyAnitTank : public Enemy {
public:
	EnemyAnitTank( const Vector &pos, const int chip_size );
	virtual ~EnemyAnitTank( );
};

