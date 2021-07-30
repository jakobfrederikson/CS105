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

	Location(int defDeg = 0, float defMin = 0.0, char defDir = '/')
	{
		latDegrees = defDeg;
		longDegrees = defDeg;
		latMinutes = defMin;
		longMinutes = defMin;
		latDirection = defDir;
		longDirection = defDir;
	}

	// Get yacht information from the user and store into the member variables.
	// Function uses do while loops to make sure the program takes the correct output.
	// It will also convert lowercase 'direction' inputs (N/E/S/W) into uppercase.
	void getpos()
	{
		do
		{
			cout << "Input degrees between 0 and 180: ";
			cin >> latDegrees;
			if (latDegrees < 0 || latDegrees > 180)
				cout << "\nPlease enter a valid input.\n";
			else
				break;
		} while (true);
		do
		{
			cout << "Input minutes between 0 and 60:  ";
			cin >> latMinutes;
			if (latMinutes < 0 || latMinutes > 60)
				cout << "\nPlease enter a valid input.\n";
			else
				break;
		} while (true);
		do
		{
			char test;
			cout << "Input ship direction(N/E/S/W):   ";
			cin >> test;
			latDirection = toupper(test);
			if (latDirection != 'N' && latDirection != 'E' && latDirection != 'S' && latDirection != 'W')
				cout << "\nPlease enter a valid input.\,";
			else
				break;
		} while (true);
		do
		{
			cout << "Input degrees between 0 and 180: ";
			cin >> longDegrees;
			if (longDegrees < 0 || longDegrees > 180)
				cout << "\nPlease enter a valid input.\n";
			else
				break;
		} while (true);
		do
		{
			cout << "Input minutes between 0 and 60:  ";
			cin >> longMinutes;
			if (longMinutes < 0 || longMinutes > 60)
				cout << "\nPlease enter a valid input.\n";
			else
				break;
		} while (true);
		do
		{
			char test;
			cout << "Input ship direction(N/E/S/W):   ";
			cin >> test;
			longDirection = toupper(test);
			if (longDirection != 'N' && longDirection != 'E' && longDirection != 'S' && longDirection != 'W')
				cout << "\nPlease enter a valid input.\n";
			else
				break;
		} while (true);
	}
};

// Yacht class is used to create yacht objects and gather/display information for each yacht 
class Yacht
{
public:
	static int totalObjects;
	int serialNumber;
	Location locationObj;

	// The variable yachtLoc is not needed in Yacht constructor as it's apart of the Location class 
	// which already has its own constructor
	Yacht()
	{
		totalObjects++;
		serialNumber = totalObjects;
	}

	// Display a yacht's location and serial number.
	void display()
	{
		cout << "Serial Number: " << serialNumber << endl;
		cout << "Latitude:      " << locationObj.latDegrees << "\xF8" << locationObj.latMinutes << "\"" << locationObj.latDirection << endl;
		cout << "Longitude:     " << locationObj.longDegrees << "\xF8" << locationObj.longMinutes << "\"" << locationObj.longDirection << endl << endl;
	}
};

// initializing total objects outside of class
int Yacht::totalObjects = 0;

int main()
{
	// Creating three yachts
	Yacht yachtObj1;
	Yacht yachtObj2;
	Yacht yachtObj3;

	cout << "[----------------------------------------]\n";
	cout << "[           OCEAN RACE 2021-22           ]\n";
	cout << "[----------------------------------------]\n";
	cout << endl;

	yachtObj1.locationObj.getpos();
	cout << endl;
	yachtObj2.locationObj.getpos();
	cout << endl;
	yachtObj3.locationObj.getpos();
	cout << endl;

	cout << "\n[ALL SHIP DETAILS]";
	cout << "\n==============\n";
	yachtObj1.display();
	yachtObj2.display();
	yachtObj3.display();

	// User input is taken inside this for loop
	//for (int i = 0; i < 3; i++)
	//{
	//	cout << "\n[ENTER DETAILS FOR SHIP NUMBER " << i + 1 << "]";
	//	cout << "\n---------------------------------\n";
	//	// getpos() function used to get latitude and longitude details from the user
	//	yachtObj[i].locationObj.getpos();
	//	// Set the yacht's serial number
	//}

	// display() function used to output all yachts position details
	/*cout << "\n[ALL SHIP DETAILS]";
	cout << "\n==============\n";
	for (int i = 0; i < 3; i++)
		yachtObj[i].display();*/

	return 0;
}
