#pragma once
#include "Enemy.h"

//í“¬‹@
class EnemyFighter : public Enemy {
public:
	EnemyFighter( const Vector &pos, const int chip_size );
	virtual ~EnemyFighter( );
private:
	void act( );
};

