#include "Game.h"
#include "Application.h"
#include "Player.h"
#include "EnemyFighter.h"
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
	_player->update( );
	_fighter->update( );
}
	

void Game::initialize( ) {
	_player = PlayerPtr( new Player( ) );
	_fighter = EnemyFighterPtr( new EnemyFighter( Vector( 60, 60 ), 64 ) );
}
