#pragma once

#include <vector>
#include "quadtree_res.h"

using namespace std;

class quadtree_node
{
private:
	int q_capacity;
	int a_capacity;
	AABB boundary;

	point2D* objects_pos;
	//OBJ* objects_data;

	quadtree_node* nw;
	quadtree_node* ne;
	quadtree_node* sw;
	quadtree_node* se;

	void subdivide();
	
public:
	quadtree_node(int cap, AABB box);

	bool insert(point2D p); // (point2D p, OBJ x)
	vector<point2D> queryRange(AABB range);
	~quadtree_node(void);
};

