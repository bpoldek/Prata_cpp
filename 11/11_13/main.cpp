#include <iostream>
#include <cstdlib>
#include <ctime>
#include "vect.h"
#include <fstream>
int main ()
{
    using namespace std;
    using VECTOR::Vector;
    ofstream fout;
    fout.open("marsz.txt");
    srand(time(0));
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    cout << "Podaj dystans do przejscia (k, aby zakonczyc) : ";
    while (cin >> target)
    {
        cout << "Podaj dlugosc kroku: ";
        if(!(cin >> dstep))
            break;
        while( result.magval() < target)
        {
            direction = rand() %360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            fout << result << endl;
            steps++;
        }
        cout << "Po " << steps << " krokach delkwent osiagnal polozenie : \n";
        cout << result << endl;
        result.polar_mode();
        cout << " czyli\n" << result << endl;
        cout << " Sredmoa dlugosc kroku pozornego = " << result.magval()/steps << endl;
        steps = 0;
        result.reset(0.0 , 0.0);
        cout << "Podaj dystans do przejscia (k, aby zakonczyc): ";
    }
    cout << "Koniec!\n";
    cin.clear();
    while(cin.get()!= '\n')
        continue;
    return 0;   
}