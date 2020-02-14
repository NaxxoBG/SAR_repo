#pragma once

struct point;

typedef struct
{
	void (*point)(struct point*);
	double (*get_x)(struct point*);
	double (*get_y)(struct point*);
} point_func_table;

typedef struct point
{
	double x;
	double y;
	point_func_table* vmt;
} point;

void point_point(point* p);
double point_get_x(point* p);
double point_get_y(point* p);

point_func_table point_vmt = {point_point, point_get_x, point_get_y};

inline void point_point(point* p, const double x, const double y)
{
	p->vmt = &point_vmt;
	p->x = x;
	p->y = y;
}

inline double point_get_x(point* p) { return p->x; }
inline double point_get_y(point* p) { return p->y; }
