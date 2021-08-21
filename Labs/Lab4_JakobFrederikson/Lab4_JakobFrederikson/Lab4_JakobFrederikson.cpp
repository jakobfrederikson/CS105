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
#include <vector>
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

	// Getters
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

	// Calculate a prestige value for an alien
	int getPrestige()
	{
		int p = 0;

		if (gender == 'm')
			p = height * weight * 2;
		else if (gender == 'f')
			p = height * weight * 3;

		return p;
	}

	// Breeding aliens by overloading + operator (alienN = alienX + alienY)
	Alien operator+(const Alien& a)
	{
		Alien alien;
		
		srand(time(0));
		int randGender = 1 + (rand() % 2); // pick number between 1 or 2

		alien.weight = (this->weight + a.weight) / 2;
		alien.height = (this->height + a.height) / 2;
		if (randGender == 1) // assign alien gender based on the random number 
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
	void operator=(const Alien& a)
	{
		this->gender = a.gender;
		this->height = a.height;
		this->weight = a.weight;
	}
};

// Programs main menu and functionality
void run_program()
{
	int menuChoice = 0;

	// vector which will hold all created aliens
	vector<Alien> alien_vector;

	Alien alien1(60, 120, 'm');
	Alien alien2(25, 50, 'f');
	Alien alien3(65, 130, 'm');
	Alien alien4(30, 60, 'f');

	// run main menu
	do
	{
		system("cls");
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
		case 1: // CREATE ALIEN PAIRS
			if (alien_vector.empty())
			{
				// lab instructions ask to let user create 4 aliens
				// I push back the previously constructed alien objects into this vector...
				alien_vector.push_back(alien1);
				alien_vector.push_back(alien2);
				alien_vector.push_back(alien3);
				alien_vector.push_back(alien4);
				cout << "\nAliens pairs created!\n";
				system("pause");
			}
			else
			{
				cout << "\n\nAlien pairs have already been created!\n\n";
				system("pause");
			}
			break;
		case 2: // CREATE OFFSPRING
			if (alien_vector.empty())
			{
				cout << "\n\nYou need alien pairs before producing offspring!\n\n";
				system("pause");
			}
			else
			{
				Alien alien5 = alien1 + alien2;
				Alien alien6 = alien3 + alien4;

				alien_vector.push_back(alien5);
				alien_vector.push_back(alien6);

				cout << "\n\nAlien offspring created!\n\n";
				system("pause");
			}
			break;
		case 3: // COMPARE OFFSPRING PRESTIGE
			if (!alien_vector.empty())
			{
				// boolalpha will print out boolean values as words (true, false) rather than numbers (1,0)
				cout << boolalpha;
				cout << "Alien5 == Alien6  ? " << (alien_vector[4] == alien_vector[5]) << endl;
				cout << "Alien5 != Alien6  ? " << (alien_vector[4] != alien_vector[5]) << endl;
				cout << "Alien5 >  Alien6  ? " << (alien_vector[4] > alien_vector[5]) << endl;
				cout << "Alien5 >= Alien6  ? " << (alien_vector[4] >= alien_vector[5]) << endl;
				cout << "Alien5 <  Alien6  ? " << (alien_vector[4] < alien_vector[5]) << endl;
				cout << "Alien5 <= Alien6  ? " << (alien_vector[4] <= alien_vector[5]) << endl;
				cout << endl;
				system("pause");
			}
			else
			{
				cout << "\n\nPlease create alien pairs/offspring first!\n\n";
				system("pause");
			}
			break;
		case 4: // EXIT
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
