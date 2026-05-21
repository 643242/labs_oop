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

long double heron_area(const Point& A, const Point& B, const Point& C);
long double distance(const Point& p1, const Point& p2);


double vector_product(const Point& a, const Point& b);
Triangle get_triangle_coordinates();
bool is_triangle_valid(const Triangle& t);
void check_points(const Triangle& t);

#endif