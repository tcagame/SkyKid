#pragma once
#include "smart_ptr.h"
#include <list>

PTR( Shot );
PTR( Military );
PTR( Enemy );

class Armoury {
public:
	Armoury( );
	virtual ~Armoury( );
public:
	void update( );
	void addShot( ShotPtr shot );
	std::list<ShotPtr>getShotList( ) const;
private:
	std::list< ShotPtr > _shots;
};

