#include <iostream>
#include <cstdlib>
#include <deque>
#include "task.h"
#include "test_vector.h"
#include <vector>

int main()
{
    {
        using namespace std;
        static char c;
        string in_str;
        Register Reg;
        ShowMenu();
        for (int i = 0; i < 14; i++)
        {
            Reg.AddTask(test[i]);
        }
        while(1)
        {
            
            cin >> c;
            switch (c)
            {
                case '1':
                    cout << "Adding task:";
                    cin.ignore();
                    getline(cin,in_str);
                    Reg.AddTask(in_str);  
                    break;
                case '2':
                    cout << "Deleting a task, enter ID: ";
                    cin.ignore();
                    getline(cin,in_str);
                    Reg.DeleteTask(in_str);
                    break;
                case '3':
                    cout << "Finding task, enter ID: ";
                    cin.ignore();
                    getline(cin,in_str);
                    Reg.FindShow((Reg.FindTask(in_str)));
                    break;
                case '4':
                    cin.ignore();
                    Reg.ShowRegisters();
                    Reg.SortTTL();
                    break;
                case '5':
                    cin.ignore();
                    Reg.ShowRegisters();
                    break;
                case 'q':
                    cout << "Zakoncz";
                    break;
                default:
                    cout << "Bledna wartosc\n";
                    break;
            }
            //system("cls");
            ShowMenu();   
        }
        return 0;
    }

}