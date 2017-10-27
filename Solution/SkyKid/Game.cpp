#include "Game.h"
#include "Application.h"

GamePtr Game::getTask( ) {
	ApplicationPtr fw = Application::getInstance( );
	return std::dynamic_pointer_cast< Game >( fw->getTask( Game::getTag( ) ) );
}

Game::Game( ) {
}


Game::~Game( ) {
}

void Game::update( ) {
}
	

void Game::initialize( ) {
}
