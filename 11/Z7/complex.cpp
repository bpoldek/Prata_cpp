#include "complex.h"

complex::complex()
{
    re = 0.0;
    im = 0.0;
}
complex::complex(double r)
{
    re = r;
    im = 0;
}
complex::complex(double r, double i)
{
    re = r;
    im = i;   
}
complex::~complex()
{

}
complex complex::operator+(complex &a)
{
    return complex(a.re +re, a.im + im);
}
complex complex::operator-(complex &a)
{
    return complex(re - a.re, im - a.im);
}
complex complex::operator*(complex &a)
{
    return complex((a.re * re)-(a.im *im), ((a.re * im)+(re*a.im)));
}
complex complex::operator*(double n)
{
    return complex(n * re, n * im);
}
complex complex::operator~()
{
    return complex(re ,-im);
}
std::ostream & operator<<(std::ostream & os, const complex & s)
{
    std::cout << "("<<s.re<<","<<s.im<<"i)";
    return os;
}
std::istream & operator>>(std::istream & is,complex & s)
{
    std::cout << "Skladowa Re: ";
    is >> s.re;
    std::cout << "Skladowa Im: ";
    is >> s.im;
    return is;
}