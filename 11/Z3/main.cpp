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
    int  num = 0, min =0, max = 0;
    long int avg_steps = 0;
    int avg_sum = 0;
    cout <<"Podaj liczbe prob:";
    cin >> num;
    cout << "Podaj dystans do przejscia (k, aby zakonczyc) : ";
    cin >> target;
    cout << "Podaj dlugosc kroku: ";
    cin >> dstep;
    for (int i = 0; i < num; i++)
    { 
            while( result.magval() < target)
            {
                direction = rand() %360;
                step.reset(dstep, direction, Vector::POL);
                result = result + step;
                fout << result << endl;
                steps++;
            } 
            if(max < steps)
                max = steps;
            if(min > steps || min == 0)
                min = steps;
            avg_steps += steps;
            cout << i+1 <<". " << "Po " << steps << " krokach delkwent osiagnal polozenie : " << result;;
            result.polar_mode();
            cout << " czyli " << result << endl;
            //cout << " Srednia dlugosc kroku pozornego = " << result.magval()/steps << endl;
            steps = 0;
            result.reset(0.0 , 0.0);
    
        
    }
    avg_sum = avg_steps/num;
    cout<<"Minimalna dlugosc krokow to: "<< min << endl;
    cout<<"Maksymalana dlugos krokow to: "<< max << endl;
    cout<<"Średnia dlugos krokow to :" << avg_sum << endl;
    cout << "Koniec!\n";
    cin.clear();
    while(cin.get()!= '\n')
        continue;
    return 0;   
}