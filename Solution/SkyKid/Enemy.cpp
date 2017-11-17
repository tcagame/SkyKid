#include "Enemy.h"



Enemy::Enemy( const Vector &pos, const int chip_size ) :
Character( pos, chip_size ) {
}


Enemy::~Enemy( ) {
}

void Enemy::act( ) {
	if( isOverlapped( ) ) {

	}
}

bool Enemy::isOverlapped( CharacterPtr target ) const {
	Vector vec = getOverlappedPos( ) - target->getOverlappedPos( );
	double radius = getOverlappedRadius( ) + target->getOverlappedRadius( );
	return vec.getLength( ) < radius;
}

