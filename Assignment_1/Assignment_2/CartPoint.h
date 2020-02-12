#pragma once
#include "Point.h"

struct CartPoint;

typedef struct {
	void(*Point) (struct Point*);
	CartPoint* (*makeCartPoint) (double x, double y);
} CartPoint_functable;

typedef struct CartPoint {
	Point inherited;
	CartPoint_functable *vmt;
} CartPoint;

void CartPoint_CartPoint(CartPoint* p);
CartPoint* CartPoint_makeCartPoint(double x, double y);

CartPoint_functable CartPoint_vmt = {Point_Point, CartPoint_makeCartPoint };
void CartPoint_CartPoint(CartPoint* p) {
	Point_Point(p->inherited);
	p->vmt = &CartPoint_vmt;
}


CartPoint* CartPoint_makeCartPoint(const double x, const double y)
{
	struct CartPoint* p = (CartPoint*)malloc(sizeof(struct CartPoint));
	p->inherited.x = x;
	p->inherited.y = y;
	return p;
}