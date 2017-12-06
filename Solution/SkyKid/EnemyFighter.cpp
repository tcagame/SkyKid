#include "EnemyFighter.h"
#include "define.h"
#include "Drawer.h"
#include "Image.h"


const int MOVE_SPEED = 10;
const int ROT_R =10;

EnemyFighter::EnemyFighter( const Vector &pos, const int chip_size ) :
Enemy( pos, NORMAL_CHIP_SIZE ),
_angle( 0 ),
_tx( 7 ){
	DrawerPtr drawer = Drawer::getTask( );
	_image = drawer->createImage( "skykid.png" );
}


EnemyFighter::~EnemyFighter( ) {
	
}

void EnemyFighter::act( ) {
	_vec.x = ROT_R * cos( _angle - 20 );
	_vec.y = ROT_R * -sin( _angle - 20 );
	_angle += PI /30;
	if ( _angle > ( 2 * PI ) ) { 
		_angle = 2 * PI;
	}
	setVec( _vec );
	draw( );
}

void EnemyFighter::draw( ) {
	_image->setRect( NORMAL_CHIP_SIZE * _tx, NORMAL_CHIP_SIZE * 1, NORMAL_CHIP_SIZE, NORMAL_CHIP_SIZE );
	_image->setPos( ( int )getPos( ).x, ( int )getPos( ).y );
	_image->draw( );
}
