#include <iostream>
char * buildstr(char c, int n);

int main()
{
    using namespace std;
    int times;
    char ch;

    cout << "Podaj zank: " << endl;
    cin >> ch;
    cout << "Podaj liczbe calkowita: ";
    cin >> times;
    char *ps = buildstr(ch, times);
    cout << ps << endl;
    delete [] ps;
    ps = buildstr('+', 19);
    cout << ps << "-Gotowe-" << ps << endl;
    delete [] ps;

    return 0;
}
char * buildstr(char c, int n)
{
    char * pstr = new char [n +1];
    pstr[n] = '\0';
    while (n-- > 0)
    {
        pstr[n]=c;
    }
    return pstr;
}