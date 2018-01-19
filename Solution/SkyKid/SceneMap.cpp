#include "SceneMap.h"
#include "Player.h"
#include "Military.h"
#include "Armoury.h"
#include "Magazine.h"
#include "Impact.h"

#include "Drawer.h"
#include "Image.h"
#include "define.h"

const int MAP_SPEED = 3;
const int GAMEOVER_COUNT = 120;

SceneMap::SceneMap( ) : 
_b_pos_x( 0 ),
_b_pos_y( 0 ),
_mx( 385 ),
_mx_1( 387 - MAP_WIDTH ),
_ty( 0 ),
_ty_1( 1 ),
_gameover_time( 0 ) {
	_magazine = MagazinePtr( new Magazine( ) );
	_military = MilitaryPtr( new Military( ) );
	_armoury = ArmouryPtr( new Armoury( ) );
	_player	= PlayerPtr( new Player( ) );

	_player->setArmoury( _armoury );
	_player->setMilitary( _military );

	_military->setArmoury( _armoury );
	_military->setMagazine( _magazine );

	DrawerPtr drawer = Drawer::getTask( );
	_back = drawer->createImage( "back/Skykid_BG_map.png" );
	_game_over = drawer->createImage( "ui/gameover.png" );
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
		if ( _gameover_time > GAMEOVER_COUNT ) { 
			return Scene::SCENE_TITLE;
		}
	return Scene::SCENE_CONTINUE;
}

void SceneMap::draw( ) {
	draw1( );
	draw2( );
	if ( _player->getAction( ) == Player::ACTION::ACTION_DEAD ) {
		_gameover_time++;
		drawGameOver( );
		if ( _gameover_time == 1 ) {
			_magazine->addImpact( ImpactPtr( new Impact( _player->getPos( ) ) ) );
		}
	}
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

void SceneMap::drawGameOver( ) {
	_game_over->setRect( 0, 0 );
	_game_over->setPos( WINDOW_WIDTH / 2 - 672 / 2, WINDOW_HEIGHT / 2 - 170 / 2 );
	_game_over->draw( );
}
