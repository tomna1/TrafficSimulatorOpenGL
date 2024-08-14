#ifndef GRID___H
#define GRID___H

// The entire map is going to be split up into grids each taking a certain
// amount of tiles

typedef struct tile {
	int x;
	int y;
} tile;

typedef struct Grid {
	tile gridTiles[10][10];
};



#endif
