#include "cow.h"

using namespace std;

int Cow::num_cows =0 ;
Cow::Cow()
{
    name[0] = '\0';
    hobby = nullptr;
    weight = 0.0;
    num_cows++;

}
Cow::Cow(const char * nm, const char * ho, double wt)
{
    strcpy(name, nm);
    hobby = new char [strlen(ho)+1];
    strcpy(hobby, ho);
    weight = wt;
    num_cows++;
}
Cow::Cow(const Cow &c)
{
    num_cows++;
    strcpy(name,c.name);
    hobby = new char [strlen(c.hobby)+1];
    strcpy(hobby,c.hobby);
    weight = c.weight;
}
Cow::~Cow()
{
    delete [] hobby;
    cout << "usunieto: " << name << endl;
    num_cows--;
    cout << "Pozostało: " << num_cows << " krow"<< endl;
}
void Cow::ShowCow() const
{
    cout << "Imię: \n";
    cout << name << endl;
    cout << "Hobby: \n";
    if(hobby == nullptr)
        cout << "Brak"<< endl;
    else
        cout << hobby << endl;
    cout << "Waga: \n";
    cout << weight << endl;
}
Cow &Cow::operator=(const Cow & c)
{
    delete [] hobby;
    hobby = new char [strlen(c.hobby)+1];
    strcpy(name,c.name);
    
    strcpy(hobby,c.hobby);
    weight = c.weight;
    return *this;

}
   