#ifndef THREED
#define THREED

#include "LRES_graphics.h"

struct vec3d {
    float x;
    float y;
    float z;
    vec3d(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
};

struct Line {
    vec3d* start;
    vec3d* end;
    Line(vec3d* _start, vec3d* _end) : start(_start), end(_end) {}
};

struct Face {
    vec3d* a;
    vec3d* b;
    vec3d* c;
    Face(vec3d* _a, vec3d* _b, vec3d* _c) : a(_a), b(_b), c(_c) {}
};

vec3d rotateVertX(vec3d old_vert, float angle, vec3d rotation_point);
vec3d rotateVertY(vec3d old_vert, float angle, vec3d rotation_point);
vec3d rotateVertZ(vec3d old_vert, float angle, vec3d rotation_point);

class Cube
{
    float halfSize;
    float z_offset = 0;
    vec3d vertices[8];
    Line lines[12];
    //Face face[12];

public:
    Cube(float size);
    void draw(Screen* screen, int x, int y, CRGB color);
    void rotateX(float angle);
    void rotateY(float angle);
    void rotateZ(float angle);
};

#endif
