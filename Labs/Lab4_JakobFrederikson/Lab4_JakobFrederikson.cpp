//
// Programmer: Jakob Frederikson
// Student ID: 200729667
//
// Bachelor of Software Engineering
// CS105 Development Principles II
// Lab 4
//

#include <iostream>
#include <stdlib.h> // for use of rand()
using namespace std;

class Alien
{
private:
	int weight;
	int height;
	char gender;
public:
	Alien(int w = 0, int h = 0, char g = 'none')
	{
		weight = w;
		height = h;
		gender = g;
	}

	int getWeight()
	{
		return weight;
	}

	int getHeight()
	{
		return height;
	}

	char getGender()
	{
		return gender;
	}

	// Returns prestige. Male = 2 points, Female = 3 points
	int getPrestige()
	{
		int p = 0;

		if (gender == 'm')
			p = height * weight * 2;
		else if (gender == 'f')
			p = height * weight * 3;

		return p;
	}

	// Breeding
	Alien operator+(const Alien& a)
	{
		Alien alien;
		
		srand(time(0));
		int randGender = 1 + (rand() % 2); // randomly pick the numbers 1 or 2 to assign to randGender

		alien.weight = (this->weight + a.weight) / 2;
		alien.height = (this->height + a.height) / 2;
		if (randGender == 1) 
		{
			alien.gender = 'm';
		}
		else if (randGender == 2)
		{
			alien.gender = 'f';
		}

		return alien;
	}

	// Compare offspring prestiges through use of operator overloading
	bool operator==(Alien& a)
	{
		if (this->getPrestige() == a.getPrestige())
			return true;
		else
			return false;
	}
	bool operator!=(Alien& a)
	{
		if (this->getPrestige() != a.getPrestige())
			return true;
		else
			return false;
	}
	bool operator<(Alien& a)
	{
		if (this->getPrestige() < a.getPrestige())
			return true;
		else
			return false;
	}
	bool operator<=(Alien& a)
	{
		if (this->getPrestige() <= a.getPrestige())
			return true;
		else
			return false;
	}
	bool operator>(Alien& a)
	{
		if (this->getPrestige() > a.getPrestige())
			return true;
		else
			return false;
	}
	bool operator>=(Alien& a)
	{
		if (this->getPrestige() >= a.getPrestige())
			return true;
		else
			return false;
	}

	// Assign one Alien object to another Alien object through overload of assignment operator
	void operator=(Alien& a)
	{
		this->gender = a.gender;
		this->height = a.height;
		this->weight = a.weight;
	}
};

void run_program()
{
	int menuChoice = 0;

	// create pairs
	Alien alien1(60, 120, 'm');
	Alien alien2(25, 50, 'f');
	Alien alien3(65, 130, 'm');
	Alien alien4(30, 60, 'f');

	// create offspring
	Alien alien5 = alien1 + alien2;
	Alien alien6 = alien3 + alien4;

	// run main menu
	do
	{
		cout << "Main Menu:" << endl;
		cout << "[1] Create Alien Pairs" << endl;
		cout << "[2] Create offspring" << endl;
		cout << "[3] Compare offspring prestige" << endl;
		cout << "[4] Exit" << endl;
		cout << "Enter choice: ";
		cin >> menuChoice;
		cout << endl;

		switch (menuChoice)
		{
		case 1:
			// create pairs?
			break;
		case 2:
			// create off spring?
			break;
		case 3:
			// boolalpha will print out boolean values as words (true, false) rather than numbers (1,0)
			cout << boolalpha; 
			cout << "Alien5 == Alien6 ? " << (alien5 == alien6) << endl;
			cout << "Alien5 != Alien6 ? " << (alien5 != alien6) << endl;
			cout << "Alien5 > Alien6  ? " << (alien5 > alien6) << endl;
			cout << "Alien5 >= Alien6 ? " << (alien5 >= alien6) << endl;
			cout << "Alien5 < Alien6  ? " << (alien5 < alien6) << endl;
			cout << "Alien5 <= Alien6 ? " << (alien5 <= alien6) << endl;
			cout << endl;
			break;
		default:
			cout << "\n\nPlease enter a number between 1-4. Thank you.\n\n";
			system("pause");
		}
	} while (menuChoice != 4);
}

int main()
{
	run_program();
	return 0;
}