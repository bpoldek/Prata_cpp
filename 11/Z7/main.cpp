#include <iostream>

#include "complex.h"
using namespace std;

int main()
{
    complex a(3.0, 4.0);
    complex c; 
    cout << "Podaj liczbe zespolona: \n";
    while(cin >> c )
    {
        cout << "c to " << c << "\n";
        cout << "sprzezenie z c to " << ~c << "\n";
        cout << "a to " << a << "\n";
        cout << "a + c wynosi: " << a + c << "\n";
        cout << "a - c wynosi: " << a - c << "\n";
        cout << "a * c wynosi: " << a * c << "\n";
        cout << "2 * c wynosi: " <<  c * 2 << "\n"; 
    }
    return 0;
}