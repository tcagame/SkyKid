#pragma once
#include "smart_ptr.h"
#include <list>

PTR( Impact );

class Magazine {
public:
	Magazine( );
	virtual ~Magazine( );
public:
	void update( );
	void addImpact( ImpactPtr impact );
private:
	std::list< ImpactPtr > _impacts;

};