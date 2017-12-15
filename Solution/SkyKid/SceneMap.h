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
	void moveBack( );
private:
	PlayerPtr _player;
	MilitaryPtr _military;
	ArmouryPtr _armoury;
	MagazinePtr _magazine;

	ImagePtr _back;
	int _b_pos_x;
	int _b_pos_y;
};

