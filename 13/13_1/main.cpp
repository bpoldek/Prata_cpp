#include <iostream>
#include "tabtenn0.h"

int main(void)
{
    using std::cout;
    TableTennisPlayer player1("Jacek", "Pogodny", true);
    TableTennisPlayer player2("Teresa", "Bogatko", false);
    player1.Name();
    if (player1.HasTable())
        cout << ": posiada stół.\n";
    else
        cout << ": nie posiada stołu.\n";
    player2.Name();
    if (player2.HasTable())
        cout << ": posiada stół.\n";
    else
        cout << ": nie posiada stołu.\n";

    return 0;
}