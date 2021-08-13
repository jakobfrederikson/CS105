//
// Programmer: Jakob Frederikson
// Student ID: 200729667
//
// Bachelor of Software Engineering
// CS105 Development Principles II
// Lab 3
//
// Details:
// - calculate area and permiter of some structures being planned
// - square, rectangle, circle, triangle
//

using namespace std;
#include <iostream>
#include <Windows.h>
#include "Shapes.h"
#include "ShapesChildren.h"

void run_program()
{
	// Shape Objects
	Square s;
	RectangleClass r;
	Triangle t;
	Circle c;

	// Menu controll
	int option = 0;

	do {
		cout << "|-------------------|" << endl;
		cout << "| SHAPES CALCULATOR |" << endl;
		cout << "|-------------------|" << endl;
		cout << "| [1] Square        |" << endl;
		cout << "| [2] Rectangle     |" << endl;
		cout << "| [3] Triangle      |" << endl;
		cout << "| [4] Circle        |" << endl;
		cout << "| [5] Exit          |" << endl;
		cout << "|-------------------|" << endl;
		cout << "| Enter your option: ";

		cin >> option;
		if (option == 5)
		{
			break;
		}
		else
		{
			switch (option)
			{
			case 1:
				s.getData();
				break;
			case 2:
				r.getData();
				break;
			case 3:
				t.getData();
				break;
			case 4:
				c.getData();
				break;
			}
		}
	} while (true);
}

int main()
{
	// Runs the main menu, all program functions stem from out from this.
	run_program();
}
