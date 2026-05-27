#include "Newton_class.h"
#include <iostream>
#include <cmath>

Newton_class::Newton_class() {}
Newton_class::~Newton_class() {}

void Newton_class::setInitialGuess(double guess) {
    x0 = guess;
}

void Newton_class::setTolerance(double vol_eps) {
    eps = vol_eps;
}

// func
double Newton_class::f(double x) {
    return std::sqrt(1.0 - 0.4 * x * x) - std::asin(x);
}


double Newton_class::df(double x) {
    double dx = 1e-6; 
    return (f(x + dx) - f(x)) / dx;
}

int Newton_class::count(double &x_out) {
    double x_curr = x0;
    double x_next;
    int max_iter = 100;

    for (int i = 0; i < max_iter; i++) {
        double derivative = df(x_curr);
        
        if (std::abs(derivative) < 1e-12) {
            std::cout << "ERROR: Derivative is close to zero." << std::endl;
            return -1; 
        }

        x_next = x_curr - f(x_curr) / derivative;

        if (std::abs(x_next - x_curr) <= eps) {
            x_out = x_next;

            std::cout << "Iterations: " << i + 1 << std::endl;
            std::cout << "Found root: " << x_out << std::endl;
            return 0;
        }

        x_curr = x_next;
    }

    std::cout << "ERROR: Maximum number of iterations exceeded." << std::endl;
    return -2;
}