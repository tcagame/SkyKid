#pragma once
#include "smart_ptr.h"

class Scene  : public std::enable_shared_from_this< Scene >{
public:
	enum SCENE {
		SCENE_TITLE,
		SCENE_MAP,
		SCENE_RESULT,
		SCENE_CONTINUE
	};
public:
	Scene( );
	virtual ~Scene( );
public:
	virtual Scene::SCENE update( ) = 0;

};

