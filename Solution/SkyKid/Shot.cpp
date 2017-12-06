#include "Shot.h"
#include "define.h"
#include "Image.h"
#include "Drawer.h"

const int MOVE_SPEED = 2;

Shot::Shot( const Vector pos ) :
Character( pos, BULLTE_CHIP_SIZE ),
_tx( 367 ),
_vec( MOVE_SPEED, 0 ) {
	DrawerPtr drawer = Drawer::getTask( );
	_image = drawer->createImage( "bullet.png" );
}

Shot::~Shot( ) {
}

void Shot::act( ) {
	setVec( _vec );
	draw( );
}

void Shot::draw( ) {
	_image->setRect( BULLTE_CHIP_SIZE * _tx, BULLTE_CHIP_SIZE * 2, BULLTE_CHIP_SIZE, BULLTE_CHIP_SIZE );
	_image->setPos( ( int )getPos( ).x, ( int )getPos( ).y );
	_image->draw( );
}