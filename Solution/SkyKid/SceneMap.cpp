#include "SceneMap.h"
#include "Player.h"
#include "Military.h"

SceneMap::SceneMap( ) {
	_player	= PlayerPtr( new Player( ) );
	_military = MilitaryPtr( new Military( _player ) );
}

SceneMap::~SceneMap( ) {
}

void SceneMap::update( ) {
	_player->update( );
	_military->update( );
}