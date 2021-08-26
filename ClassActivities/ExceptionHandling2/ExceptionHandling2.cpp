#include <iostream>
using namespace std;

// creating a class to handle exceptions
class Exception
{
public:
    string reason;
    int num_entered;
    Exception(string s, int i)
    {
        reason = s;
        num_entered = i;
    }
};

int main()
{
    int flag = 0;
    int i;

    do
    {
        try 
        {
            cout << "Enter a positive number below 100 and above 0: ";
            cin >> i;
            if (i <= 0 || i >= 100)
            {
                // throwing a class object
                throw Exception("Wrong input: ", i);
            }
            else
            {
                cout << "\nCorrect Input!\n";
                flag = 1;
            }
        }
        // catching class object
        catch (Exception e)
        {
            // outputting its member variables
            cout << e.reason << e.num_entered << "\n\n";
        }
    } while (flag == 0);

    return 0;
}
