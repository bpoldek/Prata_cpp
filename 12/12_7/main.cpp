#include <iostream>
#include <cstdlib>
#include <ctime>

#include "string1.h"
const int ArSize = 10;
const int MaxLen = 81;

int main()
{
    using namespace std;

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
            cout << sayings[i] << endl;
        String *shortest = &sayings[0];
        String *first = &sayings[0];
        for(i = 1; i < total; i++)
        {
            if(sayings[i].length() < shortest ->length())
                shortest = &sayings[i];
            if(sayings[i] < *first)
                first = &sayings[i];
        }
        cout << "Najkrótsze powiedzonko: \n" << *shortest << endl;
        cout << "Powiedzonko alfabetycznie pierwsze: \n" << *first << endl;
        cout << "Program wykorzystał " << String::HowMany() << " obiektow klasy String\n"; 

        srand(time(0));
        int choice = rand() % total;
        String *favorite = new String (sayings[choice]);

        cout << "Moje ulubione powiedzonko to: \n" << *favorite << endl;
        delete favorite; 
    }
    else
        cout << "brak danych!\n";
    return 0;
}