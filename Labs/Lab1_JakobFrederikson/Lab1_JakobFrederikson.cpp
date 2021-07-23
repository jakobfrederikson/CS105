#include <iostream>
using namespace std;
class Location
{
public:
    int degrees;
    float minutes;
    char direction;
};
class Yacht
{
public:
    int serialNum;
    Yacht(int yachtNum) // initialize the serial number
    {

    }
    void get_pos() // get the location from class Location
    {

    }
    void display() // display the latitude and longitude
    {

    }
};
int main()
{
    cout << "************OCEAN RACE 2021-22************\n\n";
    for (int i = 0; i < 3; i++)
    {      
        cout << "**********************************";
        cout << "ENTER LOCATION FOR SHIP NUMBER " << i + 1;
        cout << "Longitude:";
        cout << "Input degrees between 0 and 180: ";
        cout << "Input minutes between 0 and 60:  ";
        cout << "Input direction (N/E/S/W):       ";
        cout << "Latitude:";
        cout << "Input degrees between 0 and 180: ";
        cout << "Input minutes between 0 and 60:  ";
        cout << "Input direction (N/E/S/W):       ";
    }
    cout << "******************************************\n\n";
    for (int i = 0; i < 3; i++)
    {
        cout << "Ship serial number: ";
        cout << "Latitude:          Longitude: ";
    }
}
