#include "3D.h"

vec3d rotateVertX(vec3d old_vert, float angle, vec3d rotation_point)
{
    vec3d new_vert;

    new_vert.y = (old_vert.y - rotation_point.y) * cos(angle) - (old_vert.z - rotation_point.z) * sin(angle) + rotation_point.y;
    new_vert.z = (old_vert.y - rotation_point.y) * sin(angle) + (old_vert.z - rotation_point.z) * cos(angle) + rotation_point.z;

    old_vert.y = new_vert.y;
    old_vert.z = new_vert.z;

    return old_vert;
}

vec3d rotateVertY(vec3d old_vert, float angle, vec3d rotation_point)
{
    vec3d new_vert;

    new_vert.x = (old_vert.x - rotation_point.x) * cos(angle) - (old_vert.z - rotation_point.z) * sin(angle) + rotation_point.x;
    new_vert.z = (old_vert.x - rotation_point.x) * sin(angle) + (old_vert.z - rotation_point.z) * cos(angle) + rotation_point.z;

    old_vert.x = new_vert.x;
    old_vert.z = new_vert.z;

    return old_vert;
}

vec3d rotateVertZ(vec3d old_vert, float angle, vec3d rotation_point)
{
    vec3d new_vert;

    new_vert.x = (old_vert.x - rotation_point.x) * cos(angle) - (old_vert.y - rotation_point.y) * sin(angle) + rotation_point.x;
    new_vert.y = (old_vert.x - rotation_point.x) * sin(angle) + (old_vert.y - rotation_point.y) * cos(angle) + rotation_point.y;

    old_vert.x = new_vert.x;
    old_vert.y = new_vert.y;

    return old_vert;
}

Cube::Cube(float size) {
    float sh = size*.5;
    // Front
    vertices[0] = vec3d(-sh, sh, -sh);
    vertices[1] = vec3d(sh, sh, -sh);
    vertices[2] = vec3d(-sh, -sh, -sh);
    vertices[3] = vec3d(sh, -sh, -sh);

    line[0] = Line(&vertices[0], &vertices[1]);
    line[1] = Line(&vertices[1], &vertices[3]);
    line[2] = Line(&vertices[3], &vertices[2]);
    line[3] = Line(&vertices[2], &vertices[0]);

    // Back
    vertices[4] = vec3d(-sh, sh, sh);
    vertices[5] = vec3d(sh, sh, sh);
    vertices[6] = vec3d(-sh, -sh, sh);
    vertices[7] = vec3d(sh, -sh, sh);

    line[4] = Line(&vertices[4], &vertices[5]);
    line[5] = Line(&vertices[5], &vertices[7]);
    line[6] = Line(&vertices[7], &vertices[6]);
    line[7] = Line(&vertices[6], &vertices[4]);

    // Joining
    line[8] = Line(&vertices[0], &vertices[4]);
    line[9] = Line(&vertices[1], &vertices[5]);
    line[10] = Line(&vertices[2], &vertices[6]);
    line[11] = Line(&vertices[3], &vertices[7]);
}

void Cube::draw(CRGB *leds, float x, float y, CRGB color) {
    for (int i = 0; i < 6; i++)
        void drawLine(leds,
            (lines[i].start->x/lines[i].start->z)+x,
            (lines[i].start->y/lines[i].start->z)+y,
            (lines[i].end->x/lines[i].end->z)+x,
            (lines[i].end->y/lines[i].end->z)+y, color);
}

void Cube::rotateX(float angle) {
    for (int i = 0; i < 6; i++)
        vertices[i].x = rotateVertX(vertices[i], angle, vec3d(0, 0, 0));
}

void Cube::rotateY(float angle) {
    for (int i = 0; i < 6; i++)
        vertices[i].x = rotateVertY(vertices[i], angle, vec3d(0, 0, 0));
}

void Cube::rotateZ(float angle) {
    for (int i = 0; i < 6; i++)
        vertices[i].x = rotateVertZ(vertices[i], angle, vec3d(0, 0, 0));
}
