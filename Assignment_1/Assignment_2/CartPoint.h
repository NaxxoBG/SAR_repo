#pragma once
#include "Point.h"
#include <cstdlib>

struct cart_point;

typedef struct
{
	void (*point) (struct point*);
	cart_point* (*makeCartPoint) (double x, double y);
} cart_point_func_table;

typedef struct cart_point
{
	point* inherited;
	cart_point_func_table* vmt;
} cart_point;

void cart_point_cart_point(cart_point* p);
cart_point* cart_point_make_cart_point(double x, double y);

cart_point_func_table cart_point_vmt = {point_point, cart_point_make_cart_point};

inline void cart_point_cart_point(cart_point* p)
{
	point_point(p->inherited);
	p->vmt = &cart_point_vmt;
}


inline cart_point* cart_point_make_cart_point(const double x, const double y)
{
	const auto p = static_cast<cart_point*>(malloc(sizeof(struct cart_point)));
	p->inherited->x = x;
	p->inherited->y = y;
	return p;
}
