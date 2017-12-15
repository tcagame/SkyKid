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

Military::Military( PlayerPtr player ) {
	_player = player;
	//_enemies.push_back( EnemyPtr( new EnemyFighter( Vector ( 60 , 60 ), NORMAL_CHIP_SIZE ) ) ); 
	//_enemies.push_back( EnemyPtr( new EnemyAnitTank( Vector( 0, 600 ), 64 ) ) );
	//_enemies.push_back ( EnemyPtr( new EnemyMiniBalloon( Vector( 100, 100 ), 64 ) ) );
	//_enemies.push_back ( EnemyPtr( new EnemyInterceptionBalloon( Vector( 200, 0 ), 64 ) ) );
	_enemies.push_back ( EnemyPtr( new EnemyTruck( Vector( 0, 400 ), 64 ) ) );
	_enemies.push_back ( EnemyPtr( new EnemyAircraftGun( Vector( 200, 300 ), 32 ) ) );

}

Military::~Military( ) {
}

void Military::update( ) {
	std::list<EnemyPtr>::iterator ite = _enemies.begin( );
	while ( ite != _enemies.end( ) ) {
		EnemyPtr enemy = *ite;
		enemy->update( );
		if ( enemy->isOverlapped( _player ) ) {
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