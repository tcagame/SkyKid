#pragma once

#include "Scene.h"
#include "smart_ptr.h"
PTR( Player );
PTR( Military );

class SceneMap : public Scene {
public:
	SceneMap( );
	virtual ~SceneMap( );
public:
	void update( );
private:
	PlayerPtr _player;
	MilitaryPtr _military;
};

