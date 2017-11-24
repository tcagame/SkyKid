#include "EnemyAnitTank.h"
#include "define.h"
#include "Image.h"
#include "Drawer.h"

const int MOVE_SPEED = 5;

EnemyAnitTank::EnemyAnitTank( const Vector &pos, const int chip_size ) :
Enemy( pos, NORMAL_CHIP_SIZE ),
_tx( 0 ),
_t( 0 ),
_vec( MOVE_SPEED, 0 ){
	DrawerPtr drawer = Drawer::getTask( );
	_image = drawer->createImage( "enemy.png" );
}


EnemyAnitTank::~EnemyAnitTank( ) {
}

void EnemyAnitTank::act( ) {
	setVec( _vec );
	draw( );
}

void EnemyAnitTank::draw( ) {
	_image->setRect( NORMAL_CHIP_SIZE * _tx, NORMAL_CHIP_SIZE * 2, NORMAL_CHIP_SIZE, NORMAL_CHIP_SIZE );
	_image->setPos( ( int )getPos( ).x, ( int )getPos( ).y );
	_image->draw( );
}