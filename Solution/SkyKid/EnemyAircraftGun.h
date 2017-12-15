#pragma once
#include "Enemy.h"
#include "smart_ptr.h"

PTR( Image );

class EnemyAircraftGun : public Enemy {
public:
	EnemyAircraftGun( const Vector &pos, const int chip_size );
	virtual ~EnemyAircraftGun( );
private:
	void act( );
	void draw( );
private:
	ImagePtr _image;
	int _tx;
	int _ty;
	int _time;
	int _a;
};

