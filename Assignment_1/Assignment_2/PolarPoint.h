#pragma once
#include "Point.h"
#include <cstdlib>

struct polar_point;

typedef struct
{
	void (*point) (struct point*);
	polar_point* (*make_polar_point) (double x, double y);
} polar_point_func_table;

typedef struct polar_point
{
	point* inherited;
	polar_point_func_table* vmt;
} polar_point;

polar_point* polar_point_make_polar_point(double x, double y);

polar_point_func_table polar_point_vmt = {point_point, polar_point_make_polar_point};

inline void polar_point_polar_point(polar_point* p)
{
	point_point(p->inherited);
	p->vmt = &polar_point_vmt;
}

inline polar_point* polar_point_make_polar_point(const double x, const double y)
{
	const auto p = static_cast<polar_point*>(malloc(sizeof(struct polar_point)));
	p->inherited->x = x;
	p->inherited->y = y;
	return p;
}
