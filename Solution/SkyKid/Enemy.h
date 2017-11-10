#pragma once
#include "Character.h"

class Enemy : public Character {
public:
	Enemy( const Vector &pos, const int chip_size );
	virtual ~Enemy( );

};

