#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue.h"
#include <assert.h>
#include <unistd.h>

const int MIN_PER_HR = 60;

bool newcustomer(double x);

int main()
{
    using ::std::cin;
    using ::std::cout;
    using ::std::endl;
    using ::std::ios_base;

    std::srand(std::time(0));

    int qs = 10;
    Queue line1(qs);
    Queue line2(qs);
    double avg = 0;
    int hours = 100;
    long cyclelimit = MIN_PER_HR * hours;

    double prehour = 1;

    double min_per_cust;
    min_per_cust = MIN_PER_HR / prehour;

    Item temp;
    long turnaways = 0;
    long customers = 0;
    long served = 0;
    long sum_line = 0;
    int wait_time = 0;
    long line_wait = 0;

    /* code */
    do
    {
        for (long int cycle = 0; cycle < cyclelimit; cycle++)
        {
            if (newcustomer(min_per_cust))
            {
                if (line1.isfull() && line2.isfull())
                    turnaways++;
                else if (line1.queuecount() > line2.queuecount())
                {
                    customers++;
                    temp.set(cycle);
                    line2.enqueue(temp);
                }
                else if (line1.queuecount() < line2.queuecount())
                {
                    customers++;
                    temp.set(cycle);
                    line1.enqueue(temp);
                }
                else
                {
                    customers++;
                    temp.set(cycle);
                    line1.enqueue(temp);
                }
            }
            if (wait_time <= 0 && !line1.isempty())
            {
                line1.dequeue(temp);
                wait_time = temp.ptime();
                line_wait += cycle - temp.when();
                /*if (line_wait < 0)
                    cout << "Blad: " << line_wait << endl;*/
                served++;
            }
            if (wait_time <= 0 && !line2.isempty())
            {
                line2.dequeue(temp);
                wait_time = temp.ptime();
                line_wait += cycle - temp.when();
                /*if (line_wait < 0)
                    cout << "Blad: " << line_wait << endl;*/
                served++;
            }
            if (wait_time > 0)
                wait_time--;
            sum_line += line1.queuecount();
            sum_line += line2.queuecount();
        }
        if (customers > 0)
        {
            avg = (double)line_wait / cyclelimit;
            cout << "liczba klientów przyjętych:  " << customers << endl;
            cout << "liczba klientow obsłużonych: " << served << endl;
            cout << "liczba klientow odesłanuych: " << turnaways << endl;
            cout << "     średnia długość kolejki: ";
            cout.precision(2);
            cout.setf(ios_base::fixed, ios_base::floatfield);
            cout.setf(ios_base::showpoint);
            cout << (double)sum_line / cyclelimit << endl;
            cout << "     średni czas oczekiwania: " << (double)line_wait / cyclelimit << " minut \n";
        }
        else
            cout << "Brak klientów!\n";
        cout << "Gotów!\n";
        prehour++;
        // sleep(1);
    } while (avg <= 1);
    return 0;
}
bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);
}