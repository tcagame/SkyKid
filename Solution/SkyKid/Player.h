#pragma once
#include "Character.h"
#include "smart_ptr.h"

PTR( Image ); 

class Player : public Character {
public:
	Player( );
	virtual ~Player( );

private:
	enum ACTION {
		ACTION_MOVE
	};
private:
	void act( );
	void actOnMoving( );
	void draw( );
private:
	ImagePtr _image;
};

