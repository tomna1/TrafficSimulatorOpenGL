#ifndef GRID___H
#define GRID___H

#include "roads.h"

// The entire map is going to be split up into grids each taking a certain
// amount of tiles

typedef struct Tile {
	int x;
	int y;
	
	Road road;
} Tile;

typedef struct Grid {
	Tile gridTiles[10][10];
};



#endif
