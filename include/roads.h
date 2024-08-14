#ifndef ROADS___H
#define ROADS___H

#include <stdlib.h>

#include "points.h"

// Each tile contains this struct
typedef struct Road {
	// All roadtypes are explained in the RoadNetworkDesign.md file
	// 0 : no road
	// 1 : single tile road
	// 2 : 
	unsigned short int roadType;

} Road;



#endif
