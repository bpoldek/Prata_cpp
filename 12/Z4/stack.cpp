#include <iostream>
#include <string.h>
#include "stack.h"

Stack::Stack(int n)
{
    size = n;
    pitems = new Item[size];
    top = 0;
}
Stack::Stack(const Stack &st)
{
    size = st.size;
    pitems = new Item[size];
    Item *adress = pitems;
    pitems = st.pitems;
    top = st.top;
    pitems -= top;
    memcpy(pitems, st.pitems, sizeof(Item));
    pitems = adress;
}
Stack::~Stack()
{
    delete[] pitems;
}
bool Stack::isempty() const
{
    return top == 0;
}
bool Stack::isfull() const
{
    return top == this->size;
}
bool Stack::push(const Item &item)
{
    if (top < MAX)
    {
        *pitems = item;
        pitems++;
        top++;
        return true;
    }
    else
        return false;
}
bool Stack::pop(Item &item)
{
    if (top > 0)
    {
        pitems--;
        item = *pitems;
        top--;
        return true;
    }
    else
        return false;
}
std::ostream &operator<<(std::ostream &os, Stack &st)
{
    std::cout << "Rozmiar stosu: " << st.size << std::endl;
    st.pitems -= st.top;
    for (size_t i = 0; i < st.top; i++)
    {
        std::cout << "Element: " << i << ": " << *(Item *)st.pitems << " adres: " << st.pitems << std::endl;
        st.pitems++;
    }
    // st.pitems += st.top;

    return os;
}
Stack &Stack::operator=(const Stack &st)
{
    size = st.size;
    Item *adress = pitems;
    pitems = st.pitems + top;
    top = st.top;
    pitems -= top;
    memcpy(adress, pitems, sizeof(Item) * top);
    pitems = adress;
    pitems++;
    return *this;
}