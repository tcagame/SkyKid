#pragma once
#include "Character.h"

class Player : public Character {
public:
	Player( );
	virtual ~Player( );
public:
	void act( );
private:
	enum ACTION {
		ACTION_MOVE,
		ACTION_ATTACK,

	};
private:
	void actOnMoving( );
};

