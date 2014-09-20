#pragma once

struct point2D{
	double x,y;
	point2D(void);
	point2D(const double &X, const double &Y);

	bool operator==(point2D &other) const;
};

class AABB
{
private:
	point2D bottom_left;
	point2D top_right;

public:
	AABB(void);
	AABB(point2D bl, point2D tr);
	bool containsPoint(point2D p);
	bool intersectsAABB(AABB other);

	point2D getCenter();
	point2D getBottomLeft();
	point2D getTopRight();


	virtual ~AABB(void);
};

