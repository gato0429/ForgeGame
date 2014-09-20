#include "quadtree_res.h"

point2D::point2D(void)
{
	x = 0.0;
	y = 0.0;
}

point2D::point2D(const double &X, const double &Y)
{
	x = X;
	y = Y;
}

bool point2D::operator==(point2D &other) const
{
	return this->x == other.x && this->y == other.y;
}

AABB::AABB(void)
{
	this->bottom_left.x = 0.0;
	this->bottom_left.y = 0.0;
	this->top_right.x = 1.0;
	this->top_right.y = 1.0;
}

AABB::AABB(point2D bl, point2D tr)
{
	this->bottom_left = bl;
	this->top_right = tr;
}

AABB::~AABB(void)
{
}

bool AABB::containsPoint(point2D p){
	if(p.x >= bottom_left.x && p.x <= top_right.x &&
	   p.y >= bottom_left.y && p.y <= top_right.y )
		return true;
	return false;
}

bool AABB::intersectsAABB(AABB other){

	if(top_right.x < other.bottom_left.x)
		return false;

	if(top_right.y < other.bottom_left.y)
		return false;

	if(bottom_left.x > other.top_right.x)
		return false;

	if(bottom_left.y > other.top_right.y)
		return false;

	return true;
}

point2D AABB::getCenter()
{
	point2D center( (bottom_left.x + top_right.x)/2.0 ,(bottom_left.y + top_right.y)/2.0);
	return center;
}

point2D AABB::getBottomLeft()
{
	return bottom_left;
}

point2D AABB::getTopRight()
{
	return top_right;
}
