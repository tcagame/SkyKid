#include "EnemyFighter_1.h"
#include "define.h"
#include "Drawer.h"
#include "Image.h"


const int MOVE_SPEED = 10;
const int ROT_R =10;

EnemyFighter_1::EnemyFighter_1( const Vector &pos, const int chip_size ) :
Enemy( pos, NORMAL_CHIP_SIZE ),
_angle( 0 ),
_tx( 7 ), 
_vec( 10, 0 ) {
	DrawerPtr drawer = Drawer::getTask( );
	_image = drawer->createImage( "skykid.png" );
}


EnemyFighter_1::~EnemyFighter_1( ) {
	
}

void EnemyFighter_1::act( ) {
	setVec( _vec );
	draw( );
}

void EnemyFighter_1::draw( ) {
	_image->setRect( NORMAL_CHIP_SIZE * _tx, NORMAL_CHIP_SIZE * 1, NORMAL_CHIP_SIZE, NORMAL_CHIP_SIZE );
	_image->setPos( ( int )getPos( ).x, ( int )getPos( ).y );
	_image->draw( );
}
