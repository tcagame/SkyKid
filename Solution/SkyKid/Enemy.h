#pragma once
#include "Character.h"
#include "smart_ptr.h"

PTR( Character );

class Enemy : public Character {
public:
	Enemy( const Vector &pos, const int chip_size );
	virtual ~Enemy( );
private:
	void act( );
public:
	bool Enemy::isOverlapped( CharacterPtr target ) const;
};

