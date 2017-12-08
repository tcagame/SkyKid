#include "SceneTitle.h"
#include "Device.h"
#include "Drawer.h"
#include "Image.h"


SceneTitle::SceneTitle( ) {
	DrawerPtr drawer = Drawer::getTask( );
	_image = drawer->createImage( "title/logo.png" );
}


SceneTitle::~SceneTitle( ) {
}

Scene::SCENE SceneTitle::update( ) {
	DevicePtr device = Device::getTask( );
	if ( device->getPush( ) == BUTTON_A ) {
		return Scene::SCENE_MAP;
	}
	draw( );
	return Scene::SCENE_CONTINUE;
}

void SceneTitle::draw( ) {
	_image->setRect( 0, 0 );
	_image->setPos( 350, 100 );
	_image->draw( );
}
