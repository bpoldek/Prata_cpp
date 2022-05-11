#ifndef COMPLEX_H_
#define COMPLEX_H_
#include <iostream>
class complex
{
    private:
        double re;
        double im;
    public:
        complex();
        complex(double r);
        complex(double r, double i);
        ~complex();
        complex operator+(complex &a);
        complex operator-(complex &a);
        complex operator*(complex &a);
        complex operator*(double a);
        complex operator~();
        friend std::ostream & operator<<(std::ostream & os, const complex & s);
        friend std::istream & operator>>(std::istream & os, complex & s);

};
#endif