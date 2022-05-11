#include <cstring>
#include "string2.h"
using std::cout;
using std::cin;

int String::num_strings = 0;

int String::HowMany()
{
    return num_strings;
}
String::String(const char * s)
{
    len = std::strlen(s);
    str = new char[len +1];
    std::strcpy(str,s);
    num_strings++;
}
String::String()
{
    len = 4;
    str = new char[1];
    std::strcpy(str, "\0");
    num_strings++;
}
String::String(const String & st)
{
    num_strings++;
    len= st.len;
    str = new char[len+1];
    std::strcpy(str,st.str);
}
String::~String()
{
    --num_strings;
    delete [] str;
}
/*String & String::operator+(String &st)
{
    len = st.len + len;
    str = new char[len+1];
    std::strcat(str,st.str);
    return *this;
}
String & String::operator+( const char * s)
{
    len = std::strlen(s) + len;
    str = new char[len+1];
    std::strcat(str,s);
    return *this;
}*/
String & String::operator=(const String &st)
{
    if(this==&st)
        return *this;
    delete [] str;
    len = st.len;
    str = new char[len+1];
    std::strcpy(str, st.str);
    return *this;
}
String & String::operator=(const char * s)
{
    delete [] str;
    len = std::strlen(s);
    str = new char[len +1];
    std::strcpy(str, s);
    return *this;
}
char & String::operator[](int i)
{
    return str[i];
}
const char & String::operator[](int i) const
{
    return str[i];
}
bool operator<(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str,st2.str)<0);
}
bool operator>(const String &st1, const String &st2)
{
    return st2 <st1;
}
bool operator==(const String &st1, const String &st2)
{
    return(std::strcmp(st1.str, st2.str)==0);
}
std::ostream & operator<<(std::ostream & os, const String & st)
{
    os << st.str;
    return os;
}
istream & operator>>(istream & is, String &st)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if(is)
        st = temp;
    while(is&&is.get()!= '\n')
        continue;
    return is;
}
String operator+(const char * s, const String & st)
{
    String temp;
    temp.len = std::strlen(s) + st.len;
    strcpy(temp.str,s);
    strcat(temp.str, st.str);
    return temp;
}
String operator+(const String & st1, const String & st2)
{
    String temp;
    temp.len = st1.len + st2.len;
    strcpy(temp.str, st1.str);
    strcat(temp.str, st2.str);
    return temp;
}