#include "EnemyBomber.h"
#include "define.h"
#include "Drawer.h"
#include "Image.h"

const int MOVE_SPEED = -5;

EnemyBomber::EnemyBomber( const Vector &pos, const int chip_size ) :
Enemy( pos, NORMAL_CHIP_SIZE ),
_tx ( 1 ),
_ty ( 1 ),
_time ( 0 ),
_vec( MOVE_SPEED, 0 ){
	DrawerPtr drawer = Drawer::getTask( );
	_image = drawer->createImage( "enemy.png" );
}


EnemyBomber::~EnemyBomber( ) {
}

void EnemyBomber::act( ) {
	_time++;

	if(_time % 40 == 0 ) {
		_tx++;
		if ( _tx > 2 ) {
			_tx = 1;
		}
	}
	setVec ( _vec );
	draw( );
}

void EnemyBomber::draw( ) {
	_image->setRect( NORMAL_CHIP_SIZE * _tx, NORMAL_CHIP_SIZE * _ty, NORMAL_CHIP_SIZE, NORMAL_CHIP_SIZE );
	_image->setPos( ( int )getPos( ).x, ( int )getPos( ).y );
	_image->draw( );
}

