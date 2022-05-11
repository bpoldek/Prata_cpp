#include <iostream>
#include "string1.h"
const int ArSize = 10;
const int MaxLen = 81;

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    String name;
    cout << "Cześć, jak masz na imie?\n>> ";
    cin >> name;

    cout << name << " , wpisz do " << ArSize << " krótkich powiedzonek <pusty wiesz kończy wprowadzenie>\n";
    String sayings[ArSize];
    char temp[MaxLen];
    int i;
    for (i = 0; i < ArSize; i++)
    {
        cout << i+1 << ": ";
        cin.get(temp, MaxLen);
        while (cin && cin.get() != '\n')
            continue;
        if(!cin || temp[0]=='\0')
            break;
        else
            sayings[i] = temp;
    }
    int total = i;
    if(total >0)
    {
        cout <<"Oto Twoje powiedzonka:\n";
        for(i = 0; i < total; i++)
            cout << sayings[i][0] << ": " << sayings[i] << endl;
        int shortest = 0;
        int first = 0;
        for(i = 1; i < total; i++)
        {
            if(sayings[i].length() < sayings[shortest].length())
                shortest = i;
            if(sayings[i] < sayings[first])
                first = i;
        }
        cout << "Najkrótsze powiedzonko: \n" << sayings[shortest] << endl;
        cout << "Powiedzonko alfabetycznie pierwsze: \n" << sayings[first] << endl;
        cout << "Program wykorzystał " << String::HowMany() << " obiektow klasy String\n"; 
    }
    else
        cout << "brak danych!\n";
    return 0;
}