#include "Character.h"


Character::Character( const Vector& pos, const int chip_size ) :
_pos( pos ),
_vec( Vector( 0, 0 ) ) {

}


Character::~Character( ) {
}

Vector Character::getPos( ) {
	return _pos;
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
