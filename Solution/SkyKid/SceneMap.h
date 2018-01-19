#pragma once

#include "Scene.h"
#include "smart_ptr.h"

PTR( Player );
PTR( Military );
PTR( Armoury );
PTR( Image );
PTR( Magazine );


class SceneMap : public Scene {
public:
	SceneMap( );
	virtual ~SceneMap( );
public:
	Scene::SCENE update( );
private:
	void draw( );
	void draw1( );
	void draw2( );
	void moveBack( );
	void drawGameOver( );
private:
	PlayerPtr _player;
	MilitaryPtr _military;
	ArmouryPtr _armoury;
	MagazinePtr _magazine;

	ImagePtr _back;
	ImagePtr _game_over;
	int _b_pos_x;
	int _b_pos_y;

	int _mx;
	int _mx_1;
	int _ty;
	int _ty_1;

	int _gameover_time;
};

