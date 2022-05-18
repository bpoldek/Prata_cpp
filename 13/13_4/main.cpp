#include <iostream>
#include "tabtenn1.h"

int main(void)
{
    using std::cout;
    using std::endl;
    TableTennisPlayer player1("Jacek", "Pogodny", true);
    RatedPlayer rplayer1(1140, "Maciej", "Kaczkowski", true);
    rplayer1.Name();
    if (rplayer1.HasTable())
        cout << ": posiada stół.\n";
    else
        cout << ": nie posiada stołu.\n";
    player1.Name();
    if (player1.HasTable())
        cout << ": posiada stół.\n";
    else 
        cout << ": nie posiada stołu.\n";
    cout << "Imie i nazwikso: ";
    rplayer1.Name();
    cout << "; Ranking: " << rplayer1.Rating() << endl;
    RatedPlayer rplayer2(1212, player1);
    cout << "Imie i nazwisko: ";

    rplayer2.Name();
    cout << ", Ranking: " << rplayer2.Rating() << endl;
    return 0;
}