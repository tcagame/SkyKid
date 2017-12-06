#include "SceneMap.h"
#include "Player.h"
#include "Military.h"
#include "Armoury.h"

SceneMap::SceneMap( ) {
	_player	= PlayerPtr( new Player( ) );
	_military = MilitaryPtr( new Military( _player ) );
	_armoury = ArmouryPtr( new Armoury( _military ) );
	_player->setArmoury( _armoury );
}

SceneMap::~SceneMap( ) {
}

void SceneMap::update( ) {
	_player->update( );
	_military->update( );
	_armoury->update( );
}