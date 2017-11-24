#pragma once

#include "Task.h"
#include <string>

PTR( Game )
PTR( Player )
PTR( EnemyFighter )
PTR( EnemyAnitTank )
PTR( EnemyMiniBalloon )
PTR( EnemyInterceptionBalloon )

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
	EnemyAnitTankPtr _anit_tank;
	EnemyMiniBalloonPtr _mini_balloon;
	EnemyInterceptionBalloonPtr _interception_balloon;
};

