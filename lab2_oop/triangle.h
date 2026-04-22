#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <array>
 
struct Point
{
    double x;
    double y;
};

std::array<Point,3> get_triangle_coordinates();
std::array<Point, 3> get_triangle_sides(const std::array<Point, 3>& coordinates );
double vector_product(const Point& a, const Point& b);
bool is_triangle_valid(const std::array<Point, 3>& triangle);
bool check_points(const char* filename, const std::array<Point, 3>& triangle, const std::array<Point, 3>& sides);


#endif