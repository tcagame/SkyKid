#pragma once
#include "Enemy.h"

//�퓬�@
class EnemyFighter : public Enemy {
public:
	EnemyFighter( const Vector &pos, const int chip_size );
	virtual ~EnemyFighter( );
private:
	void act( );
};

