#include <iostream>
#include "brass.h"

using std::cout;
using std::endl;
using std::string;

typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();
void restore(format f, precis p);

Brass::Brass(const string &s, long an, double bal)
{
    fullName = s;
    acctNum = an;
    balance = bal;
}

void Brass::Deposit(double amt)
{
    if (amt < 0)
        cout << "NIe mozna wpłacić ujemnej kwoty; Wpłata anulowana.\n";
    else
        balance += amt;
}

void Brass::Withdraw(double amt)
{
    format initialState = setFormat();
    precis prec = cout.precision(2);
    if (amt < 0)
        cout << "Nie mozna wypłacić ujemnej kwoty; Wypłata anulowana.\n";
    else if (amt <= balance)
        balance -= amt;
    else
        cout << "Żądana suma " << amt << " zł przekracza dostępne środki.\nWypłata anulowana" << endl;
    restore(initialState, prec);
}
double Brass::Balance() const
{
    return balance;
}
void Brass::ViewAcct() const
{
    format initState = setFormat();
    precis prec = cout.precision(2);
    cout << "Klient: " << fullName << endl;
    cout << "Numer rachunku: " << acctNum << endl;
    cout << "Stan konta: " << balance << " zł" << endl;
    restore(initState, prec);
}

BrassPlus::BrassPlus(const string &s, long an, double bal, double ml, double r) : Brass(s, an, bal)
{
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}
BrassPlus::BrassPlus(const Brass &ba, double ml, double r) : Brass(ba)
{
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}
void BrassPlus::ViewAcct() const
{
    format initState = setFormat();
    precis prec = cout.precision(2);

    Brass::ViewAcct();
    cout << "Limit debetu: " << maxLoan << "zł" << endl;
    cout << "Kwota zadłużenia: " << owesBank << "zł" << endl;
    cout.precision(3);
    cout << "Stopa oprocentowania: " << 100 * rate << "%\n";
    restore(initState, prec);
}
void BrassPlus::Withdraw(double amt)
{
    format initState = setFormat();
    precis prec = cout.precision(2);
    double bal = Balance();
    if (amt <= bal)
        Brass::Withdraw(amt);
    else if (amt < bal + maxLoan - owesBank)
    {
        double advance = amt - bal;
        owesBank += advance * (1.0 + rate);
        cout << "Zadłużenie faktyczne: " << advance << "zł" << endl;
        cout << "Odsetki: " << advance * rate << "zł" << endl;
        Deposit(advance);
        Brass::Withdraw(amt);
    }
    else
        cout << "Przekorczony limit debetu. Operacja anulowana.\n";
    restore(initState, prec);
}
format setFormat()
{
    return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}
void restore(format f, precis p)
{
    cout.setf(f, std::ios_base::floatfield);
    cout.precision(p);
}