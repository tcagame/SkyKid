#include "Player.h"
#include "define.h"
#include "Drawer.h"
#include "Image.h"
#include "Device.h"
#include "Shot.h"
#include "Armoury.h"

const int MOVE_SPEED = 8;

Player::Player( ) :
Character( START_POS, NORMAL_CHIP_SIZE ),
_tx( 6 ) {
	DrawerPtr drawer = Drawer::getTask( );
	_image = drawer->createImage( "player.png" );
}


Player::~Player( ) {
}

void Player::act( ) {
	switch ( _action ) {
	case ACTION_MOVE:
		actOnMove( );
		break;
	case ACTION_SOMERSAULT:
		actOnSomersault( );
		break;
	case ACTION_ATTACK:
		actOnAttack( );
	}
	draw( );
}

void Player::draw( ) {
	_image->setRect( NORMAL_CHIP_SIZE * _tx, 64, NORMAL_CHIP_SIZE, NORMAL_CHIP_SIZE );
	_image->setPos( ( int )getPos( ).x, ( int )getPos( ).y );
	_image->draw( );
}

void Player::actOnMove( ) {	
	DevicePtr device = Device::getTask( );
	Vector vec;
	if ( device->getDirX( ) > 0 ) {
		vec += Vector( MOVE_SPEED, 0 );
		_tx = 6;
	} 
	
	if ( device->getDirX( ) < 0 ) {
		vec += Vector( -MOVE_SPEED, 0 );
		_tx = 6;
	}

	if ( device->getDirY( ) > 0 ) {
		vec += Vector( 0, MOVE_SPEED );
		_tx = 4;
	}

	if ( device->getDirY( ) < 0 ) {
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
	setVec( Vector( 0, -10 ) );
}

void Player::setArmoury( ArmouryPtr armoury ) {
	_armoury = armoury;
}


void Player::actOnAttack( ) {
	_armoury->addShot( ShotPtr( new Shot( Vector( getPos( ).x, getPos( ).y ) ) ) );
	_action = ACTION_MOVE; 
}