#include "triangle.h"
#include <cmath>
#include <iostream>
#include <array>
#include <fstream>  

std::array<Point,3> get_triangle_coordinates()
{
    std::array<Point, 3> triangle;
    int ascii_letter = 65; //A  
    for (int i = 0; i < 3; ++i)
    {
        std::cout << "Write x and y(separate with space) for point " << char(ascii_letter+i) << ": ";
        std::cin >> triangle[i].x >> triangle[i].y;
    }
    return triangle;
}

std::array<Point, 3> get_triangle_sides(const std::array<Point, 3>& coordinates )
{
    std::array <Point, 3> sides; // AB, BC, CA
    for (int i = 0; i < 3; i++)
    {
        int next_i = (i == 2) ? 0 : i + 1;
        sides[i].x = coordinates[next_i].x - coordinates[i].x;
        sides[i].y = coordinates[next_i].y - coordinates[i].y;

    }
    return sides;
}

double vector_product(const Point& a, const Point& b)
{
    return a.x * b.y - a.y * b.x;
}   

bool is_triangle_valid(const std::array<Point, 3>& triangle) // чек на виродженість
{
    Point AB = {
        triangle[1].x - triangle[0].x,
        triangle[1].y - triangle[0].y
    };

    Point AC = {
        triangle[2].x - triangle[0].x,
        triangle[2].y - triangle[0].y
    };

    double area = vector_product(AB, AC);

    if (std::abs(area) < 1e-9)
    {
        return false;
    }
    return true;
}

bool check_points(const char* filename, const std::array<Point, 3>& triangle_coordinates, const std::array<Point, 3>& sides)
{
    std::ifstream coordinates_txt(filename);
    if (!coordinates_txt.is_open())
    {
        printf("Cannot open file\n");
        return false;
    }

    double x, y;
    while (coordinates_txt >> x >> y)
    {
        Point P = {x, y};

        Point AP = {P.x - triangle_coordinates[0].x, P.y - triangle_coordinates[0].y};
        Point BP = {P.x - triangle_coordinates[1].x, P.y - triangle_coordinates[1].y};
        Point CP = {P.x - triangle_coordinates[2].x, P.y - triangle_coordinates[2].y};

        double D1 = vector_product(sides[0], AP);
        double D2 = vector_product(sides[1], BP);
        double D3 = vector_product(sides[2], CP);

        if ((D1 > 0 && D2 > 0 && D3 > 0) || (D1 < 0 && D2 < 0 && D3 < 0)) 
        {
            std::cout << "Point (" << x << ", " << y << ") is inside\n";
        }
        else if (D1 == 0 || D2 == 0 || D3 == 0) 
        {       
            if ((D1 >= 0 && D2 >= 0 && D3 >= 0) || (D1 <= 0 && D2 <= 0 && D3 <= 0))     
            {
                std::cout << "Point (" << x << ", " << y << ") is on the edge\n";
            } 
            else 
            {
                std::cout << "Point (" << x << ", " << y << ") is outside\n";
            }
        }
        else 
        {
            std::cout << "Point (" << x << ", " << y << ") is outside\n";
        }
    }
    return true;
}
