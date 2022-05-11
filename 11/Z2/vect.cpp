#include <cmath>
#include "vect.h"
using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;
namespace VECTOR
{
    const double Rad_to_deg = 45.0 /atan(1.0);
    double Vector::magval() const
    {
        return sqrt(x * x + y * y );
    }
    double Vector::angval() const
    {
        if(x==0.0 && y == 0.0)
            return 0.0;
        else
            return atan2(y,x);
    }
    void Vector::set_x()
    {
        x = x * cos(y);
    }
    void Vector::set_y()
    {
        y = x * sin(y);
    }
    Vector::Vector()
    {
        x = y = 0.0;
        mode = RECT;
    }
    double Vector::calc_mag(double n1, double n2)
    {
        return sqrt(n1 * n1 + n2 * n2);
    }
    double Vector::calc_ang(double n1, double n2)
    {
        if(n1==0.0 && n2 == 0.0)
            return  0.0;
        else
            return  atan2(n2,n1);
    }
    Vector::Vector(double n1, double n2, Mode from)
    {
        mode = from;
        if(from == RECT)
        {
            x = n1;
            y = n2;
        }
        else if(from == POL)
        {
            x = n1;
            y = n2;
            set_x();
            set_y();
        }
        else 
        {
            cout << "Niepoprawna wartosc trzeciego argumentu Vector() --";
            cout << "zeruje wektor\n";
            x = y  = 0.0;
            mode = RECT;
        }
    }
    void Vector::reset(double n1, double n2, Mode form)
    {
        mode = form;
        if(form == RECT)
        {
            x = n1;
            y = n2;
        }
        else if(form == POL)
        { 
            x = n1;
            y = n2;
            set_x();
            set_y();
        }
        else 
        {
            cout << "Niepoprawna wartosc trzeciego argumentu set() --";
            cout << "zeruje wektor\n";
            x = y = 0.0;
            mode = RECT;
        }
    }
    Vector::~Vector()
    {
    }
    void Vector::polar_mode()
    {
        mode = POL;
    }
    void Vector::rect_mode()
    {
        mode = RECT;
    }
    Vector Vector::operator+(const Vector & b) const
    {
        return Vector(x + b.x, y + b.y);
    }
    Vector Vector::operator-(const Vector &b) const
    {
        return Vector(x - b.x, y - b.y);
    }
    Vector Vector::operator-() const
    {
        return Vector(-x, -y);
    }

    Vector Vector::operator*(double n) const
    {
        return Vector(n* x, n * y);
    }
    Vector operator*(double n, const Vector &a)
    {
        return a * n;
    }
    std::ostream & operator<<(std::ostream & os, const Vector & v)
    {
        if( v.mode == Vector::RECT)
            os << "(x,y) = (" << v.x << ", "<< v.y <<")";
        else if(v.mode == Vector::POL)
        {
            os << "(m,a) = (" << v.magval() << ", " << v.angval() * Rad_to_deg <<")";
        }
        else
            os << "Niepoprawny tryb reprezentacji obiektu wektora";
        return os;
    }
}