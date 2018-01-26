#include "EnemyAircraftGun.h"
#include "define.h"
#include "Drawer.h"
#include "Image.h"

const Vector MOVE_SPEED = Vector( 4, 0 );

EnemyAircraftGun::EnemyAircraftGun( const Vector &pos, const int chip_size ) :
Enemy( pos, SMALL_CHIP_SIZE ),
_tx( 0 ),
_ty( 6 ),
_time( 0 ),
_a( 0 ) {
	DrawerPtr drawer = Drawer::getTask( );
	_image = drawer->createImage( "enemy.png" );
}


EnemyAircraftGun::~EnemyAircraftGun( ) {
}

void EnemyAircraftGun::act( ) {
	setVec( MOVE_SPEED );
	_time++;
	if( _time % 40 == 0 ) {
		_tx++;
		if( _tx > 11 ) {
			_tx = 0;
		}
	}
	draw( );
}

void EnemyAircraftGun::draw( ) {
	_image->setRect( SMALL_CHIP_SIZE * _tx, SMALL_CHIP_SIZE * _ty, SMALL_CHIP_SIZE, SMALL_CHIP_SIZE );
	_image->setPos( ( int )getPos( ).x, ( int )getPos( ).y );
	_image->draw( );
}

