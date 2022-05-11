#include <iostream>
#include "task.h"
#include <list>
int main()
{
    {
        using namespace std;
        static char c;
        Register reg;
        Task temp;
        Task *temp_ptr;
        uint8_t num_of_task =0, idx=0;
        string in_str;
        

        ShowMenu();
        while(1)
        {
            
            cin >> c;
            switch (c)
            {
                case '1':
                    cout << "Dodawanie taska:";
                    cin.ignore();
                    getline(cin,in_str);
                    temp = temp.CreateTask(in_str);
                    temp_ptr = temp.FindTask(in_str,reg.TRG,num_of_task);
                    if(temp_ptr!=nullptr)
                    {
                        *temp_ptr = temp;
                    }
                    else if(temp_ptr==nullptr)
                    {
                        reg.TRG[num_of_task] = temp;
                        num_of_task++;
                    }
                    break;
                case '2':
                    cout << "Usuwanie taska, podaj ID: ";
                    cin.ignore();
                    getline(cin,in_str);
                    temp_ptr = reg.TRG[num_of_task].FindTask(in_str,reg.TRG,num_of_task);
                    if(temp_ptr==nullptr)
                    {
                        cout<<"Brak taska do usuniecia\n";  
                    }
                    else if(temp_ptr!=nullptr)
                    {
                        temp_ptr = ++temp_ptr;
                        temp_ptr->DeleteTask();
                        //num_of_task--;
                    }
                    break;
                case '3':
                    cout << "Znajdywanie taska, podaj ID: ";
                    cin.ignore();
                    getline(cin,in_str);
                    temp_ptr = reg.TRG[num_of_task].FindTask(in_str,reg.TRG,num_of_task);
                    //temp_ptr.ShowTask();
                case '4':
                    cin.ignore();
                    reg.ShowRegisters(reg.TRG, num_of_task);
                    break;
                case '5':
                    cin.ignore();
                    reg.ShowRegisters(reg.TRG, num_of_task);
                    break;
                case 'q':
                    cout << "Zakoncz";
                    break;
                default:
                    cout << "Bledna wartosc\n";
                    break;
            }
            ShowMenu();   
        }
        return 0;
    }

}