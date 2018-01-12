#pragma once
#include "Character.h"
#include "smart_ptr.h"

PTR( Image ); 
PTR( Shot );
PTR( Enemy );
PTR( Armoury );
PTR( Military );

class Player : public Character {
public:
	Player( );
	virtual ~Player( );
private:
	enum ACTION {
		ACTION_MOVE,
		ACTION_SOMERSAULT,
		ACTION_ATTACK,
		ACTION_DEAD
	};
public:
	void setArmoury( ArmouryPtr armoury );
	ACTION getAction( ) const;
private:
	void act( );
	void draw( );
	void actOnMove( );
	void actOnSomersault( );
	void actOnAttack( );
	void actOnDead( );
	bool isCoolTime( );
private:
	int _tx;
	int _cool_time;
	ACTION _action;	
	ImagePtr _image;
	ArmouryPtr _armoury;
	MilitaryPtr _military;
};

