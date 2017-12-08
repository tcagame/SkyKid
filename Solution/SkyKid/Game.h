#pragma once

#include "Task.h"
#include <string>
#include "Scene.h"

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
	void changeScene( );
private:
	ScenePtr _scene;
	Scene::SCENE _next;
};

