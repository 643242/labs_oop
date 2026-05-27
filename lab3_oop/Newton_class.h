#ifndef NEWTON_CLASS_H
#define NEWTON_CLASS_H

class Newton_class {
private:
    double x0;
    double eps;
    
    double f(double x);
    double df(double x);

public:
    Newton_class();
    ~Newton_class();

    void setInitialGuess(double guess);
    void setTolerance(double vol_eps);
    int count(double &x_out);
};

#endif