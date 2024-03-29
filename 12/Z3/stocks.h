#ifndef STOCKS_H_
#define STOCKS_H_

#include <string>

class Stock
{
private:
    char *company;
    long shares;
    double share_val;
    double total_val;
    void set_tot() { total_val = shares * share_val; }

public:
    Stock();
    Stock(const char *co, long n = 0, double pr = 0.0);
    ~Stock();
    void acqure(const char *co, long n, double pr);
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    friend std::ostream &operator<<(std::ostream &os, const Stock &st);
    void show() const;
    const Stock &topval(const Stock &s) const;
};
#endif