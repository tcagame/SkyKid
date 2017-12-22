#include "Character.h"
#include "Enemy.h"
#include "Shot.h"


Character::Character( const Vector& pos, const int chip_size ) :
_pos( pos ),
_vec( Vector( 0, 0 ) ),
_chip_size( chip_size ),
_act_time( 0 ) {

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
	_act_time++;
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

bool Character::isOverlapped( CharacterPtr target ) const {
	Vector vec = getOverlappedPos( ) - target->getOverlappedPos( );
	double radius = getOverlappedRadius( ) + target->getOverlappedRadius( );
	return vec.getLength( ) < radius;
}

bool Character::isOverlapped( EnemyPtr enemy ) const {
	Vector vec = getOverlappedPos( ) - enemy->getOverlappedPos( );
	double radius = getOverlappedRadius( ) + enemy->getOverlappedRadius( );
	return vec.getLength( ) < radius;
}

bool Character::isOverlapped( ShotPtr shot ) const {
	Vector vec = getOverlappedPos( ) - shot->getOverlappedPos( );
	double radius = getOverlappedRadius( ) + shot->getOverlappedRadius( );
	return vec.getLength( ) < radius;
}

int Character::getActTime( ) {
	return _act_time;
}