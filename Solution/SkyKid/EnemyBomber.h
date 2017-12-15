#pragma once
#include "Enemy.h"

PTR( Image );

//’ãŽ@”šŒ‚‹@
class EnemyBomber : public Enemy {
public:
	EnemyBomber( const Vector &pos, const int chip_size );
	virtual ~EnemyBomber( );
private:
	void act( );
	void draw( );
private:
	ImagePtr _image;
	int _tx;
	int _ty;
	int _time;
	Vector _vec;
};

