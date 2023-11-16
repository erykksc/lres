#include "3D.h"

vec3d rotateVertX(vec3d old_vert, float angle, vec3d rotation_point)
{
    vec3d new_vert = vec3d(0, 0, 0);

    new_vert.y = (old_vert.y - rotation_point.y) * cos(angle) - (old_vert.z - rotation_point.z) * sin(angle) + rotation_point.y;
    new_vert.z = (old_vert.y - rotation_point.y) * sin(angle) + (old_vert.z - rotation_point.z) * cos(angle) + rotation_point.z;

    old_vert.y = new_vert.y;
    old_vert.z = new_vert.z;

    return old_vert;
}

vec3d rotateVertY(vec3d old_vert, float angle, vec3d rotation_point)
{
    vec3d new_vert = vec3d(0, 0, 0);

    new_vert.x = (old_vert.x - rotation_point.x) * cos(angle) - (old_vert.z - rotation_point.z) * sin(angle) + rotation_point.x;
    new_vert.z = (old_vert.x - rotation_point.x) * sin(angle) + (old_vert.z - rotation_point.z) * cos(angle) + rotation_point.z;

    old_vert.x = new_vert.x;
    old_vert.z = new_vert.z;

    return old_vert;
}

vec3d rotateVertZ(vec3d old_vert, float angle, vec3d rotation_point)
{
    vec3d new_vert = vec3d(0, 0, 0);

    new_vert.x = (old_vert.x - rotation_point.x) * cos(angle) - (old_vert.y - rotation_point.y) * sin(angle) + rotation_point.x;
    new_vert.y = (old_vert.x - rotation_point.x) * sin(angle) + (old_vert.y - rotation_point.y) * cos(angle) + rotation_point.y;

    old_vert.x = new_vert.x;
    old_vert.y = new_vert.y;

    return old_vert;
}

Cube::Cube(float size)
    : halfSize(size*.5),
      vertices{
          vec3d(-halfSize, halfSize, -halfSize+z_offset),
          vec3d(halfSize, halfSize, -halfSize+z_offset),
          vec3d(-halfSize, -halfSize, -halfSize+z_offset),
          vec3d(halfSize, -halfSize, -halfSize+z_offset),
          vec3d(-halfSize, halfSize, halfSize+z_offset),
          vec3d(halfSize, halfSize, halfSize+z_offset),
          vec3d(-halfSize, -halfSize, halfSize+z_offset),
          vec3d(halfSize, -halfSize, halfSize+z_offset)
      },
      lines{
          Line(&vertices[0], &vertices[1]),
          Line(&vertices[1], &vertices[3]),
          Line(&vertices[3], &vertices[2]),
          Line(&vertices[2], &vertices[0]),
          Line(&vertices[4], &vertices[5]),
          Line(&vertices[5], &vertices[7]),
          Line(&vertices[7], &vertices[6]),
          Line(&vertices[6], &vertices[4]),
          Line(&vertices[0], &vertices[4]),
          Line(&vertices[1], &vertices[5]),
          Line(&vertices[2], &vertices[6]),
          Line(&vertices[3], &vertices[7])
      } {
}

void Cube::draw(Screen* screen, int x, int y, CRGB color)
{
    for (int i = 0; i < 12; i++)
    {
        drawLine(screen,
                 (lines[i].start->x) + x,
                 (lines[i].start->y) + y,
                 (lines[i].end->x) + x,
                 (lines[i].end->y) + y, color);
    }
}

void Cube::rotateX(float angle)
{
    vec3d origin = vec3d(0, 0, 0);
    for (int i = 0; i < 8; i++)
        vertices[i] = rotateVertX(vertices[i], angle, origin);
}

void Cube::rotateY(float angle)
{
    vec3d origin = vec3d(0, 0, 0);
    for (int i = 0; i < 8; i++)
        vertices[i] = rotateVertY(vertices[i], angle, origin);
}

void Cube::rotateZ(float angle)
{
    vec3d origin = vec3d(0, 0, 0);
    for (int i = 0; i < 8; i++)
        vertices[i] = rotateVertZ(vertices[i], angle, origin);
}
