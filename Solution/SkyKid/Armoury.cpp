#include "Armoury.h"

#include "Shot.h"
#include "define.h"

#include "Military.h"

#include "Magazine.h"
#include "Impact.h"


Armoury::Armoury( ) {
}


Armoury::~Armoury( ) {
}

void Armoury::update( ) {
	std::list<ShotPtr>::iterator ite = _shots.begin( );
	while ( ite != _shots.end( ) ) {
		ShotPtr shot = *ite;
		shot->update( );

		ite++;
	}
}

void Armoury::addShot( ShotPtr shot ) {
	_shots.push_back( shot );
}

std::list<ShotPtr> Armoury::getShotList( ) const {
	return _shots;
}





