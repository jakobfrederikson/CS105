#pragma once

void setcolor(unsigned char color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

class Shapes
{
protected:
	double base;
	double height;
	double result;
public:
	Shapes(double defB = 0, double defH = 0, double defR = 0)
	{
		base = defB;
		height = defH;
		result = defR;
	}

	void drawShape(int shape)
	{
		switch (shape)
		{
		case 1:
			cout << " ---------------------" << endl;
			cout << " |                   |" << endl;
			cout << " |                   |" << endl;
			cout << " |                   |" << endl;
			cout << " |                   |" << endl;
			cout << " |                   |" << endl;
			cout << " |                   |" << endl;
			cout << " |                   |" << endl;
			cout << " |                   |" << endl;
			cout << " ---------------------" << endl;
			cout << endl;
			break;
		case 2:
			cout << " ---------------------" << endl;
			cout << " |                   |" << endl;
			cout << " |                   |" << endl;
			cout << " |                   |" << endl;
			cout << " ---------------------" << endl;
			cout << endl;
			break;
		case 3:
			for (int i = 1, k = 0; i <= 5; ++i, k = 0)
			{
				cout << "   ";
				for (int space = 1; space <= 5 - i; ++space)
				{
					cout << "  ";
				}

				while (k != 2 * i - 1)
				{
					cout << "* ";
					++k;
				}
				cout << endl;
			}
			break;
		case 4:
			float r = 8;
			float pr = 2;
			for (int i = -r; i <= r; i++)
			{
				for (int j = -r; j <= r; j++)
				{
					float d = ((i * pr) / r) * ((i * pr) / r) + (j / r) * (j / r);
					if (d > 0.95 && d < 1.08)
					{
						cout << "*";
					}
					else
					{
						cout << " ";
					}
				}
				cout << endl << "  ";
			}
			cout << endl;
			break;
		}
	}

	void getData()
	{
		cout << "\n___No shape selected___\n";
	}

	void calculateArea(int shape)
	{
		switch (shape)
		{
		case 1: // SQUARE
			cout << "\nEnter a side length: ";
			setcolor(2);
			cin >> base;
			setcolor(7);
			result = base * base;
			break;
		case 2: // RECTANGLE
			cout << "\nEnter base: ";
			setcolor(2);
			cin >> base;
			setcolor(7);
			cout << "Enter height: ";
			setcolor(2);
			cin >> height;
			setcolor(7);
			result = base * height;
			break;
		case 3: // TRIANGLE
			cout << "\nEnter base: ";
			setcolor(2);
			cin >> base;
			setcolor(7);
			cout << "Enter height: ";
			cin >> height;
			setcolor(7);
			result = 0.5 * (base * height);
			break;
		}
	}

	// Overloaded function specifically for Circle
	void calculateArea()
	{
		double radius = 0;
		cout << "\nEnter radius: ";
		setcolor(2);
		cin >> radius;
		setcolor(7);
		result = 3.14 * radius * radius;
	}

	void giveResult()
	{
		cout << "\nThe result is: ";
		setcolor(12);
		cout << result;
		setcolor(7);
		cout << endl << endl;
		system("pause");
		system("cls");
	}
};