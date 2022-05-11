#include <iostream>
using std::cout;
#include "stonewt.h"

void display(const Stonewt & st, int n);
int main()
{
    Stonewt incognito = 275;
    Stonewt wolfe(285.7);
    Stonewt taft(21, 8);

    cout << "Celebryta ważył: ";
    incognito.show_stn();
    cout << "Detektyw ważył: ";
    wolfe.show_stn();
    cout << "Prezydent ważył: ";
    taft.show_lbs();
    incognito = 276.8;
    taft = 325;
    cout << "Po obiedzie celebryta waży: ";
    incognito.show_stn();
    cout << "Prezydent waży: ";
    taft.show_lbs();
    display(taft, 2);
    cout << " a zapasnik wazy jeszcze wiecej \n" ;
    display(427 , 2);
    cout << "Nie pozostał kamień na kamieniu\n";
    
    return 0;
}
void display(const Stonewt & st, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << "Oho! ";
        st.show_stn();
    }
}