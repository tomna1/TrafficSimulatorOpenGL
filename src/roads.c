#include "roads.h"



unsigned int getEstimateDistancebb(basicRoad *road1, basicRoad *road2) {
	return (abs(road1->x - road2->x) + abs(road1->y - road2->y));
}