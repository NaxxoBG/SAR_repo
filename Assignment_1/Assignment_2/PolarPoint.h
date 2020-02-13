#pragma once
#include "Point.h"

struct PolarPoint;

typedef struct {
	void(*Point) (struct Point*);
	PolarPoint* (*makePolarPoint) (double x, double y);
} PolarPoint_functable;

typedef struct PolarPoint {
	Point inherited;
	PolarPoint_functable *vmt;
} PolarPoint;

PolarPoint* PolarPoint_makePolarPoint(double x, double y);

PolarPoint_functable PolarPoint_vmt = { Point_Point, PolarPoint_makePolarPoint };

void PolarPoint_PolarPoint(PolarPoint *p) 
{
	Point_Point(p->inherited);
	p->vmt = &PolarPoint_vmt;
}

PolarPoint* PolarPoint_makePolarPoint(const double x, const double y)
{
	struct PolarPoint* p = (PolarPoint*)malloc(sizeof(struct PolarPoint));
	p->inherited.x = x;
	p->inherited.y = y;
	return p;
}