#pragma once
#include "Enemy.h"
#include "smart_ptr.h"
PTR( Image );

//ƒ~ƒj‹C‹…
class EnemyMiniBalloon : public Enemy {
public:
	EnemyMiniBalloon( const Vector &pos, const int chip_size );
	virtual ~EnemyMiniBalloon( );
private:
	void act( );
	void draw( );
private:
	ImagePtr _image;
	int _tx;
	Vector _vec;
	double _angle;
};

