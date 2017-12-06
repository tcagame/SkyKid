#pragma once
#include "Enemy.h"

PTR( Image );

//êÌé‘
class EnemyAnitTank : public Enemy {
public:
	EnemyAnitTank( const Vector &pos, const int chip_size );
	virtual ~EnemyAnitTank( );
private:
	void act( );
	void draw( );
private:
	ImagePtr _image;
	int _tx;
	int _t;
	Vector _vec;
};

