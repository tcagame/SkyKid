#include "Armoury.h"

#include "Shot.h"
#include "define.h"

#include "Military.h"


Armoury::Armoury( MilitaryPtr military ) {
	_enemies = military->getEnemyList( );
}


Armoury::~Armoury( ) {
}

void Armoury::update( ) {
	std::list<ShotPtr>::iterator ite = _shots.begin( );
	while ( ite != _shots.end( ) ) {
		ShotPtr shot = *ite;
		shot->update( );
		if ( isOverlappedEnemys( shot ) ) {
			ite = _shots.erase( ite );
			continue;
		}
		ite++;
	}
}

void Armoury::addShot( ShotPtr shot ) {
	_shots.push_back( shot );
}

bool Armoury::isOverlappedEnemys( ShotPtr shot ) {
	std::list<EnemyPtr>::iterator _enemy_ite = _enemies.begin( );
	while ( _enemy_ite != _enemies.end( ) ) {
		EnemyPtr enemy = *_enemy_ite;
		if ( shot->isOverlapped( enemy ) ) {
			return true;
		}
		_enemy_ite++;
	}

	return false;
}



