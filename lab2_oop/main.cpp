#include "triangle.h"
#include <iostream>
#include <array>

int main(void)
{
    std::array<Point, 3> triangle_coordinates = get_triangle_coordinates();
    if (!is_triangle_valid(triangle_coordinates))
    {
        std::cout << "The triangle is degenerate.\n";
        return 1;
    }
    // printf("Triangle coordinates:\n");
    // for (int i = 0; i < 3; ++i)
    // {
    //     std::cout << "Point " << char(65+i) << ": (" << triangle_coordinates[i].x << ", " << triangle_coordinates[i].y << ")\n";
    // }
    std::array<Point, 3> triangle_sides  = get_triangle_sides(triangle_coordinates);
    // printf("Triangle sides:\n");
    // for (int i = 0; i < 3; ++i)
    // {
    //     std::cout << "Side "<< ": (" << triangle_sides[i].x << ", " << triangle_sides[i].y << ")\n";
    // }
    check_points("coordinates.txt", triangle_coordinates, triangle_sides);
    return 0;
}