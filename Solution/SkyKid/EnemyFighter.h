#pragma once
#include "Enemy.h"
#include "smart_ptr.h"
PTR( Image )

//êÌì¨ã@
class EnemyFighter : public Enemy {
public:
	EnemyFighter( const Vector &pos, const int chip_size );
	virtual ~EnemyFighter( );
private:
	void act( );
	void draw( );
private:
	ImagePtr _image;
	int _tx;
};

