#pragma once
#include "Enemy.h"
#include "smart_ptr.h"

PTR( Image );

//‚Ë–C
class EnemyGunShot : public Enemy {
public:
	EnemyGunShot( const Vector &pos, const int chip_size );
	virtual ~EnemyGunShot( );
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

