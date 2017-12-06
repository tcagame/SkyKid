#pragma once
#include "Character.h"
#include "smart_ptr.h"

PTR( Image );

class Shot : public Character {
public:
	Shot( const Vector &pos );
	virtual ~Shot( );
public:
	void act( );
private:
	void draw( );
private:
	ImagePtr _image;
	int _tx;
	Vector _vec;
};

