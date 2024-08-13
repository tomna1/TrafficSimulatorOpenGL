#ifndef ROADS___H
#define ROADS___H

#include <stdlib.h>

#include "points.h"

typedef struct basicRoad {
	int x;
	int y;
	unsigned int length;
	unsigned int numOfEdges;
	// Connections can only be made up, left, right and down, from a road.
	void *connectedLeft;
	void *connectedRight;
	void *connectedUp;
	void *connectedDown;
} basicRoad;

// TODO: IMPROVE THIS ESTIMATE FUNCTION.
unsigned int getEstimateDistancebb(basicRoad *road1, basicRoad *road2);

#endif
