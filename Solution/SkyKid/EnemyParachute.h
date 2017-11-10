#pragma once
#include "Enemy.h"
class EnemyParachute :
	public Enemy
{
public:
	EnemyParachute( const Vector &pos, const int chip_size );
	virtual ~EnemyParachute();
};

