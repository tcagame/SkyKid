#pragma once
#include "Scene.h"
#include "smart_ptr.h"

PTR( Image );

class SceneTitle:
	public Scene {
public:
	SceneTitle( );
	virtual ~SceneTitle( );
public:
	Scene::SCENE update( );
private:
	void draw( );
private:
	ImagePtr _image;
};

