#include <iostream>
using std::cout;
#include "stonewt.h"

void display(const Stonewt & st, int n);
int main()
{
    Stonewt incognito1(21.8, Stone);
    Stonewt incognito2(21.8, Pont);
    Stonewt incognito3(21.8, Pont_frc);
    Stonewt mult1(1.5, Pont);
    Stonewt mult2(1.5, Pont);

    cout << "Incognicto1: " << incognito1 << std::endl;
    cout << "Incognicto2: " << incognito2 << std::endl;
    cout << "Incognicto3: " << incognito3 << std::endl;
    incognito1 = incognito1 + incognito2;
    cout << "Incognicto1: " << incognito1 << std::endl;
    incognito1 = incognito1 - incognito2;
    cout << "Incognicto1: " << incognito1 << std::endl;

    mult1 = mult1 * mult2;
    cout << " mult1 * mult2: " << mult1 << std::endl;

    return 0;
}
