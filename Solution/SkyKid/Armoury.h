#pragma once
#include "smart_ptr.h"
#include <list>

PTR( Shot );
PTR( Military );
PTR( Enemy );

class Armoury {
public:
	Armoury( MilitaryPtr military );
	virtual ~Armoury( );
public:
	void update( );
	void addShot( ShotPtr shot );
private:
	bool isOverlappedEnemys( ShotPtr shot );
private:
	std::list< ShotPtr > _shots;
	std::list<EnemyPtr> _enemies;
};

