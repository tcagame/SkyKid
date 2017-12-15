#pragma once
#include "Character.h"
#include "smart_ptr.h"

PTR( Image );

class Impact : public Character {
public:
	Impact( const Vector &pos );
	virtual ~Impact( );
public:
	void act( );
private:
	void draw( );
private:
	ImagePtr _image;
	Vector _vec;
	int _tx;
};

