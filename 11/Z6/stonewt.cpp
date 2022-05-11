#include <iostream>
using std::cout;
#include "stonewt.h"

Stonewt::Stonewt(double lbs)
{
    mode = Pont;
    stone = int(lbs)/Lbs_per_stn;
    pds_left = int (lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs; 
}
Stonewt::Stonewt(int stn, double pds, double pds_lef)
{
    stone = stn;
    pounds = pds;
    pds_left = pds_lef;
    mode = Pont;
}
Stonewt::Stonewt(double weight, Mode form)
{
    mode = form;
    if(mode == Stone)
    {
        stone = int(weight);
        pounds = weight *Lbs_per_stn;
        pds_left = pounds - int(pounds);
    }
    else if(mode == Pont)
    {
        pounds = int(weight);
        stone = int(pounds)/Lbs_per_stn;
        pds_left =  weight -int(pounds);
    }
    else if(mode == Pont_frc)
    {
        stone = int(weight)/Lbs_per_stn;
        pds_left =  weight- int(weight);
        pounds = weight; 
    }

}
Stonewt::Stonewt()
{
    stone = pounds = pds_left = 0;
}
Stonewt::~Stonewt()
{

}
std::ostream & operator<<(std::ostream & os, const Stonewt & s)
{
    if(s.mode == Stone)
        std::cout <<"Kamieni: "<< s.stone;
    else if(s.mode == Pont)
        std::cout << "Funtów:  " << s.pounds;
    else if(s.mode == Pont_frc)
        std::cout << "Funtów:  " << s.pounds << " po przecinku " << s.pds_left;
    std::cout <<" || kamieni: "<< s.stone << " Funtów: " << s.pounds << " po przecinku " << s.pds_left;
    return os;
}
Stonewt Stonewt::operator+(const Stonewt &s)const
{
    return Stonewt(s.stone + stone, s.pounds + pounds, s.pds_left +pds_left);
}
Stonewt Stonewt::operator-(const Stonewt &s)const
{
    return Stonewt(stone - s.stone, pounds - s.pounds, pds_left - s.pds_left);
}
Stonewt Stonewt::operator*(const Stonewt &s)const
{
    return Stonewt(stone * s.stone, (pounds+pds_left) * (s.pounds+ s.pds_left), pds_left * s.pds_left);
}
Stonewt Stonewt::operator/(const Stonewt &s)const
{
    if(s.stone !=0)
        return Stonewt(stone / s.stone, (pounds+pds_left) / (s.pounds+ s.pds_left), pds_left / s.pds_left);
    else
        return Stonewt(stone / 1, (int(pounds)+pds_left) / (int(s.pounds)+ s.pds_left), pds_left / s.pds_left);
}
bool Stonewt::operator>(const Stonewt &s)const
{
    if((int(pounds)+pds_left)> (int(s.pounds)+ s.pds_left))
        return true;
    else
        return false;
}
bool Stonewt::operator<(const Stonewt &s)const
{
    if((int(pounds)+pds_left)< (int(s.pounds)+ s.pds_left))
        return true;
    else
        return false;
}

