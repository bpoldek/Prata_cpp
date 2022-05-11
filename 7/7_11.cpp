#include <iostream>
struct  travel_time
{
    int hour;
    int min;
};

const int MIN_PRE_HR = 60;

travel_time sum(travel_time t1, travel_time t2);
void show_time(travel_time t);

int main()
{
    using namespace std;

    travel_time day1 = {5, 45};
    travel_time day2 = {4, 55};

    travel_time trip = sum(day1, day2);
    cout << "Suma dwch dni: ";
    show_time(trip);

    travel_time day3 = {4,32};
    cout << "suma trzech dni: ";
    show_time(sum(trip,day3));

    return 0;
}
travel_time sum(travel_time t1, travel_time t2)
{
    travel_time total;
    total.min = (t1.min + t2.min) % MIN_PRE_HR;
    total.hour = t1.hour + t2.hour + (t1.min + t2.min)/ MIN_PRE_HR;

    return total;
}
void show_time(travel_time t)
{
    using namespace std;
    cout<< t.hour << " godzin " << t.min << " minut \n";
}
