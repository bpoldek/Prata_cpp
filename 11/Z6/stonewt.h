#ifndef STONEWT_H_
#define STONEWT_H_

enum Mode {Stone, Pont, Pont_frc};
class Stonewt
{
    private:
        enum {Lbs_per_stn = 14};
        int stone;
        double pds_left;
        double pounds;
        Mode mode;
    public:
        Stonewt(double lbs);
        Stonewt(int stn, double pds, double pds_lef);
        Stonewt(double weight, Mode form);
        Stonewt();
        ~Stonewt();
        Stonewt operator+(const Stonewt &s)const;
        Stonewt operator-(const Stonewt &s)const;
        Stonewt operator*(const Stonewt &s)const;
        Stonewt operator/(const Stonewt &s)const;
        bool operator>(const Stonewt &s)const;
        bool operator<(const Stonewt &s)const;
        friend std::ostream & operator<<(std::ostream & os, const Stonewt & s);
};

#endif