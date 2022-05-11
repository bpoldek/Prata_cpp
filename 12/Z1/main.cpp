#include <iostream>

#include "cow.h"

int main()
{
    Cow krysia;
    krysia.ShowCow();
    Cow marysia("Marysia", "Narty", 123.22);
    marysia.ShowCow();
    Cow zosia = marysia;
    zosia.ShowCow();
    Cow asia("Asia", "Łucznictwo", 255.22);
    krysia = asia;

    return 0;
}