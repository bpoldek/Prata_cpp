#include <iostream>
using std::cout;
using std::cin;
#include "stonewt.h"

void display(const Stonewt & st, int n);
int main()
{
    Stonewt incognito1(21.8, Stone);
    Stonewt incognito2(21.8, Pont);
    Stonewt incognito3(21.8, Pont_frc);
    Stonewt mult1(1.5, Pont);
    Stonewt mult2(1.5, Pont);
    int min=0, max=0, cnt=1;
    Stonewt tab[6] = {(154), (401.2), (122.5) };
    for (size_t i = 0; i < 3; i++)
    {
        double input;
        cout << "Podaj wage w lbs " << i+3 << " elementu: ";
        cin >> input;
        tab[i+3] = input;
    }
    for (size_t i = 0; i < 6; i++)
    {
        if(tab[i]<tab[i-1] && i!=0)
            min = i;
        if(tab[i]>tab[i-1] && i!=0)
            max = i;
        //cout << tab[i] << std::endl;
        if(tab[0]<tab[i])
            cnt++;
    }
    for (size_t i = 0; i < 6; i++)
    {
       cout << tab[i] << std::endl;
    }
    cout <<"Min: "<<  min << " Max: "<< max << " Liczba elementow 11: "<< cnt << std::endl;
    
    /*cout << "Incognicto1: " << incognito1 << std::endl;
    cout << "Incognicto2: " << incognito2 << std::endl;
    cout << "Incognicto3: " << incognito3 << std::endl;
    incognito1 = incognito1 + incognito2;
    cout << "Incognicto1: " << incognito1 << std::endl;
    incognito1 = incognito1 - incognito2;
    cout << "Incognicto1: " << incognito1 << std::endl;

    mult1 = mult1 * mult2;
    cout << " mult1 * mult2: " << mult1 << std::endl;
    if(mult1 < mult2)
        cout << "1. [<] mult1 < mult2"<< std::endl;
    else
        cout << "1. [<] mult1 > mult2"<< std::endl;
    if(mult1 > mult2)
        cout << "1. [>] mult1 > mult2"<< std::endl;
    else
        cout << "1. [>] mult1 < mult2"<< std::endl;

    mult1 = mult1 / mult2;
    cout << " mult1 / mult2: " << mult1 << std::endl;*/

    return 0;
}
