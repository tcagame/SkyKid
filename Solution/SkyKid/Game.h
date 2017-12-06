#pragma once

#include "Task.h"
#include <string>

PTR( Game );
PTR( Scene );

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
	ScenePtr _scene;
};

