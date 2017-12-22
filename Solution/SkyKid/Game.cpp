#include "Game.h"
#include "Application.h"

#include "Scene.h"
#include "SceneMap.h"
#include "SceneTitle.h"

#include "Drawer.h"
#include "Sound.h"


GamePtr Game::getTask( ) {
	ApplicationPtr app = Application::getInstance( );
	return std::dynamic_pointer_cast< Game >( app->getTask( Game::getTag( ) ) );
}

Game::Game( ) :
_next( Scene::SCENE_TITLE ) {
}


Game::~Game( ) {
}

void Game::update( ) {
	Drawer::getTask( )->flip( );
	changeScene( );
	_next = _scene->update( );
}

void Game::changeScene( ) {
	SoundPtr sound = Sound::getTask( );
	if ( _next == Scene::SCENE_CONTINUE ) {
        return;
    }
    switch( _next ) {
	case Scene::SCENE_TITLE:
        _scene = ScenePtr( new SceneTitle( ) );
		sound->playBGM( "sound/sky_music_start_music.wav" );
		break;
	case Scene::SCENE_MAP:
        _scene = ScenePtr( new SceneMap( ) );
		sound->playBGM( "sound/sky_music_skykidmarch.wav" );
		break;
	case Scene::SCENE_RESULT:
		break;
    }
}

	

void Game::initialize( ) {

}
