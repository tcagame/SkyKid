#include "Magazine.h"
#include "Impact.h"

#include "define.h"

#include "Image.h"

Magazine::Magazine( ) {
}


Magazine::~Magazine( ) {
}

void Magazine::update( ) {
	std::list<ImpactPtr>::iterator ite = _impacts.begin( );
	while ( ite != _impacts.end( ) ) {
		ImpactPtr impact = *ite;
		impact->update( );
		if ( impact->getActTime( ) > 10 ) {
			ite = _impacts.erase( ite );
			continue;
		}
		ite++;
	}
}

void Magazine::addImpact( ImpactPtr impact ) {
	_impacts.push_back( impact );
}