#include <iostream>
#include "Dyhotomia_class.h"
#include "Newton_class.h"

int main() {
    double tolerance = 0.001;
    double a, b;
    std::cout << "Enter the beginning of the interval (a): ";
    std::cin >> a;
    std::cout << "Enter the end of the interval (b): ";
    std::cin >> b;
    
    //1 method
    std::cout << "\n--- Dichotomy method ---" << std::endl;
    double x_dyh = 0.0;
    Dyhotomia_class* dyh = new Dyhotomia_class();
    
    dyh->setVolumes(a, b);
    dyh->setTolerance(tolerance);

    dyh->count(x_dyh);
    delete dyh;

    // 2 method
    std::cout << "\n--- Newton's method ---" << std::endl;
    double x_newton = 0.0;
    Newton_class* newton = new Newton_class();

    double first_guess = (a + b) / 2.0;
    newton->setInitialGuess(first_guess); 
    newton->setTolerance(tolerance);

    newton->count(x_newton);
    delete newton;

    return 0;
}