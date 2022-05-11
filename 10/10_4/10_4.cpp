#include <iostream>
#include "stocks.h"

int main()
{
    {
    using std::cout;
    using std::ios_base;

    cout << "Tworzenie nowych obiektow przy uzyciu konstruktorow\n";
    Stock stock1("NanoSmart", 20 , 12.50);
    stock1.show();
    Stock stock2("BurakPol", 2, 2.0);
    stock2.show();

    cout << " Przypisanie stock1 do stock2:\n";
    stock2 = stock1;
    cout <<" Po przypisaniu: \n";
    stock1.show();
    stock2.show();

    cout<< " Wyzerowanie obiektu konstruktorem\n";
    stock1 = Stock("FutroPOL", 10 , 50.0);
    cout << "Nowa wersja stock1: \n";
    stock1.show();
    }
    return 0;
}