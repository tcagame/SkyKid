#include "SceneTitle.h"
#include "Device.h"
#include "Drawer.h"
#include "Image.h"
#include "define.h"


SceneTitle::SceneTitle( ) {
	DrawerPtr drawer = Drawer::getTask( );
	_image = drawer->createImage( "title/logo.png" );
	_ui = drawer->createImage( "title/ui.png" );
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
	_image->setPos( WINDOW_WIDTH / 2 - 512 / 2, 70 );
	_image->draw( );

	_ui->setRect( 0, 0 );
	_ui->setPos( WINDOW_WIDTH / 2 - 512 / 2, WINDOW_HEIGHT / 3 * 2 );
	_ui->draw( );
}
