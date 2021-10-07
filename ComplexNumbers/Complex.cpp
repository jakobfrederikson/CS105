#include "Complex.h"

bool Complex::plus = true;
bool Complex::minus = true;
bool Complex::multiply = true;
bool Complex::divide = true;

Complex Complex::operator+(const Complex& obj)
{
    plus = true;
    Complex c;
    c.num1 = this->num1 + obj.num1;
    c.num2 = this->num2 + obj.num2;
    return c;
}

Complex Complex::operator-(const Complex& obj)
{
    minus = true;
    Complex c;
    c.num1 = this->num1 - obj.num1;
    c.num2 = this->num2 - obj.num2;
    return c;
}

Complex Complex::operator/(const Complex& obj)
{
    divide = true;
    Complex c;
    c.num1 = this->num1 / obj.num1;
    c.num2 = this->num2 / obj.num2;
    return c;
}

Complex Complex::operator*(const Complex& obj)
{
    multiply = true;
    Complex c;
    c.num1 = this->num1 * obj.num1;
    c.num2 = this->num2 * obj.num2;
    return c;
}

int Complex::GetNumOne()
{
    return num1;
}

int Complex::GetNumTwo()
{
    return num2;
}

void Complex::Print()
{
    if (Complex::plus == true)
        std::cout << "[ PLUS ]\n";
    else if (Complex::minus == true)
        std::cout << "[ MINUS ]\n";
    else if (Complex::divide == true)
        std::cout << "[ DIVIDE ]\n";
    else if (Complex::multiply == true)
        std::cout << "[ MULTIPLY ]\n";

    std::cout << "num1: " << Complex::GetNumOne() << "\n";
    std::cout << "num2: " << Complex::GetNumTwo() << "\n";
    std::cout << "\n";

    plus = false;
    minus = false;
    multiply = false;
    divide = false;
}