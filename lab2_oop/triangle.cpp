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

long double distance(const Point& p1, const Point& p2) {
    long double dx = (long double)p1.x - (long double)p2.x;
    long double dy = (long double)p1.y - (long double)p2.y;
    return std::sqrt(dx * dx + dy * dy);}

long double heron_area(const Point& A, const Point& B, const Point& C) {
    return std::abs((A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y)) / 2.0);
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

        // 1.cross product
        Point AP = {P.x - t.A.x, P.y - t.A.y};
        Point BP = {P.x - t.B.x, P.y - t.B.y};
        Point CP = {P.x - t.C.x, P.y - t.C.y};

        double D1 = vector_product(AB, AP);
        double D2 = vector_product(BC, BP);
        double D3 = vector_product(CA, CP);

        bool on_AB = (std::abs(D1) < 1e-14) && (AP.x * BP.x <= 1e-14) && (AP.y * BP.y <= 1e-14);
        bool on_BC = (std::abs(D2) < 1e-14) && (BP.x * CP.x <= 1e-14) && (BP.y * CP.y <= 1e-14);
        bool on_CA = (std::abs(D3) < 1e-14) && (CP.x * AP.x <= 1e-14) && (CP.y * AP.y <= 1e-14);

        std::cout << "Vector product: Point (" << x << ", " << y << ") ";
        if (on_AB || on_BC || on_CA) 
        {
            std::cout << "is on the edge\n";
        }
        else if ((D1 > 0 && D2 > 0 && D3 > 0) || (D1 < 0 && D2 < 0 && D3 < 0)) 
        {
            std::cout << "is inside\n";
        }
        else 
        {
            std::cout << "is outside\n";
        }

        // Heron
        long double A_main = heron_area(t.A, t.B, t.C);
        long double heron_epsilon = 1e-14; 

        std::cout << "Heron: Point (" << x << ", " << y << ") ";

        if (A_main < heron_epsilon) 
        {
            long double dist_AB = distance(t.A, t.B);
            long double dist_BC = distance(t.B, t.C);
            long double dist_CA = distance(t.C, t.A);
            
            long double dist_AP = distance(t.A, P);
            long double dist_BP = distance(t.B, P);
            long double dist_CP = distance(t.C, P);

            if (std::abs((dist_AP + dist_BP) - dist_AB) < 1e-7 ||
                std::abs((dist_BP + dist_CP) - dist_BC) < 1e-7 ||
                std::abs((dist_CP + dist_AP) - dist_CA) < 1e-7) 
            {
                std::cout << "is on the edge\n";
            }
            else 
            {
                std::cout << "is outside\n";
            }
            continue; 
        }

        long double A1 = heron_area(t.A, t.B, P);
        long double A2 = heron_area(t.B, t.C, P);
        long double A3 = heron_area(t.C, t.A, P);
        long double diff = std::abs(A_main - (A1 + A2 + A3));

        if (diff > heron_epsilon) 
        {
            std::cout << "is outside\n";
        }
        else 
        {
            if (A1 < heron_epsilon || A2 < heron_epsilon || A3 < heron_epsilon) 
            {
                std::cout << "is on the edge\n";
            }
            else 
            {
                std::cout << "is inside\n";
            }
        }
    }
}