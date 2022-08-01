#include <iostream>
#include "classic.h"

using namespace std;

void Bravo(const Cd &disk);

int main()
{
    Cd c1("Beatels", "Capitol", 14, 35.5);
    Classic c2 = Classic("Sonata fortepianowa B-dur", "Fantazja C-moll", "Alfred Brendel", "Philips", 2, 57.17);

    Cd *pcd = &c1;

    cout << "Bezpośrednie użycie obiektu: \n";
    c1.Report();
    c2.Report();

    cout << "Użycie wskaźnika na typ Cd: \n";
    pcd->Report();
    pcd = &c2;
    pcd->Report();

    cout << "Wywołanie funkcji z argumentem w postaci referencji do typu Cd: \n";
    Bravo(c1);
    Bravo(c2);

    cout << "Test Przypisania: ";
    Classic copy;
    copy = c2;
    copy.Report();

    return 0;
}

void Bravo(const Cd &disk)
{
    disk.Report();
}