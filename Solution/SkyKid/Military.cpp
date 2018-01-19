#include "Military.h"

#include "define.h"

#include "Enemy.h"
#include "Player.h"
#include "EnemyFighter.h"
#include "EnemyAnitTank.h"
#include "EnemyMiniBalloon.h"
#include "EnemyInterceptionBalloon.h"
#include "EnemyTruck.h"
#include "EnemyAircraftGun.h"
#include "EnemyGunShot.h"
#include "EnemyBomber.h"

#include "Armoury.h"
#include "Shot.h"

#include "Magazine.h"
#include "Impact.h"

Military::Military( ) {
	//_enemies.push_back( EnemyPtr( new EnemyFighter( Vector ( 60 , 60 ), NORMAL_CHIP_SIZE ) ) ); 
	//_enemies.push_back ( EnemyPtr( new EnemyMiniBalloon( Vector( 100, 100 ), 64 ) ) );
	//_enemies.push_back ( EnemyPtr( new EnemyInterceptionBalloon( Vector( 200, 0 ), 64 ) ) );
	_enemies.push_back( EnemyPtr( new EnemyAnitTank( Vector( 0, 600 ), 64 ) ) );
	_enemies.push_back ( EnemyPtr( new EnemyTruck( Vector( 0, 400 ), 64 ) ) );
	_enemies.push_back ( EnemyPtr( new EnemyAircraftGun( Vector( 200, 300 ), 32 ) ) );
	_enemies.push_back( EnemyPtr( new EnemyBomber( Vector( 1240, 100 ), 64 ) ) );
}

Military::~Military( ) {
}

void Military::update( ) {
	_shots = _armoury->getShotList( );
	std::list<EnemyPtr>::iterator ite = _enemies.begin( );
	while ( ite != _enemies.end( ) ) {
		EnemyPtr enemy = *ite;
		enemy->update( );
		if ( isOverlappedShots( enemy ) ) {
			_magazine->addImpact( ImpactPtr( new Impact( enemy->getPos( ) ) ) );
			ite = _enemies.erase( ite );
			continue;
		}
		ite++;
	}
}

void Military::addEnemy( EnemyPtr enemy ) {
	_enemies.push_back( enemy );
}

std::list<EnemyPtr> Military::getEnemyList( ) const {
	return _enemies;
}

bool Military::isOverlappedShots( EnemyPtr enemy ) {
	std::list<ShotPtr>::iterator _shot_ite = _shots.begin( );
	while ( _shot_ite != _shots.end( ) ) {
		ShotPtr shot = *_shot_ite;
		if ( enemy->isOverlapped( shot ) ) {
			_shot_ite = _shots.erase( _shot_ite );
			return true;
		}
		_shot_ite++;
	}

	return false;
}

void Military::setArmoury( ArmouryPtr armoury ) {
	_armoury = armoury;
}

void Military::setMagazine( MagazinePtr magazine ) {
	_magazine = magazine;
}
