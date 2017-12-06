#pragma once
#include "smart_ptr.h"


class Scene {
public:
	Scene( );
	virtual ~Scene( );
public:
	virtual void update( ) = 0;
private:

};

