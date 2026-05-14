#include "triangle.h"
#include <cmath>
#include <iostream>

double vector_product(const Point& a, const Point& b)
{
    return a.x * b.y - a.y * b.x;
}   

double Triangle::area() const {
    Point AB = {B.x - A.x, B.y - A.y};
    Point AC = {C.x - A.x, C.y - A.y};
    return std::abs(vector_product(AB, AC)) / 2.0; 
}

bool Triangle::contains(const Point &P) const {
    Triangle T1 = {A, B, P};
    Triangle T2 = {B, C, P};
    Triangle T3 = {C, A, P};

    double S_main = area();
    double S_sum = T1.area() + T2.area() + T3.area();

    return std::fabs(S_main - S_sum) < 1e-9;
}

Triangle get_triangle_coordinates()
{
    Triangle t;
    std::cout << "Write x and y(separate with space) for point A: ";
    std::cin >> t.A.x >> t.A.y;
    std::cout << "Write x and y(separate with space) for point B: ";
    std::cin >> t.B.x >> t.B.y;
    std::cout << "Write x and y(separate with space) for point C: ";
    std::cin >> t.C.x >> t.C.y;
    return t;
}

bool is_triangle_valid(const Triangle& t) 
{
    return t.area() >= 1e-9;
}

void check_points(const Triangle& t)
{
    int num_points;
    std::cout << "How many points do you want to check?: ";
    std::cin >> num_points;

    Point AB = {t.B.x - t.A.x, t.B.y - t.A.y};
    Point BC = {t.C.x - t.B.x, t.C.y - t.B.y};
    Point CA = {t.A.x - t.C.x, t.A.y - t.C.y};

    for (int i = 0; i < num_points; ++i)
    {
        double x, y;
        std::cout << "Write x and y (separate with space) for point " << i + 1 << ": ";
        std::cin >> x >> y;

        Point P = {x, y};

        Point AP = {P.x - t.A.x, P.y - t.A.y};
        Point BP = {P.x - t.B.x, P.y - t.B.y};
        Point CP = {P.x - t.C.x, P.y - t.C.y};

        double D1 = vector_product(AB, AP);
        double D2 = vector_product(BC, BP);
        double D3 = vector_product(CA, CP);

        bool on_AB = (std::abs(D1) < 1e-14) && (AP.x * BP.x <= 1e-14) && (AP.y * BP.y <= 1e-14);

        bool on_BC = (std::abs(D2) < 1e-14) && (BP.x * CP.x <= 1e-14) && (BP.y * CP.y <= 1e-14);

        bool on_CA = (std::abs(D3) < 1e-14) && (CP.x * AP.x <= 1e-14) && (CP.y * AP.y <= 1e-14);

        if (on_AB || on_BC || on_CA) 
        {
            std::cout << "Point (" << x << ", " << y << ") is on the edge\n";
        }
        else if ((D1 > 0 && D2 > 0 && D3 > 0) || (D1 < 0 && D2 < 0 && D3 < 0)) 
        {
            std::cout << "Point (" << x << ", " << y << ") is inside\n";
        }
        else 
        {
            std::cout << "Point (" << x << ", " << y << ") is outside\n";
        }
    }
}