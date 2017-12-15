#include "EnemyAnitTank.h"
#include "define.h"
#include "Image.h"
#include "Drawer.h"

const int MOVE_SPEED = 5;

EnemyAnitTank::EnemyAnitTank( const Vector &pos, const int chip_size ) :
Enemy( pos, SMALL_CHIP_SIZE ),
_tx( 0 ),
_ty( 5 ),
_time( 0 ),
_vec( 3 , 0 ) {
	DrawerPtr drawer = Drawer::getTask( );
	_image = drawer->createImage( "enemy.png" );
}


EnemyAnitTank::~EnemyAnitTank( ) {
}

void EnemyAnitTank::act( ) {
	_time++;

	if(_time % 40 == 0 ) {
		_tx++;
		if ( _tx > 4 ) {
			_tx = 0;
		}
	}
	setVec( _vec );
	draw( );
}

void EnemyAnitTank::draw( ) {
	_image->setRect( SMALL_CHIP_SIZE * _tx, SMALL_CHIP_SIZE * _ty, SMALL_CHIP_SIZE, SMALL_CHIP_SIZE );
	_image->setPos( ( int )getPos( ).x, ( int )getPos( ).y );
	_image->draw( );
}