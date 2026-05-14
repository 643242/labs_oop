#include "triangle.h"
#include <iostream>

int main(void)
{
    Triangle t = get_triangle_coordinates();

    if (!is_triangle_valid(t))
    {
        std::cout << "The triangle is degenerate.\n";
    }
    check_points(t);

    return 0;
}