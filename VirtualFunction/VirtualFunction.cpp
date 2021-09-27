// VirtualFunction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class BankAccount
{
protected:
    string customer_name_;
    long int account_number_;
public:
    BankAccount(string cn = "no_name", long int an = 000000000)
    {
        customer_name_ = cn;
        account_number_ = an;
    }

    virtual void display() = 0;
    virtual void calculate() = 0;
};

class SavingsAccount : public BankAccount
{
private:
    long int account_balance_;
public:
    void display()
    {
        cout << "SAVINGS ACCOUNT\n";
        cout << "---------------------------------------------------\n";
        cout << "Customer name:  " << customer_name_ << "\n";
        cout << "Account number: " << account_number_ << "\n\n";
    }

    void calculate()
    {

    }
};

class CreditAccount : public BankAccount
{
private:
    long int balance_borrowed_;
public:
    void display()
    {
        cout << "CREDIT ACCOUNT\n";
        cout << "---------------------------------------------------\n";
        cout << "Customer name:  " << customer_name_ << "\n";
        cout << "Account number: " << account_number_ << "\n\n";
    }
    void calculate()
    {

    }
};

int main()
{
    SavingsAccount s;
    CreditAccount c;
    BankAccount* bank[100];
    int test_case = 0;
    int user_choice = 0;

    cout << "Enter how many accounts you're making: ";
    cin >> test_case;

    for (int i = 0; i < test_case; i++)
    {
        cout << "Are you making a: \n";
        cout << "[1]. Savings account";
        cout << "[2]. Credit account";
        
        try 
        {
            cin >> user_choice;
            if (!cin || user_choice < 1 || user_choice > 2) throw "error";

            if (user_choice == 1)
            {
                bank[i] = new SavingsAccount;
                bank[i]->calculate();
            }
            else if (user_choice == 2)
            {
                bank[i] = new CreditAccount;
            }
        }
        catch (...)
        {
            cout << "Please enter a valid number.";
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            system("pause");
            i--;
        }

    }
}
