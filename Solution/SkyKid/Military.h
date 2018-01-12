#pragma once
#include "smart_ptr.h"
#include <list>

PTR( Enemy );
PTR( Player );
PTR( Shot );
PTR( Armoury);
PTR( Magazine );


class Military {
public:
	Military( );
	virtual ~Military( );
public:
	void update( );
	void addEnemy( EnemyPtr enemy );
	bool isOverlappedShots( EnemyPtr enemy );
	void setArmoury( ArmouryPtr armoury );
	void setMagazine( MagazinePtr magazine );
	std::list<EnemyPtr> getEnemyList( ) const;
private:
	std::list< ShotPtr > _shots;
	std::list<EnemyPtr> _enemies;
	ArmouryPtr _armoury;
	MagazinePtr _magazine;
};

