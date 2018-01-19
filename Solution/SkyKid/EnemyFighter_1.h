#pragma once
#include "Enemy.h"
#include "smart_ptr.h"

PTR( Image );

//êÌì¨ã@
class EnemyFighter_1 : public Enemy {
public:
	EnemyFighter_1( const Vector &pos, const int chip_size );
	virtual ~EnemyFighter_1( );
private:
	void act( );
	void draw( );
private:
	ImagePtr _image;
	int _tx;
	Vector _vec;
	double _angle;
};

