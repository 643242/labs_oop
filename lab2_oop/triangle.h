#ifndef TRIANGLE_H
#define TRIANGLE_H

struct Point {
    double x, y;
};

struct Triangle {
    Point A, B, C;
    
    double area() const;
    bool contains(const Point &P) const;
};

double vector_product(const Point& a, const Point& b);
Triangle get_triangle_coordinates();
bool is_triangle_valid(const Triangle& t);
void check_points(const Triangle& t);

#endif