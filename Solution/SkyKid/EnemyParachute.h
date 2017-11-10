#pragma once
#include "Enemy.h"

//パラシュート
class EnemyParachute : public Enemy {
public:
	EnemyParachute( const Vector &pos, const int chip_size );
	virtual ~EnemyParachute( );
private:
	void act( );
};

