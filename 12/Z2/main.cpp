#include <iostream>
using namespace std;
#include "string2.h"

int main()
{
    String s1(" i uczę się C++.");
    String s2 = "Podaj swoje imie: ";
    String s3;

    cout << s2;
    cin >> s3;
    s2 = "Mam na imię " + s3;
    cout << s2 << ".\n";
    s2 = s2 + s1;
    /*s2.stringup();
    cout << "Ciąg\n" << s2 << "\nzawiera " << s2.has('A') << " 'A' .\n";
    s1 = "czerwona";
    string rgb[3] = { String s1, String("zielona"), String("niebieska")};
    cout << "Podaj nazwę barwy podsatwowej: ";
    String ans;
    bool sucess = false;
    while(cin>> ans)
    {
        ans.stringlow();
        for(int i = 0; i<3; i++)
        {
            if(ans == rgb[i])
            {
                cout << "Prawidłowo!\n";
                sucess = true;
                break
            }   
        }
        if(sucess)
            break;
        else
            cout << "Spróbuj ponownie!\n";
    }
    cout << "Żewgnam !\n";*/

    return 0;

}