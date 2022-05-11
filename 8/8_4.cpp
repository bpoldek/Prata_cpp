#include <iostream>

void swapr(int & a, int & b);
void swapp(int * p, int *q);
void swapv(int a, int b);

int main()
{
    using namespace std;

    int wallet1 = 300;
    int wallet2 = 350;

    cout << " Wallet 1 : " << wallet1;
    cout << " Wallet 2 : " << wallet2 << endl;

    cout << " ZMiana wartosci za pomoca referencji: \n";
    swapr(wallet1,wallet2);
    cout << " Wallet 1 : " << wallet1;
    cout << " Wallet 2 : " << wallet2 << endl;

    cout << " ZMiana wartosci za pomoca wskaznika: \n";
    swapp(&wallet1,&wallet2);
    cout << " Wallet 1 : " << wallet1;
    cout << " Wallet 2 : " << wallet2 << endl;

    cout << " ZMiana wartosci za pomoca wartosci: \n";
    swapv(wallet1,wallet2);
    cout << " Wallet 1 : " << wallet1;
    cout << " Wallet 2 : " << wallet2 << endl;
    return 0;
}
void swapr(int & a, int & b)
{
    int temp;

    temp = a;
    a = b;
    b = temp;

}
void swapp(int * p, int *q)
{
    int temp;

    temp = *p;
    *p = *q;
    *q = temp;
}
void swapv(int a, int b)
{
    int temp;

    temp = a;
    a = b;
    b = temp;
}