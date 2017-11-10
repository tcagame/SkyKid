#pragma once
#include "mathmatics.h"

class Character {
public:
	Character( const Vector& pos, const int chip_size );
	virtual ~Character( );
private:
	virtual void act( ) = 0; 
};

