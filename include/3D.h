#ifndef THREED
#define THREED

#include "effects.h"

struct vec3d {
    float x, y, z;
    vec3d(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
}

struct Line {
    vec3d* start, end;
    Line(vec3d* _start, vec3d* _end) : start(_start), end(_end) {}
};

struct Face {
    vec3d* a, b, c;
    Face(vec3d* _a, vec3d* _b, vec3d* _c) : a(_a), b(_b), c(_c) {}
};

vec3d rotateVertX(vec3d old_vert, float angle, vec3d rotation_point);
vec3d rotateVertY(vec3d old_vert, float angle, vec3d rotation_point);
vec3d rotateVertZ(vec3d old_vert, float angle, vec3d rotation_point);

class Cube
{
    vec3d vertices[8];
    Line lines[12]
    Face face[12];

public:
    Cube(float size);
    void draw(CRGB *leds, float x, float y, CRGB color);
    void rotateX(float angle);
    void rotateY(float angle);
    void rotateZ(float angle);
};

#endif
