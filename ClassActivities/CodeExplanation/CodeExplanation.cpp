#include <iostream>
using namespace std;

class Phone
{
public:
    double cost;
    int slots;
};

int main()
{
    Phone Y6;
    Phone Y7;

    Y6.cost = 100.0;
    Y6.slots = 2;
    Y7.cost = 200.0;
    Y7.slots = 2;

    cout << "Y6 cost = " << Y6.cost << endl;
    cout << "Y6 slots = " << Y6.slots << endl;
    cout << "\nY7 cost = " << Y7.cost << endl;
    cout << "Y7 slots = " << Y7.slots << endl;

    return 0;
 }
