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
        fout << "Dystans do przejscia :" << target << "długosc kroku: " << dstep << endl;
        while( result.magval() < target)
        {
            static int cnt= 0;
            direction = rand() %360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            fout << cnt <<". "<< result << endl;
            steps++;
            cnt++;
        }
        fout <<"Po " << steps << " krokach delkwent osiagnal polozenie : \n" << result << endl;
        result.polar_mode();
        fout << " czyli\n" << result << endl;
        fout << " Sredmoa dlugosc kroku pozornego = " << result.magval()/steps << endl;
        cout << "Po " << steps << " krokach delkwent osiagnal polozenie : \n";
        result.rect_mode();
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