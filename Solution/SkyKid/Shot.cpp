#include "Shot.h"
#include "define.h"
#include "Drawer.h"
#include "Image.h"

const int MOVE_SPEED = 10;

Shot::Shot( const Vector &pos ) :
Character( pos, 32 ),
_tx( 7 ),
_vec( -MOVE_SPEED, 0 ) {
	DrawerPtr drawer = Drawer::getTask( );
	_image = drawer->createImage( "shot/shot1.png" );
}

Shot::~Shot( ) {
}

void Shot::act( ) {
	setVec( _vec );
	draw( );
}

void Shot::draw( ) {
	_image->setRect( 0, 0, 32, 32 );
	_image->setPos( ( int )getPos( ).x, ( int )getPos( ).y + 20);
	_image->draw( );
}