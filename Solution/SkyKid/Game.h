#pragma once

#include "Task.h"
#include <string>

PTR( Game )
PTR( Player )
PTR( EnemyFighter )

class Game : public Task {
public:
	static std::string getTag( ) { return "GAME"; }
	static GamePtr getTask( );
	Game( );
	virtual ~Game( );
public:
	void update( );
	void initialize( );
private:
	PlayerPtr _player;
	EnemyFighterPtr _fighter;
};

