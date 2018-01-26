#include "SceneMap.h"
#include "Player.h"
#include "Military.h"
#include "Armoury.h"
#include "Magazine.h"
#include "Impact.h"

#include "Drawer.h"
#include "Image.h"
#include "define.h"


#include "Enemy.h"
#include "Player.h"
#include "EnemyFighter.h"
#include "EnemyAnitTank.h"
#include "EnemyMiniBalloon.h"
#include "EnemyInterceptionBalloon.h"
#include "EnemyTruck.h"
#include "EnemyAircraftGun.h"
#include "EnemyGunShot.h"
#include "EnemyBomber.h"
#include "EnemyFighter_1.h"

#include "Sound.h"

const int MAP_SPEED = 4;
const int GAMEOVER_COUNT = 120;

SceneMap::SceneMap( ) : 
_b_pos_x( 0 ),
_b_pos_y( 0 ),
_mx( 385 ),
_mx_1( 387 - MAP_WIDTH ),
_ty( 0 ),
_ty_1( 1 ),
_pop( false ),
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
	_game_crear = drawer->createImage( "ui/creal.png");
}

SceneMap::~SceneMap( ) {
}

Scene::SCENE SceneMap::update( ) {
	moveBack( );
	draw( );

	appearanceEnemy( );

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
	SoundPtr sound = Sound::getTask( );
	if ( _player->getAction( ) == Player::ACTION::ACTION_DEAD ) {
		_gameover_time++;
		drawGameOver( );
		if ( _gameover_time == 1 ) {
			_magazine->addImpact( ImpactPtr( new Impact( _player->getPos( ) ) ) );
			sound->playBGM( "sound/sky_music_gameover.wav" );
		}
	}
	if ( _player->getAction( ) == Player::ACTION::ACTION_CREAR ) {
		drawGameCrear( );
		sound->playBGM( "sound/sky_music_high_score.wav.wav" );
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
	if ( _ty_1 ==  7 ) {
		_player->setAction( Player::ACTION_CREAR );
	}
	_mx += MAP_SPEED;
	_mx_1 += MAP_SPEED;
	if ( _mx > WINDOW_WIDTH ) {
		_mx = -MAP_WIDTH;
		_ty += 2;
		_pop = false;
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

void SceneMap::drawGameCrear( ) {
	_game_crear->setRect( 0, 0 );
	_game_crear->setPos( WINDOW_WIDTH / 2 - 672 / 2, WINDOW_HEIGHT / 2 - 170 / 2 );
	_game_crear->draw( );
}

void SceneMap::appearanceEnemy( ) {
	if ( !_pop ) {
		switch( _ty ) {
		case 0:
			_military->addEnemy( EnemyPtr( new EnemyAnitTank( Vector( -40, 613 ), 64 ) ) ) ;
			_military->addEnemy( EnemyPtr( new EnemyAnitTank( Vector( -80, 613 ), 64 ) ) ) ;
			_military->addEnemy( EnemyPtr( new EnemyAnitTank( Vector( -120, 613 ), 64 ) ) ) ;
			_military->addEnemy( EnemyPtr( new EnemyTruck( Vector( 300, 598 ), 64 ) ) );
			_military->addEnemy( EnemyPtr( new EnemyTruck( Vector( 260, 598 ), 64 ) ) );
			_military->addEnemy( EnemyPtr( new EnemyFighter_1( Vector ( -140 , 80 ), NORMAL_CHIP_SIZE ) ) ); 
			_military->addEnemy( EnemyPtr( new EnemyFighter_1( Vector ( -100 , 120 ), NORMAL_CHIP_SIZE ) ) ); 
			_military->addEnemy( EnemyPtr( new EnemyFighter_1( Vector ( -60 , 160 ), NORMAL_CHIP_SIZE ) ) );
			_military->addEnemy( EnemyPtr( new EnemyFighter_1( Vector ( -500 , 500 ), NORMAL_CHIP_SIZE ) ) ); 
			_military->addEnemy( EnemyPtr( new EnemyFighter_1( Vector ( -460 , 460 ), NORMAL_CHIP_SIZE ) ) ); 
			_military->addEnemy( EnemyPtr( new EnemyFighter_1( Vector ( -420 , 420 ), NORMAL_CHIP_SIZE ) ) ); 
			_military->addEnemy( EnemyPtr( new EnemyFighter_1( Vector ( -380 , 380 ), NORMAL_CHIP_SIZE ) ) ); 
			_military->addEnemy( EnemyPtr( new EnemyFighter_1( Vector ( -500 ,200  ), NORMAL_CHIP_SIZE ) ) ); 
			_military->addEnemy( EnemyPtr( new EnemyMiniBalloon( Vector( -550, 155 ), 64 ) ) );
			_military->addEnemy( EnemyPtr( new EnemyMiniBalloon( Vector( -550, 210 ), 64 ) ) );
			_military->addEnemy( EnemyPtr( new EnemyMiniBalloon( Vector( -550, 265 ), 64 ) ) );
			_military->addEnemy( EnemyPtr( new EnemyMiniBalloon( Vector( -550, 320 ), 64 ) ) );
			
			_pop = true;
		break;
		case 2:
			_military->addEnemy( EnemyPtr( new EnemyAnitTank( Vector( -300, 600 ), 64 ) ) );
			_military->addEnemy( EnemyPtr( new EnemyTruck( Vector( -20, 400 ), 64 ) ) );
			_military->addEnemy( EnemyPtr( new EnemyAircraftGun( Vector( -100, 613 ), 32 ) ) );
			_military->addEnemy( EnemyPtr( new EnemyBomber( Vector( 1300, 100 ), 64 ) ) );
			_military->addEnemy( EnemyPtr( new EnemyInterceptionBalloon( Vector( -30, 0 ), 64 ) ) );
			_military->addEnemy( EnemyPtr( new EnemyInterceptionBalloon( Vector( -60, 30 ), 64 ) ) );
			_military->addEnemy( EnemyPtr( new EnemyInterceptionBalloon( Vector( -90, 60 ), 64 ) ) );
			_military->addEnemy( EnemyPtr( new EnemyInterceptionBalloon( Vector( -120, 90 ), 64 ) ) );
			_military->addEnemy( EnemyPtr( new EnemyInterceptionBalloon( Vector( -150, 120 ), 64 ) ) );
			_pop = true;
		break;
		case 4:
			_military->addEnemy( EnemyPtr( new EnemyAnitTank( Vector( -20, 600 ), 64 ) ) );
			_military->addEnemy( EnemyPtr( new EnemyTruck( Vector( -20, 400 ), 64 ) ) );
			_military->addEnemy( EnemyPtr( new EnemyAircraftGun( Vector( -20, 300 ), 32 ) ) );
			_military->addEnemy( EnemyPtr( new EnemyBomber( Vector( 1240, 100 ), 64 ) ) );
			_military->addEnemy( EnemyPtr( new EnemyFighter( Vector ( -45 , 100 ), NORMAL_CHIP_SIZE ) ) ); 
			_military->addEnemy( EnemyPtr( new EnemyFighter( Vector ( 0 , 100 ), NORMAL_CHIP_SIZE ) ) ); 
			_military->addEnemy( EnemyPtr( new EnemyFighter( Vector ( -20 , 140 ), NORMAL_CHIP_SIZE ) ) ); 
			_pop = true;
		break;
		case 6:
			_military->addEnemy( EnemyPtr( new EnemyAnitTank( Vector( -20, 600 ), 64 ) ) );
			_military->addEnemy( EnemyPtr( new EnemyTruck( Vector( -20, 400 ), 64 ) ) );
			_military->addEnemy( EnemyPtr( new EnemyAircraftGun( Vector( -20, 300 ), 32 ) ) );
			_military->addEnemy( EnemyPtr( new EnemyBomber( Vector( 1240, 100 ), 64 ) ) );
			_pop = true;
		break;
		case 8:
			_military->addEnemy( EnemyPtr( new EnemyAnitTank( Vector( -20, 600 ), 64 ) ) );
			_military->addEnemy( EnemyPtr( new EnemyTruck( Vector( -20, 400 ), 64 ) ) );
			_military->addEnemy( EnemyPtr( new EnemyAircraftGun( Vector( -20, 300 ), 32 ) ) );
			_military->addEnemy( EnemyPtr( new EnemyBomber( Vector( 1240, 100 ), 64 ) ) );
			_pop = true;
		break;
		}
	}
}
