#include "Game.h"
#include "Application.h"

#include "Scene.h"
#include "SceneMap.h"

#include "Drawer.h"

GamePtr Game::getTask( ) {
	ApplicationPtr app = Application::getInstance( );
	return std::dynamic_pointer_cast< Game >( app->getTask( Game::getTag( ) ) );
}

Game::Game( ) {
}


Game::~Game( ) {
}

void Game::update( ) {
	Drawer::getTask( )->flip( );
	_scene->update( );
}
	

void Game::initialize( ) {
	_scene = ScenePtr( new SceneMap( ) ); 

}
