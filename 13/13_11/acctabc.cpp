#include <iostream>
#include "acctabc.h"

using namespace std;

AcctABC::AcctABC(const string &s, long an, double bal)
{
    fullName = s;
    acctNum = an;
    balance = bal;
}
void AcctABC::Deposit(double amt)
{
    if (amt < 0)
        cout << "Nie możesz wpłacić ujemnej kwoty; Wpłata anulowana.\n";
    else
        balance += amt;
}
void AcctABC::Withdraw(double amt)
{
    balance -= amt;
}
AcctABC::Formatting AcctABC::SetFormat() const
{
    Formatting f;
    f.flag = cout.setf(ios_base::fixed, ios_base::floatfield);
    f.pr = cout.precision(2);
    return f;
}
void AcctABC::Restore(Formatting &f) const
{
    cout.setf(f.flag, ios_base::floatfield);
    cout.precision(f.pr);
}
void Brass::Withdraw(double amt)
{
    if (amt < 0)
        cout << "Nie można wypłacić ujemnej kwoty; Wypłata anulowana.\n";
    else if (amt <= Balance())
        AcctABC::Withdraw(amt);
    else
        cout << "Żądana wartosć " << amt << " zł przekracza dostępne środki.\n Wypłata anulowana.\n";
}
void Brass::ViewAcct() const
{
    Formatting f = SetFormat();
    cout << "Właśiciel rachunku Brass : " << Fullname() << endl;
    cout << "Numer rachunku: " << AcctNum() << endl;
    cout << "Stan konta: " << Balance() << " zł" << endl;
    Restore(f);
}
BrassPlus::BrassPlus(const string &s, long an, double bal, double ml, double r) : AcctABC(s, an, bal)
{
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}
BrassPlus::BrassPlus(const Brass &ba, double ml, double r) : AcctABC(ba)
{
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}
void BrassPlus::ViewAcct() const
{
    Formatting f = SetFormat();
    cout << "Właściciel rachunku BrassPlus: " << Fullname() << endl;
    cout << "Numer rachunku: " << AcctNum() << endl;
    cout << "Stan konta: " << Balance() << " zł" << endl;
    cout << "Kwota zadłużenia: " << owesBank << " zł" << endl;
    cout.precision(3);
    cout << "Stopa oprocentowania: " << 100 * rate << "%\n";
    Restore(f);
}
void BrassPlus::Withdraw(double amt)
{
    Formatting f = SetFormat();

    double bal = Balance();
    if (amt <= bal)
        AcctABC::Withdraw(amt);
    else if (amt <= bal + maxLoan - owesBank)
    {
        double advance = amt - bal;
        owesBank += advance * (1.0 + rate);
        cout << "Zadłużenie faktyczne: " << advance << " zł" << endl;
        cout << "Odsetki :" << advance * rate << " zł" << endl;
        Deposit(advance);
        AcctABC::Withdraw(amt);
    }
    else
        cout << "Przekroczony limit debetu. Operacja anulowana.\n";
    Restore(f);
}