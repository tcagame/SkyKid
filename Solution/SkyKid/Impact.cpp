#include "Impact.h"
#include "define.h"
#include "Drawer.h"
#include "Image.h"

Impact::Impact( const Vector &pos ) :
Character( pos, 32 ),
_tx( 7 ) {
	DrawerPtr drawer = Drawer::getTask( );
	_image = drawer->createImage( "impact/Bom64.png" );
}

Impact::~Impact( ) {
}

void Impact::act( ) {
	setVec( _vec );
	draw( );
}

void Impact::draw( ) {
	_image->setRect( 0, 0, 64, 64 );
	_image->setPos( ( int )getPos( ).x, ( int )getPos( ).y );
	_image->draw( );
}