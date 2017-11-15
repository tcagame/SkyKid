#include "Player.h"
#include "define.h"
#include "Drawer.h"
#include "Image.h"
#include "Device.h"

const int MOVE_SPEED = 5;

Player::Player( ) :
Character( START_POS, NORMAL_CHIP_SIZE ),
_move( MOVE_WAIT ) {
	DrawerPtr drawer = Drawer::getTask( );
	_image = drawer->createImage( "skykid.png" );
}


Player::~Player( ) {
}

void Player::act( ) {
	setVec( Vector( 0, 0 ) );
	updateMove( );
	draw( );
}

void Player::draw( ) {
	_image->setRect( NORMAL_CHIP_SIZE * 6, 0, NORMAL_CHIP_SIZE, NORMAL_CHIP_SIZE );
	_image->setPos( ( int )getPos( ).x, ( int )getPos( ).y );
	_image->draw( );
}

void Player::updateMove( ) {	
	DevicePtr device = Device::getTask( );
	Vector vec;
	if ( device->getDirX( ) > 0 ) {
		vec += Vector( MOVE_SPEED, 0 );
	} 
	
	if ( device->getDirX( ) < 0 ) {
		vec += Vector( -MOVE_SPEED, 0 );
	}

	if ( device->getDirY( ) > 0 ) {
		vec += Vector( 0, MOVE_SPEED );
	}

	if ( device->getDirY( ) < 0 ) {
		vec += Vector( 0, -MOVE_SPEED );
	}

	setVec( vec.normalize( ) * MOVE_SPEED );
}
