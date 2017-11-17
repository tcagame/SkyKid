#include "EnemyFighter.h"
#include "define.h"
#include "Drawer.h"
#include "Image.h"

EnemyFighter::EnemyFighter( const Vector &pos, const int chip_size ) :
Enemy( pos, NORMAL_CHIP_SIZE ),
_tx( 7 ){
	DrawerPtr drawer = Drawer::getTask( );
	_image = drawer->createImage( "skykid.png" );
}


EnemyFighter::~EnemyFighter( ) {
}

void EnemyFighter::act( ) {
	setVec( Vector( 3, 5  ) );
	draw( );
}

void EnemyFighter::draw( ) {
	_image->setRect( NORMAL_CHIP_SIZE * _tx, NORMAL_CHIP_SIZE * 1, NORMAL_CHIP_SIZE, NORMAL_CHIP_SIZE );
	_image->setPos( ( int )getPos( ).x, ( int )getPos( ).y );
	_image->draw( );
}