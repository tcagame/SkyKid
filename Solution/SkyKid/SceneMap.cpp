#include "SceneMap.h"
#include "Player.h"
#include "Military.h"
#include "Armoury.h"
#include "Magazine.h"

#include "Drawer.h"
#include "Image.h"
#include "define.h"

const int MAP_SPEED = 3;

SceneMap::SceneMap( ) : 
_b_pos_x( 0 ),
_b_pos_y( 0 ),
_mx( 385 ),
_mx_1( 387 - MAP_WIDTH ),
_ty( 0 ),
_ty_1( 1 ) {
	_player	= PlayerPtr( new Player( ) );
	_magazine = MagazinePtr( new Magazine( ) );
	_military = MilitaryPtr( new Military( ) );
	_armoury = ArmouryPtr( new Armoury( ) );

	_player->setArmoury( _armoury );
	_military->setArmoury( _armoury );
	_military->setMagazine( _magazine );

	DrawerPtr drawer = Drawer::getTask( );
	_back = drawer->createImage( "back/Skykid_BG_map.png" );
}

SceneMap::~SceneMap( ) {
}

Scene::SCENE SceneMap::update( ) {
	moveBack( );
	draw( );

	_player->update( );
	_armoury->update( );
	_military->update( );
	_magazine->update( );

	return Scene::SCENE_CONTINUE;
}

void SceneMap::draw( ) {
	draw1( );
	draw2( );
}

void SceneMap::draw1( ) {
	_back->setRect( 0, MAP_HEIGHT * _ty, MAP_WIDTH, MAP_HEIGHT );
	_back->setPos( _mx, 0, MAP_WIDTH + _mx, MAP_HEIGHT );
	_back->draw( );
}
void SceneMap::draw2( ) {
	_back->setRect( 0, MAP_HEIGHT * _ty_1, MAP_WIDTH, MAP_HEIGHT );
	_back->setPos( _mx_1, 0, MAP_WIDTH + _mx_1, MAP_HEIGHT );
	_back->draw( );
}

void SceneMap::moveBack( ) {
	_mx += MAP_SPEED;
	_mx_1 += MAP_SPEED;
	if ( _mx > WINDOW_WIDTH ) {
		_mx = -MAP_WIDTH;
		_ty += 2;
	}
	if ( _mx_1 > WINDOW_WIDTH ) {
		_mx_1 = -MAP_WIDTH;
		_ty_1 += 2;
	}
}
