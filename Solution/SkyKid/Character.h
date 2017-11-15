#pragma once
#include "mathmatics.h"

class Character {
public:
	Character( const Vector& pos, const int chip_size );
	virtual ~Character( );
public:
	Vector getPos( );
	void setVec( Vector vec );
	void update( );
	void move( );
private:
	virtual void act( ) = 0;
private:
	Vector _pos;
	Vector _vec;
};

