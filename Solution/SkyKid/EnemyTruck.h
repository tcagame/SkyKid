#pragma once
#include "Enemy.h"
#include "smart_ptr.h"

PTR( Image );

class EnemyTruck : public Enemy {
public:
	EnemyTruck( const Vector &pos, const int chip_size );
	virtual ~EnemyTruck( );
private:
	void act( );
	void draw( );
private:
	ImagePtr _image;
	int _tx;
	int _ty;
};

