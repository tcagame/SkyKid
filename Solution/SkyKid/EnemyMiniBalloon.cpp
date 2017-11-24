#include "EnemyMiniBalloon.h"
#include "define.h"
#include "Drawer.h"
#include "Image.h"
#include <math.h>

const int MOVE_SPEED = 5;
const int ROT_R =10;

EnemyMiniBalloon::EnemyMiniBalloon( const Vector &pos, const int chip_size ) :
Enemy( pos, NORMAL_CHIP_SIZE ),
_angle( 0 ),
_tx( 3 ){
	DrawerPtr drawer = Drawer::getTask( );
	_image = drawer->createImage( "enemy.png" );
}


EnemyMiniBalloon::~EnemyMiniBalloon( ) {
	
}

void EnemyMiniBalloon::act( ) {
	_vec.x = MOVE_SPEED;
	_vec.y = ROT_R * -sin( _angle - 20 );
	_angle += PI / 30;
	if ( _angle > ( 2 * PI ) ) { 
		_angle -= 2 * PI;
	}
	setVec( _vec );
	draw( );
}

void EnemyMiniBalloon::draw( ) {
	_image->setRect( NORMAL_CHIP_SIZE * _tx, NORMAL_CHIP_SIZE * 1, NORMAL_CHIP_SIZE, NORMAL_CHIP_SIZE );
	_image->setPos( ( int )getPos( ).x, ( int )getPos( ).y );
	_image->draw( );
}
