#include "Player.h"
#include "define.h"
#include "Drawer.h"
#include "Image.h"
#include "Device.h"
#include "Shot.h"
#include "Armoury.h"
#include "Sound.h"
#include "Enemy.h"
#include "Military.h"

const int MOVE_SPEED = 8;

Player::Player( ) :
Character( START_POS, NORMAL_CHIP_SIZE ),
_tx( 6 ),
_cool_time( 0 ),
_time( 0 ),
_ty( 1 ) {
//	_military = military;
	DrawerPtr drawer = Drawer::getTask( );
	_image = drawer->createImage( "player.png" );
}


Player::~Player( ) {
}

void Player::act( ) {
	_cool_time++;
	overlapped( );
	switch ( _action ) {
	case ACTION_MOVE:
		actOnMove( );
		break;
	case ACTION_SOMERSAULT:
		actOnSomersault( );
		break;
	case ACTION_ATTACK:
		actOnAttack( );
		break;
	case ACTION_DEAD:
		actOnDead( );
		break;
	}
	draw( );
}

void Player::draw( ) {
	_image->setRect( NORMAL_CHIP_SIZE * _tx, NORMAL_CHIP_SIZE * _ty, NORMAL_CHIP_SIZE, NORMAL_CHIP_SIZE );
	_image->setPos( ( int )getPos( ).x, ( int )getPos( ).y );
	_image->draw( );
}

void Player::actOnMove( ) {	
	DevicePtr device = Device::getTask( );
	Vector vec;
	if ( device->getDirX( ) > 0 && getPos( ).x < WINDOW_WIDTH -128 ) {
		vec += Vector( MOVE_SPEED, 0 );
		_tx = 6;
	} 
	
	if ( device->getDirX( ) < 0 && getPos( ).x > 0 ) {
		vec += Vector( -MOVE_SPEED, 0 );
		_tx = 6;
	}

	if ( device->getDirY( ) > 0 && getPos( ).y < WINDOW_HEIGHT - 128 ) {
		vec += Vector( 0, MOVE_SPEED );
		_tx = 4;
	}

	if ( device->getDirY( ) < 0 && getPos( ).y > 0 ) {
		vec += Vector( 0, -MOVE_SPEED );
		_tx = 2;
	}

	if ( device->getPush( ) == BUTTON_A ) {
		_action = ACTION_ATTACK;
	}

	if ( device->getPush( ) == BUTTON_B ) {
		_action = ACTION_SOMERSAULT;
	}

	setVec( vec.normalize( ) * MOVE_SPEED );
}

void Player::actOnSomersault( ) {
	_vec.x = 9 * -cos( _angle );
	_vec.y = 7 * -sin( _angle );
	_angle += PI /30;
	if ( _angle > ( 2 * PI ) ) { 
		_angle = 0;
		_action = ACTION_MOVE;
	}
	setVec( _vec );
}

void Player::setArmoury( ArmouryPtr armoury ) {
	_armoury = armoury;
}

void Player::setMilitary( MilitaryPtr military ) {
	_military = military;
}


void Player::actOnAttack( ) {
	SoundPtr sound = Sound::getTask( );
	sound->playSE( "sound/sky_se_max_shot.wav" );
	_armoury->addShot( ShotPtr( new Shot( getPos( ) ) ) );
	_cool_time = 0;
	_action = ACTION_MOVE; 
}

void Player::actOnDead( ) {
	_time++;
	setVec( Vector( 0, 5 ) );
	_ty = 2;

	if(_time % 5 == 0 ) {
		_tx++;
		if ( _tx > 1 ) {
			_tx = 0;
		}
	}
}

bool Player::isCoolTime( ) {
	return _cool_time > COOL_TIME;
}

Player::ACTION Player::getAction( ) const {
	return _action;
}

void Player::overlapped( ) {
	_enemies = _military->getEnemyList( );
	std::list<EnemyPtr>::iterator _enemy_ite = _enemies.begin( );
	while ( _enemy_ite != _enemies.end( ) ) {
		EnemyPtr enemy = *_enemy_ite;
		if ( isOverlapped( enemy ) ) {
			_tx = 0;
			_action = ACTION_DEAD;
		}
		_enemy_ite++;
	}
}

