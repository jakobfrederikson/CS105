#pragma once

#include <iostream>

class Complex
{
private:
    int num1, num2;
    static bool plus;
    static bool minus;
    static bool divide;
    static bool multiply;
public:
    Complex(int a = 0, int b = 0)
    {
        num1 = a;
        num2 = b;
    }

    Complex operator+(const Complex& obj);
    Complex operator-(const Complex& obj);
    Complex operator*(const Complex& obj);
    Complex operator/(const Complex& obj);

    int GetNumOne();
    int GetNumTwo();

    void Print();
};
