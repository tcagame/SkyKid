#include "EnemyTruck.h"
#include "define.h"
#include "Drawer.h"
#include "Image.h"

const Vector MOVE_SPEED = Vector( 3, 0 );

EnemyTruck::EnemyTruck( const Vector &pos, const int chip_size ) :
Enemy( pos, NORMAL_CHIP_SIZE ),
_tx( 7 ),
_ty( 1 ) {
	DrawerPtr drawer = Drawer::getTask( );
	_image = drawer->createImage( "enemy.png" );
}


EnemyTruck::~EnemyTruck( ) {
}

void EnemyTruck::act( ) {
	setVec( MOVE_SPEED );
	draw( );
}

void EnemyTruck::draw( ) {
	_image->setRect( NORMAL_CHIP_SIZE * _tx, NORMAL_CHIP_SIZE * _ty, NORMAL_CHIP_SIZE, NORMAL_CHIP_SIZE );
	_image->setPos( ( int )getPos( ).x, ( int )getPos( ).y );
	_image->draw( );
}

