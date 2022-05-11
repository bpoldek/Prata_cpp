#include <iostream>
#include "coordin.h"
int main()
{
    using namespace std;
    rect rplace;
    polar pplace;
    
    cout << "Podaj wartoi x i y: ";
    while(cin >> rplace.x >> rplace.y)
    {
        pplace = rect_to_polar(rplace);
        show_polar(pplace);
        cout << "Podaj nast liczny q, aby zakonczyc: ";
    }
    cout << "Gotowe \n";
    return 0;
}