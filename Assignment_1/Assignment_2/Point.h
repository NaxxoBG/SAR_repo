#pragma once
#include <cstdlib>

struct Point;

typedef struct
{
	void(*Point) (struct Point*);
	double (*getx)(struct Point*);
	double (*gety)(struct Point*);
} Point_functable;

typedef struct Point {
	double x;
	double y;
	Point_functable *vmt;
} Point;

void Point_Point(Point *p);
double Point_getx(Point* p);
double Point_gety(Point* p);

Point_functable Point_vmt = { Point_Point, Point_getx, Point_gety };

void Point_Point(Point* p, double x, double y) { p->vmt = &Point_vmt; p->x = x; p->y = y; }
double Point_getx(Point* p) { p->x; }
double Point_gety(Point* p) { return p->y; }
