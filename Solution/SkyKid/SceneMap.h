#pragma once

#include "Scene.h"
#include "smart_ptr.h"

PTR( Player );
PTR( Military );
PTR( Armoury );


class SceneMap : public Scene {
public:
	SceneMap( );
	virtual ~SceneMap( );
public:
	Scene::SCENE update( );
private:
	PlayerPtr _player;
	MilitaryPtr _military;
	ArmouryPtr _armoury;
};

