#include "Shot.h"
#include "define.h"
#include "Drawer.h"
#include "Image.h"

const int MOVE_SPEED = 3;

Shot::Shot( const Vector &pos ) :
Character( pos, NORMAL_CHIP_SIZE ),
_tx( 7 ),
_vec( -MOVE_SPEED, 0 ) {
	DrawerPtr drawer = Drawer::getTask( );
	_image = drawer->createImage( "player.png" );
}

Shot::~Shot( ) {
}

void Shot::update( ) {
	setVec( _vec );
	draw( );
}

void Shot::draw( ) {
	_image->setRect( NORMAL_CHIP_SIZE * _tx, 64, NORMAL_CHIP_SIZE, NORMAL_CHIP_SIZE );
	_image->setPos( ( int )getPos( ).x, ( int )getPos( ).y );
	_image->draw( );
}