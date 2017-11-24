#include "Game.h"
#include "Application.h"

#include "Player.h"

#include "EnemyFighter.h"
#include "EnemyAnitTank.h"
#include "EnemyMiniBalloon.h"
#include "EnemyInterceptionBalloon.h"

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
	_anit_tank->update( );
	_mini_balloon->update( );
	_interception_balloon->update( );
}
	

void Game::initialize( ) {
	_player				  = PlayerPtr( new Player( ) );
	_fighter			  = EnemyFighterPtr( new EnemyFighter( Vector( 60, 60 ), 64 ) );
	_anit_tank			  = EnemyAnitTankPtr( new EnemyAnitTank( Vector( 0, 600 ), 64 ) );
	_mini_balloon         = EnemyMiniBalloonPtr( new EnemyMiniBalloon( Vector( 100, 100 ), 64 ) );
	_interception_balloon = EnemyInterceptionBalloonPtr( new EnemyInterceptionBalloon( Vector( 200, 0 ), 64 ) );
}
