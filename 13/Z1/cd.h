#include <iostream>

class Cd
{
    private:
        char performers[50];
        char label[20];
        int slections;
        double playtime;
    public:
        Cd(const Cd & d);
        Cd();
        ~Cd();
        void Report() const;
        Cd & operator( Cd & d);
}