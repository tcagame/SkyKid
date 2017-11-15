#pragma once
#include "Character.h"
#include "smart_ptr.h"

PTR( Image ); 

class Player : public Character {
public:
	Player( );
	virtual ~Player( );

private:
	enum MOVE {
		MOVE_WAIT,
		MOVE_RIGHT,
		MOVE_LEFT,
		MOVE_UP,
		MOVE_DOWN,
	};
private:
	void act( );
	void draw( );
	void updateMove( );
	void moveLeft( );
	void moveRight( );
	void moveUp( );
	void moveDown( );
private:
	ImagePtr _image;
	MOVE _move;	
};

