#include "Impact.h"
#include "define.h"
#include "Drawer.h"
#include "Image.h"

Impact::Impact( const Vector &pos ) :
Character( pos, 32 ),
_tx( 1 ) {
	DrawerPtr drawer = Drawer::getTask( );
	_image = drawer->createImage( "impact/Bom32.png" );
}

Impact::~Impact( ) {
}

void Impact::act( ) {
	setVec( _vec );
	if ( getActTime( ) == IMPACT_TIME / 2 ) {
		_tx = 0;
	}
	draw( );
}

void Impact::draw( ) {
	_image->setRect( SMALL_CHIP_SIZE * _tx, 0, 32, 32 );
	_image->setPos( ( int )getPos( ).x, ( int )getPos( ).y );
	_image->draw( );
}