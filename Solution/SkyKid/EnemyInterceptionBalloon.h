#pragma once
#include "Enemy.h"
#include "smart_ptr.h"
PTR( Image )

//Œ}Œ‚‹C‹…
class EnemyInterceptionBalloon : public Enemy {
public:
	EnemyInterceptionBalloon( const Vector &pos, const int chip_size );
	virtual ~EnemyInterceptionBalloon( );
private:
	void act( );
	void draw( );
private:
	ImagePtr _image;
	int _tx;
	Vector _vec;
	double _angle;
	int _act_count;
};

