#pragma once
#include "smart_ptr.h"
#include <list>

PTR( Enemy );
PTR( Player );
PTR( Image );

class Military {
public:
	Military( PlayerPtr player );
	virtual ~Military( );
public:
	void update( );
	void addEnemy( EnemyPtr enemy );
	void draw( ) const;
private:
	ImagePtr _image;
	std::list< EnemyPtr > _enemies;
	PlayerPtr _player;
};

