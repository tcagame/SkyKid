#include "EnemyGunShot.h"
#include "define.h"
#include "Drawer.h"
#include "Image.h"


EnemyGunShot::EnemyGunShot( const Vector &pos, const int chip_size ) :
Enemy( pos, SMALL_CHIP_SIZE ),
_tx( 6 ),
_ty( 5 ),
_time( 0 ),
_a( 0 ) {
	DrawerPtr drawer = Drawer::getTask( );
	_image = drawer->createImage( "enemy.png" );
}


EnemyGunShot::~EnemyGunShot( ) {
}

void EnemyGunShot::act( ) {
	_time++;

	if( _time % 40 == 0 ) {
		_tx++;
		if ( _tx > 9 ) {
			_tx = 6;
		}
	}
	draw( );
}

void EnemyGunShot::draw( ) {
	_image->setRect( SMALL_CHIP_SIZE * _tx, SMALL_CHIP_SIZE * _ty, SMALL_CHIP_SIZE, SMALL_CHIP_SIZE );
	_image->setPos( ( int )getPos( ).x, ( int )getPos( ).y );
	_image->draw( );
}
