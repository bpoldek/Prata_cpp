#include <cstring>
#include "string2.h"
using std::cin;
using std::cout;

int String::num_strings = 0;

int String::HowMany()
{
    return num_strings;
}
String::String(const char *s)
{
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    num_strings++;
}
String::String()
{
    len = 4;
    str = new char[1];
    std::strcpy(str, "\0");
    num_strings++;
}
String::String(const String &st)
{
    num_strings++;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
}
String::~String()
{
    --num_strings;
    delete[] str;
}
String &String::operator=(const String &st)
{
    if (this == &st)
        return *this;
    delete[] str;
    len = st.len;
    str = new char[std::strlen(st.str) + 1];
    std::strcpy(str, st.str);
    return *this;
}
String &String::operator=(const char *s)
{
    delete[] str;
    len = std::strlen(s) - 1;
    str = new char[len + 1];
    std::strcpy(str, s);
    return *this;
}
char &String::operator[](int i)
{
    return str[i];
}
const char &String::operator[](int i) const
{
    return str[i];
}
bool operator<(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str, st2.str) < 0);
}
bool operator>(const String &st1, const String &st2)
{
    return st2 < st1;
}
bool operator==(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str, st2.str) == 0);
}
std::ostream &operator<<(std::ostream &os, const String &st)
{
    os << st.str;
    return os;
}
istream &operator>>(istream &is, String &st)
{
    int cnt = 0;
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is)
    {
        std::strcpy(st.str, temp);
        st.len = (std::strlen(st.str)) + 1;
    }
    while (is && is.get() != '\n')
    {
        cnt++;
        continue;
    }

    return is;
}
String operator+(const char *s, const String &st)
{
    String temp;
    temp.len = std::strlen(s) + st.len;
    temp.len -= 1;
    strcpy(temp.str, s);
    strcat(temp.str, st.str);
    return temp;
}
String operator+(const String &st1, const String &st2)
{
    String temp;
    temp.len = st1.len + st2.len;
    temp.len -= 1;
    strcpy(temp.str, st1.str);
    strcat(temp.str, st2.str);
    return temp;
}