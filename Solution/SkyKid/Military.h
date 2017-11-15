#pragma once
#include "smart_ptr.h"
#include <list>

PTR( Enemy );
PTR( Image );

class Military {
public:
	Military( );
	virtual ~Military( );
public:
	void update( );
	void addEnemy( EnemyPtr enemy );
	void draw( ) const;
private:
	ImagePtr _image;
	std::list< EnemyPtr > _enemis;
};

