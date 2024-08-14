# My road network explained.

The entire map will be made of tiles (1 wide and 1 long) which can each fit 1 road. A road may look and function different
depending on the roads connected to it. This section will show all of the different road types in my simulation.
For now, each road will only have one lane (though this may change later).

## Road Types

In this section, I will use illustrations to show what my road network would look like.


### Single tile road (0 road connections)

Below is an example of a tile with a road. Since this road is not connected to any other roads, it does
not have any direction and would be useless in the simulation.

![Single tile road](/example_images/single_tile_road.png)

### Dead end road (1 road connection)

A dead end road is connection to a single straight road. It is pretty similar to the single tile road and in
the simulation will mostly be used as a destination or starting point where cars come from.

### Straight road (2 road connections)

A straight road is connected to 2 other roads both of which face the same direction. In the example below, there are
4 straight roads and 2 dead end roads.

![Straight road](/example_images/straight_road.png)

Note that the fact the roads are connected does matter. Simply there being tiles next to each other with roads does not
mean that the roads are connected. Take the image below as an example. You can see that there are 12 total tiles with roads
but the fact that some tiles are adjacent does not mean that the roads are connected. Connected roads are based on how the roads
were constructed in the road maker tool.

![2 Unconnected Roads](/example_images/2_unconnected_roads.png)

###  Curved roads (2 road connections)

A curved road is connected to 2 other roads which do not face the same direction. In the example below, there is a curved road in the
middle which is connected to 1 road which goes left to right and another road which goes up to down.

![Curved Road](/example_images/simple_curved_road.png)

Note that when I said the road goes left to right, it also goes right to left and likewise a road that goes up to down also goes
down to up. Roads in my simulation are bi-directional meaning you can go either way (1 direction per lane).

### T junctions (3 road connections)

If a single tile has a road which is connected to 3 other roads, that is defined as a T junction. A T junction consists of
a tile connected to 3 straight roads (2 of which face the same direction and 1 which doesnt). The 2 roads which face the same direction 
are called the major road and the 1 road which doesnt face the same direction is called the minor road. Cars on the major road have
priority over cars on the minor road. The major road is shown in red and the minor road is shown in black.

![T junction](/example_images/t_junction.png)

A T junction can also have traffic lights, which is defined by the tile the T junction is on. Below is an example of a T junction
with traffic lights. The green dots are the traffic lights and the green glow shows the direction the traffic lights will be viewed from.

![T junction with traffic lights](/example_images/t_junction_traffic_lights.png)

### 4 way Intersections (4 road connections)

If a single tile has a road which is connected to 4 other roads, that is defined as a 4 way intersection. Unlike a T junction a 4 way 
intersection has to have traffic lights to function. Below is an example.

![4 way intersection](/example_images/four_way_intersection_traffic_lights.png)


## Road Connections Implementation

My entire map will be a graph that is made up of nodes and vertices. Each node will be a road that either has 3 or more connections
(T junction and 4 way intersection) or a single connection (dead end road). Each edge will be the amount of straight and curved roads leading 
up to the node. In the example below there is a simple road network with 3 dead ends, 1 T junction (no traffic lights) and straight and curved
roads which connect them. The nodes in this case would be the tiles which contains the 3 dead ends and 1 T junction. In the image, the node
tile are pink and labelled with a number (1-4). 

![Simple road network](/example_images/simple_road_network.png)

This would be implemented with a graph that contains the 4 nodes. The nodes contain their tile values. The graph would also contains edges
which represent the road network connecting 2 nodes. For example an edge between Node 1 and Node 2 on the above image will be stored in both
the node1 and node2 objects (maybe as a linked link) and would contain a pointer to the node it is connecting to and a weighting (in this
case the weighting would be 10 since there are 7 straight roads and 3 curved roads which connect the nodes).

This graph network would be used for implementations of shortest path algorithms so the cars would know where to go. It wouldnt tell the cars
the exact roads to go on but tell them which nodes to go to. Since there should only be 1 path between 2 nodes, there is no need for a algorithm
to find the path between nodes (Hopefully).




## Cars per road

In this section I will specify how many cars have fit onto each different tile that with a different road type.

DO THIS LATER


