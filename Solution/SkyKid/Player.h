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
		ACTION_MOVE,
		ACTION_SOMERSAULT,
	};
private:
	void act( );
	void draw( );
	void actOnMove( );
	void actOnSomersault( );
private:
	ImagePtr _image;
	ACTION _action;	
	int _tx;
};

