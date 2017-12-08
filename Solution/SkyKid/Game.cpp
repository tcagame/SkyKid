#include "Game.h"
#include "Application.h"

#include "Scene.h"
#include "SceneMap.h"

#include "Drawer.h"

GamePtr Game::getTask( ) {
	ApplicationPtr app = Application::getInstance( );
	return std::dynamic_pointer_cast< Game >( app->getTask( Game::getTag( ) ) );
}

Game::Game( ) :
_next( Scene::SCENE_MAP ){
}


Game::~Game( ) {
}

void Game::update( ) {
	Drawer::getTask( )->flip( );
	changeScene( );
	_next = _scene->update( );
}

void Game::changeScene( ) {
    if ( _next == Scene::SCENE_CONTINUE ) {
        return;
    }
    switch( _next ) {
	case Scene::SCENE_TITLE:
        _scene = ScenePtr( new SceneMap( ) );
		break;
	case Scene::SCENE_MAP:
        _scene = ScenePtr( new SceneMap( ) );
		break;
    }
}

	

void Game::initialize( ) {

}
