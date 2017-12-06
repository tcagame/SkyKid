#pragma once
#include "mathmatics.h"
#include "smart_ptr.h"

PTR( Character );

class Character {
public:
	Character( const Vector& pos, const int chip_size );
	virtual ~Character( );
public:
	Vector getPos( );
	void setPos( Vector pos );
	Vector getVec( );
	void setVec( Vector vec );
	void update( );
	void move( );
	double getOverlappedRadius( ) const;
	Vector getOverlappedPos( ) const;
	bool isOverlapped( CharacterPtr target ) const;
private:
	virtual void act( ) = 0;
private:
	int _chip_size;
	Vector _pos;
	Vector _vec;
};

