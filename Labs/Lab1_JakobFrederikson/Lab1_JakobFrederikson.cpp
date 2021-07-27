//
// Programmer: Jakob Frederikson
// Student ID: 200729667
//
// Bachelor of Software Engineering
// CS105 Development Principles II
// Lab 1
// 
// Details:
//		- Create two classes, 'Yacht' and 'Location'
//		- 'Yacht' includes the yacht's number and location
//		- Location includes degrees, minutes, and direction
//		- A member function [ getpos() ] of 'Yacht' should get the location
//		  of the yacht from the user.
// 
//		- Another member function [ display() ] should report the yacht 
//		  number and location with the correct latitude and longitude format.
// 
//		- The main() function creates three yachts, asks the user to input the
//		  the location and then displays each yachts number and location.
//

#include <iostream>
using namespace std;

// The location class holds the positional variables for each yacht
class Location
{
public:
	int latDegrees;
	int longDegrees;
	float latMinutes;
	float longMinutes;
	char latDirection;
	char longDirection;

public:
	Location(int defDeg = 0, float defMin = 0.0, char defDir = '/')
	{
		latDegrees = defDeg;
		longDegrees = defDeg;
		latMinutes = defMin;
		longMinutes = defMin;
		latDirection = defDir;
		longDirection = defDir;
	}
};

// Yacht class is used to create yacht objects and gather/display information for each yacht 
class Yacht
{
public:
	int serialNumber;
	Location yachtLoc;

public:
	// The variable yachtLoc is not needed in Yacht constructor as it's apart of the Location class 
	// which already has its own constructor
	Yacht(int s = 0)
	{
		serialNumber = s;
	}

public:
	// Get yacht information from the user and store into the member variables.
	void getpos()
	{
		cout << "Input degrees between 0 and 180: ";
		cin >> yachtLoc.latDegrees;
		cout << "Input minutes between 0 and 60:  ";
		cin >> yachtLoc.latMinutes;
		cout << "Input ship direction(N/E/S/W):   ";
		cin >> yachtLoc.latDirection;
		cout << "Input degrees between 0 and 180: ";
		cin >> yachtLoc.longDegrees;
		cout << "Input minutes between 0 and 60:  ";
		cin >> yachtLoc.longMinutes;
		cout << "Input ship direction(N/E/S/W):   ";
		cin >> yachtLoc.longDirection;
	}

	// Display a yacht's location and serial number.
	void display()
	{
		cout << "Serial Number: " << serialNumber << endl;
		cout << "Latitude:      " << yachtLoc.latDegrees << "\xF8" << yachtLoc.latMinutes << "\"" << yachtLoc.latDirection << endl;
		cout << "Longitude:     " << yachtLoc.longDegrees << "\xF8" << yachtLoc.longMinutes << "\"" << yachtLoc.longDirection << endl << endl;
	}
};

int main()
{
	// Creating three yachts
	Yacht yachtObj[3];

	cout << "[----------------------------------------]\n";
	cout << "[           OCEAN RACE 2021-22           ]\n";
	cout << "[----------------------------------------]\n";
	cout << endl;

	// User input is taken inside this for loop
	for (int i = 0; i < 3; i++)
	{
		cout << "\n[ENTER DETAILS FOR SHIP NUMBER " << i + 1 << "]";
		cout << "\n---------------------------------\n";

		// getpos() function used to get latitude and longitude details from the user
		yachtObj[i].getpos();
		// Set the yacht's serial number
		yachtObj[i].serialNumber = i + 1;
	}

	// display() function used to output all yachts position details
	cout << "\n[ALL SHIP DETAILS]";
	cout << "\n==============\n";
	for (int i = 0; i < 3; i++)
		yachtObj[i].display();

	return 0;
}
