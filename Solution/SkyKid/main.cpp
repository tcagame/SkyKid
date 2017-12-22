#include "Application.h"
#include "Keyboard.h"
#include "Device.h"
#include "Game.h"
#include "Character.h"
#include "Drawer.h"
#include "Sound.h"

void main( ) {
	ApplicationPtr app = Application::getInstance( );
	app->setWindowSize( 1280, 720 );

	TaskPtr drawer = DrawerPtr( new Drawer( "Resources" ) );
	TaskPtr sound = SoundPtr( new Sound( "Resources" ) );
	TaskPtr game = GamePtr( new Game );
	TaskPtr keyboard = KeyboardPtr( new Keyboard );
	TaskPtr device = DevicePtr( new Device );


	app->addTask( Drawer::getTag( ), drawer );
	app->addTask( Sound::getTag( ), sound );
	app->addTask( Game::getTag( ), game );
	app->addTask( Keyboard::getTag( ), keyboard );
	app->addTask( Device::getTag( ), device );

}