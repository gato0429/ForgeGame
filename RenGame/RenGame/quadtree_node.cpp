#include "quadtree_node.h"


quadtree_node::quadtree_node(int cap, AABB box)
{
	this->q_capacity = cap;
	this->boundary = box;

	this->objects_pos = new point2D[q_capacity];
	//this->objects_data = new OBJ[q_capacity];
	this->a_capacity = 0;

	this->nw = NULL;
	this->sw = NULL;
	this->ne = NULL;
	this->se = NULL;

}


quadtree_node::~quadtree_node(void)
{
	delete [] objects_pos;
	//delete [] objects_data;
}


void quadtree_node:: subdivide(){
	if(nw != NULL)
		return;

	point2D c = boundary.getCenter();
	point2D bl = boundary.getBottomLeft();
	point2D tr = boundary.getTopRight();

	AABB box1(  point2D(bl.x,c.y)   ,  point2D(c.x,tr.y)  );
	AABB box2(  c   ,  tr );
	AABB box3(  bl  ,  c  );
	AABB box4(  point2D(c.x,bl.y)   ,  point2D(tr.x,c.y)  );

	nw = new quadtree_node(q_capacity,box1);
	ne = new quadtree_node(q_capacity,box2);
	sw = new quadtree_node(q_capacity,box3);
	se = new quadtree_node(q_capacity,box4);
	return;
}

bool quadtree_node::insert(point2D p)
{
	if(!boundary.containsPoint(p))
		return false;

	if(a_capacity < q_capacity){
		objects_pos[a_capacity] = p;
		//objects_data[a_capacity] = obj;
		a_capacity++;
		return true;
	}

	if(nw == NULL)
		subdivide();

	if (nw->insert(p)) return true;
    if (ne->insert(p)) return true;
    if (sw->insert(p)) return true;
    if (se->insert(p)) return true;

	return false;
}

vector<point2D> quadtree_node::queryRange(AABB range)
{
	vector<point2D> res;

	if(!boundary.intersectsAABB(range))
		return res;

	for (int i = 0; i < a_capacity; i++){
		if (range.containsPoint(objects_pos[i]))
			res.push_back(objects_pos[i]);
    }

	if(nw == NULL)
		return res;

	vector<point2D> resNW = nw->queryRange(range);
	vector<point2D> resNE = ne->queryRange(range);
	vector<point2D> resSW = sw->queryRange(range);
	vector<point2D> resSE = se->queryRange(range);

	res.insert(res.end(), resNW.begin(), resNW.end());
	res.insert(res.end(), resNE.begin(), resNE.end());
	res.insert(res.end(), resSW.begin(), resSW.end());
	res.insert(res.end(), resSE.begin(), resSE.end());

	return res;
}