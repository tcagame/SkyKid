#include "EnemyInterceptionBalloon.h"
#include "define.h"
#include "Drawer.h"
#include "Image.h"
#include <math.h>

const int MOVE_SPEED = 10;
const int ROT_R =10;
const int FALLING_COUNT = 60;

EnemyInterceptionBalloon::EnemyInterceptionBalloon( const Vector &pos, const int chip_size ) :
Enemy( pos, NORMAL_CHIP_SIZE ),
_angle( 0 ),
_tx( 0 ),
_act_count( 0 ) {
	DrawerPtr drawer = Drawer::getTask( );
	_image = drawer->createImage( "enemy.png" );
}


EnemyInterceptionBalloon::~EnemyInterceptionBalloon( ) {
	
}

void EnemyInterceptionBalloon::act( ) {
	_act_count++;
	if ( _act_count < FALLING_COUNT ) {
		_vec.x += 0.05;
	}
	if ( _act_count > FALLING_COUNT ) {
		_vec.x -= 0.05;
	}
	if( _act_count > FALLING_COUNT * 3 ) {
		_vec.x += 0.1;

	}
	_vec.y += 0.01;

	setVec( _vec );
	draw( );
}

void EnemyInterceptionBalloon::draw( ) {
	_image->setRect( NORMAL_CHIP_SIZE * _tx, NORMAL_CHIP_SIZE * 1, NORMAL_CHIP_SIZE, NORMAL_CHIP_SIZE );
	_image->setPos( ( int )getPos( ).x, ( int )getPos( ).y );
	_image->draw( );
}
