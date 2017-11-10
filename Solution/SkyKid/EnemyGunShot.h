#pragma once
#include "Enemy.h"

//‚Ë–C
class EnemyGunShot : public Enemy {
public:
	EnemyGunShot( const Vector &pos, const int chip_size );
	virtual ~EnemyGunShot( );
private:
	void act( );
};

