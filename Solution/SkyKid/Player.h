#pragma once
#include "Character.h"
#include "smart_ptr.h"
#include <list>

PTR( Image ); 
PTR( Shot );
PTR( Enemy );
PTR( Armoury );
PTR( Military );

class Player : public Character {
public:
	Player( );
	virtual ~Player( );
public:
	enum ACTION {
		ACTION_MOVE,
		ACTION_SOMERSAULT,
		ACTION_ATTACK,
		ACTION_DEAD,
		ACTION_CREAR
	};
public:
	void setArmoury( ArmouryPtr armoury );
	void setMilitary( MilitaryPtr military );
	void setAction( ACTION action );
	ACTION getAction( ) const;
private:
	void act( );
	void draw( );
	void actOnMove( );
	void actOnSomersault( );
	void actOnAttack( );
	void actOnDead( );
	void actCrear( );
	void overlapped( );
	bool isCoolTime( );
private:
	int _tx;
	int _ty;
	int _time;
	int _cool_time;
	int _s_time;
	ACTION _action;	
	ImagePtr _image;
	ArmouryPtr _armoury;
	MilitaryPtr _military;
	std::list<EnemyPtr> _enemies;

	Vector _vec;
	double _angle;
};

