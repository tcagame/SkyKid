#pragma once
#include "Character.h"
#include "smart_ptr.h"

PTR( Image ); 
PTR( Shot );
PTR( Enemy );
PTR( Armoury );

class Player : public Character {
public:
	Player( );
	virtual ~Player( );
private:
	enum ACTION {
		ACTION_MOVE,
		ACTION_SOMERSAULT,
		ACTION_ATTACK
	};
public:
	void setArmoury( ArmouryPtr armoury );
private:
	void act( );
	void draw( );
	void actOnMove( );
	void actOnSomersault( );
	void actOnAttack( );
	bool isCoolTime( );
private:
	int _tx;
	int _cool_time;
	ACTION _action;	
	ImagePtr _image;
	ArmouryPtr _armoury;
	EnemyPtr _enemy;
};

