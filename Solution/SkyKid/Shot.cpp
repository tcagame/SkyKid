#include "Shot.h"
#include "define.h"
#include "Drawer.h"
#include "Image.h"

const int MOVE_SPEED = 2;

Shot::Shot( const Vector &pos ) :
Character( pos, NORMAL_CHIP_SIZE ),
_tx( 7 ),
_vec( -MOVE_SPEED, 0 ) {
	DrawerPtr drawer = Drawer::getTask( );
	_image = drawer->createImage( "enemy.png" );
}

Shot::~Shot( ) {
}

void Shot::act( ) {
	int a = getPos( ).x;
	setVec( _vec );
	draw( );
}

void Shot::draw( ) {
	_image->setRect( NORMAL_CHIP_SIZE * _tx, NORMAL_CHIP_SIZE * 2, NORMAL_CHIP_SIZE, NORMAL_CHIP_SIZE );
	_image->setPos( ( int )getPos( ).x, ( int )getPos( ).y );
	_image->draw( );
}