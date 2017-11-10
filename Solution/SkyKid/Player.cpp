#include "Player.h"
#include "define.h"
#include "Drawer.h"
#include "Image.h"

Player::Player( ) : Character( START_POS, NORMAL_CHIP_SIZE ) {
	DrawerPtr drawer = Drawer::getTask( );
	drawer->createImage( "" );
}


Player::~Player( ) {
}

void Player::act( ) {
	actOnMoving( );
}

void Player::actOnMoving( ) {
}

void Player::draw( ) {
	_image->setPos( ( int )START_POS.x, ( int )START_POS.y );
	_image->draw( );
}