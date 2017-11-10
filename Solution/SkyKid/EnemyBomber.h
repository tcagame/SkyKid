#pragma once
#include "Enemy.h"

//’ã@”šŒ‚‹@
class EnemyBomber : public Enemy {
public:
	EnemyBomber( const Vector &pos, const int chip_size );
	virtual ~EnemyBomber( );
private:
	void act( );
};

