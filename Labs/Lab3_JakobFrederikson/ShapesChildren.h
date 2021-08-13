#pragma once

// File ShapesChildren.h -- Includes all children of the base class (Shapes.h)
//							Each class includes the overwritten function getData();
//							Each class has includes the function calculatePerimeter();
//							Calculate perimeter will set variable 'result' to a different value each time based on the shapes requirements.

class Square : public Shapes
{
public:
	void calculatePerimeter()
	{
		cout << "\nEnter a side length: ";
		cin >> base;
		result = 4 * base;
	}

	void getData()
	{
		int option = 0;

		do {
			system("cls");
			cout << "|-------------------|" << endl;
			cout << "| SQUARE CALCULATOR |" << endl;
			cout << "|-------------------|" << endl;
			cout << endl;

			drawShape(1);

			cout << "|------------------------|" << endl;
			cout << "| [1] Find area          |" << endl;
			cout << "| [2] Find perimeter     |" << endl;
			cout << "| [3] Back to main menu  |" << endl;
			cout << "|------------------------|" << endl;
			cout << "| Enter option: ";
			cin >> option;

			switch (option)
			{
			case 1:
				calculateArea(1);
				giveResult();
				break;
			case 2:
				calculatePerimeter();
				giveResult();
				break;
			case 3:
				system("cls");
				break;
			}
		} while (option != 3);
	}
};

class RectangleClass : public Shapes
{
public:
	void calculatePerimeter()
	{
		cout << "\nEnter length: ";
		cin >> height;
		cout << "Enter width: ";
		cin >> base;
		result = 2 * (height + base);
	}

	void getData()
	{
		int option = 0;

		do
		{
			system("cls");
			cout << "|----------------------|" << endl;
			cout << "| RECTANGLE CALCULATOR |" << endl;
			cout << "|----------------------|" << endl;
			cout << endl;

			drawShape(2);

			cout << "|------------------------|" << endl;
			cout << "| [1] Find area          |" << endl;
			cout << "| [2] Find perimeter     |" << endl;
			cout << "| [3] Back to main menu  |" << endl;
			cout << "|------------------------|" << endl;
			cout << "| Enter option: ";
			cin >> option;

			switch (option)
			{
			case 1:
				calculateArea(2);
				giveResult();
				break;
			case 2:
				calculatePerimeter();
				giveResult();
				break;
			case 3:
				system("cls");
				break;
			}
		} while (option != 3);
	}
};

class Triangle : public Shapes
{
public:
	void calculatePerimeter()
	{
		double side1, side2, side3;
		cout << "\nEnter side 1 length: ";
		cin >> side1;
		cout << "Enter side 2 length: ";
		cin >> side2;
		cout << "Enter side 3 length: ";
		cin >> side3;
		result = side1 + side2 + side3;
	}

	void getData()
	{
		int option = 0;

		do
		{
			system("cls");
			cout << "|---------------------|" << endl;
			cout << "| TRIANGLE CALCULATOR |" << endl;
			cout << "|---------------------|" << endl;
			cout << endl;

			drawShape(3);

			cout << "|------------------------|" << endl;
			cout << "| [1] Find area          |" << endl;
			cout << "| [2] Find perimeter     |" << endl;
			cout << "| [3] Back to main menu  |" << endl;
			cout << "|------------------------|" << endl;
			cout << "| Enter option: ";
			cin >> option;

			switch (option)
			{
			case 1:
				calculateArea(3);
				giveResult();
				break;
			case 2:
				calculatePerimeter();
				giveResult();
				break;
			case 3:
				system("cls");
				break;
			}
		} while (option != 3);

	}
};

class Circle : public Shapes
{
public:
	void calculatePerimeter()
	{
		double radius = 0;
		cout << "\nEnter circle radius: ";
		cin >> radius;
		result = 2 * 3.14 * radius;
	}

	void getData()
	{
		int option = 0;

		do
		{
			system("cls");
			cout << "|-------------------|" << endl;
			cout << "| CIRCLE CALCULATOR |" << endl;
			cout << "|-------------------|" << endl;
			cout << endl;

			drawShape(4);

			cout << "|------------------------|" << endl;
			cout << "| [1] Find area          |" << endl;
			cout << "| [2] Find perimeter     |" << endl;
			cout << "| [3] Back to main menu  |" << endl;
			cout << "|------------------------|" << endl;
			cout << "| Enter option: ";
			cin >> option;

			switch (option)
			{
			case 1:
				calculateArea();
				giveResult();
				break;
			case 2:
				calculatePerimeter();
				giveResult();
				break;
			case 3:
				system("cls");
				break;
			}
		} while (option != 3);
	}
};