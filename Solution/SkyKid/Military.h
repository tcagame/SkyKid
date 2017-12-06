#pragma once
#include "smart_ptr.h"
#include <list>

PTR( Enemy );
PTR( Player );

class Military {
public:
	Military( PlayerPtr player );
	virtual ~Military( );
public:
	void update( );
	void addEnemy( EnemyPtr enemy );
	std::list<EnemyPtr> getEnemyList( ) const;
private:
	std::list< EnemyPtr > _enemies;
	PlayerPtr _player;
};

