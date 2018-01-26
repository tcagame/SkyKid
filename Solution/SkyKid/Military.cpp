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

#include "Sound.h"

Military::Military( ) {
	
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
			SoundPtr sound = Sound::getTask( );
			sound->playSE( "sound/sky_se_aireborne_enemy_hit.wav" );
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
