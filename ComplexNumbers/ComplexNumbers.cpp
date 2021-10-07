#include "Complex.h"

int main()
{
    Complex c1(5, 10), c2(8, 6);
    Complex c3;

    c3 = c1 + c2;
    c3.Print();

    c3 = c1 - c2;
    c3.Print();

    c3 = c1 * c2;
    c3.Print();

    c3 = c1 / c2;
    c3.Print();
}