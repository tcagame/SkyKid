#pragma once
#include "Enemy.h"

class EnemyTruck : public Enemy {
public:
	EnemyTruck( const Vector &pos, const int chip_size );
	virtual ~EnemyTruck( );
private:
	void act( );
};

