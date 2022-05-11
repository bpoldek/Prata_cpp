#include <string>

namespace pers
{
    struct Pereson
    {
        std::string fname;
        std::string lname;

    };
    void getPerson(Pereson &);
    void showPerson(const Pereson &);
}

namespace debts
{
    using namespace pers;
    struct Debt
    {
        Pereson name;
        double amount;       /* data */
    };
    void getDebt(Debt &);
    void showDebt(const Debt &);
    double sumDebts(const Debt ar[], int en);
}