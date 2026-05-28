#include "Dyhotomia_class.h"
#include <iostream>
#include <cmath> 

Dyhotomia_class::Dyhotomia_class() {}

Dyhotomia_class::~Dyhotomia_class() {}

void Dyhotomia_class::setVolumes(double vol_a, double vol_b) {
    a = vol_a;
    b = vol_b;
}

void Dyhotomia_class::setTolerance(double vol_eps) {
    eps = vol_eps;
}

double Dyhotomia_class::f(double x) {
    return std::sqrt(1.0 - 0.4 * x * x) - std::asin(x);
}

int Dyhotomia_class::count(double &x) {
    if (f(a) * f(b) > 0) {
        std::cout << "No root in the given interval." << std::endl;
        return -1; 
    }

    double c;
    do {
        c = (a + b) / 2.0;
        
        if (f(a) * f(c) < 0) 
        {
            b = c;
        } 
        else 
        {
            a = c;
        }
    } while (std::abs(b - a) > eps);

    x = (a + b) / 2.0;
    
    std::cout << "Found root: " << x << std::endl;

    std::cout << "f(" << x << ") = " << f(x) << std::endl;

    return 0; 
}