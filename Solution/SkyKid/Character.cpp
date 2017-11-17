#include "Character.h"


Character::Character( const Vector& pos, const int chip_size ) :
_pos( pos ),
_vec( Vector( 0, 0 ) ),
_chip_size( chip_size ){

}


Character::~Character( ) {
}

Vector Character::getPos( ) {
	return _pos;
}

void Character::setPos( Vector pos ) {
	_pos = pos;
}

Vector Character::getVec( ) {
	return _vec;
}

void Character::setVec( Vector vec ) {
	_vec = vec; 
}

void Character::update( ) {
	act( );
	move( );
}

void Character::move( ) {
	_pos += _vec;
}

double Character::getOverlappedRadius( ) const {
	return _chip_size / 2 * 0.8;
}

Vector Character::getOverlappedPos( ) const {
	return Vector( _pos.x, _pos.y  - _chip_size / 2 );
}