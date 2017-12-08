#include "SceneMap.h"
#include "Player.h"
#include "Military.h"
#include "Armoury.h"
#include "Drawer.h"
#include "Image.h"
#include "define.h"

SceneMap::SceneMap( ) : 
_b_pos_x( 0 ),
_b_pos_y( 0 ) {
	_player	= PlayerPtr( new Player( ) );
	_military = MilitaryPtr( new Military( _player ) );
	_armoury = ArmouryPtr( new Armoury( _military ) );
	_player->setArmoury( _armoury );

	DrawerPtr drawer = Drawer::getTask( );
	_back = drawer->createImage( "back/back.png" );
}

SceneMap::~SceneMap( ) {
}

Scene::SCENE SceneMap::update( ) {
	draw( );

	_player->update( );
	_military->update( );
	_armoury->update( );

	return Scene::SCENE_CONTINUE;
}

void SceneMap::draw( ) {
	_back->setRect( 0, 0, 1024, 1024 );
	_back->setPos( 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT );
	_back->draw( );

}

void SceneMap::moveBack( ) {

}
