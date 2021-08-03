//
// Programmer: Jakob Frederikson
// Student ID: 200729667
//
// Bachelor of Software Engineering
// CS105 Development Principles II
// Lab 2
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Race enumurator
enum Race { DEFAULT, HUMAN, ELF, DWARF, ORC, TROLL };

class Player
{
private:
	string name;
	int hitPoints, magicPoints;
	Race race;
public:
	Player(string defName = "DEFAULT_NAME", Race defRace = DEFAULT, int defHP = 0, int defMP = 0)
	{
		name = defName;
		race = defRace;
		hitPoints = defHP;
		magicPoints = defMP;
	}

	string whatRace()
	{
		switch (getRace())
		{
		case 1:
			return "Human";
			break;
		case 2:
			return "Elf";
			break;
		case 3:
			return "Dwarf";
			break;
		case 4:
			return "Orc";
			break;
		case 5:
			return "Troll";
			break;
		default:
			return "DEFAULT";
			break;
		}
	}

	// GETTERS
	string getName()
	{
		return name;
	}
	Race getRace()
	{
		return race;
	}
	int getHitPoints()
	{
		return hitPoints;
	}
	int getMagicPoints()
	{
		return magicPoints;
	}

	// SETTERS
	void setName(string n)
	{
		name = n;
	}
	void setRace(Race r)
	{
		race = r;
	}
	void setHitPoints(int hp)
	{
		hitPoints = hp;
	}
	void setMagicPoints(int mp)
	{
		magicPoints = mp;
	}
	string attack()
	{
		return "No attack method defined yet!";
	}
};

class Warrior : public Player
{
public:
	Warrior()
	{
		setHitPoints(200);
		setMagicPoints(0);
	}
	void createCharacter()
	{
		string name;
		cout << "\t\t\t[==========================]\n";
		cout << "\t\t\t[Enter characters name: ";
		cin.ignore();
		getline(cin, name);
		setName(name);
	}
	string attack()
	{
		return "Bone Crunching Sword Swipe!";
	}
};

class Priest : public Player
{
public:
	Priest()
	{
		setHitPoints(100);
		setMagicPoints(200);
	}
	void createCharacter()
	{
		string name;
		cout << "\t\t\t[==========================]\n";
		cout << "\t\t\t[Enter characters name: ";
		cin.ignore();
		getline(cin, name);
		setName(name);
	}
	string attack()
	{
		return "Blinding Holy Wrath!";
	}
};

class Mage : public Player
{
public:
	Mage()
	{
		setHitPoints(000);
		setMagicPoints(200);
	}
	void createCharacter()
	{
		string name;
		cout << "\t\t\t[==========================]\n";
		cout << "\t\t\t[Enter characters name: ";
		cin.ignore();
		getline(cin, name);
		setName(name);
	}
	string attack()
	{
		return "Luminous Arcane Missiles!";
	}
};

int displayCharacters(vector<Warrior> warrior, vector<Priest> priest, vector<Mage> mage);

int main()
{
	//
	// ALL CLASS OBJECTS
	//
	Warrior w;
	Priest p;
	Mage m;
	vector<Warrior> warrior;
	vector<Priest> priest;
	vector<Mage> mage;

	//
	// USER INPUT VARIABLES
	//
	Race r;
	int classChoice;
	int raceChoice;
	int characterCheck;

	//
	// LOOP CONTROLS
	//
	bool True = true;     // "CHARACTER CREATION" loop
	bool raceTrue = true; // "Choose characters race" loop

	do {
		system("cls");
		cout << "\t\t\t[=======================================]\n";
		cout << "\t\t\t[          CHARACTER CREATION           ]\n";
		cout << "\t\t\t[=======================================]\n";
		cout << "\t\t\t[Choose your characters class:          ]\n";
		cout << "\t\t\t[1. Warrior                             ]\n";
		cout << "\t\t\t[2. Priest                              ]\n";
		cout << "\t\t\t[3. Mage                                ]\n";
		cout << "\t\t\t[---------------------------------------]\n";
		cout << "\t\t\t[4. View and finish creating characters ]\n";
		cout << "\t\t\t[=======================================]\n";
		cout << "\t\t\t[Enter choice here: ";
		cin >> classChoice;
		cout << endl;

		if (classChoice <= 4 && classChoice >= 1)
		{
			if (classChoice < 4)
			{
				do
				{
					cout << "\t\t\t[=======================================]\n";
					cout << "\t\t\t[Choose your characters race:           ]\n";
					cout << "\t\t\t[1. Human                               ]\n";
					cout << "\t\t\t[2. Elf                                 ]\n";
					cout << "\t\t\t[3. Dwarf                               ]\n";
					cout << "\t\t\t[4. Orc                                 ]\n";
					cout << "\t\t\t[5. Troll                               ]\n";
					cout << "\t\t\t[=======================================]\n";
					cout << "\t\t\t[Enter choice here: ";
					cin >> raceChoice;
					cout << endl;

					// Switch case sets the variable 'r' to the users choice in race.
					// Later, in the 'classChoice' switch case, we set the race with setRace(r);
					switch (raceChoice)
					{
					case 1:
						r = HUMAN;
						raceTrue = false;
						break;
					case 2:
						r = ELF;
						raceTrue = false;
						break;
					case 3:
						r = DWARF;
						raceTrue = false;
						break;
					case 4:
						r = ORC;
						raceTrue = false;
						break;
					case 5:
						r = TROLL;
						raceTrue = false;
						break;
					default:
						cout << "\n\t\t\tWrong input entered! Please enter a number between 1-5.\n\n";
					}
				} while (raceTrue);
			}

			// Case 1, 2, and 3 will:
			//		- Create the character based on their chosen class
			//		- Set the characters race
			//		- Push back data into the respective vector
			//
			// Case 4 is explained in the case itself.
			switch (classChoice)
			{
			case 1:
				w.createCharacter();
				w.setRace(r);
				warrior.push_back(w);
				cout << "\n\t\t\t[Character sucessfully created!]\n";
				cout << "\t\t\t";
				system("pause");
				break;
			case 2:
				p.createCharacter();
				p.setRace(r);
				priest.push_back(p);
				cout << "\n\t\t\t[Character sucessfully created!]\n";
				cout << "\t\t\t";
				system("pause");
				break;
			case 3:
				m.createCharacter();
				m.setRace(r);
				mage.push_back(m);
				cout << "\n\t\t\t[Character sucessfully created!]\n";
				cout << "\t\t\t";
				system("pause");
				break;
			case 4:
				// displayCharacters() function returns 0 or 1 depending on whether the vectors are all empty(0) or not(1).
				characterCheck = displayCharacters(warrior, priest, mage);

				// If all vectors are empty, check if they want to create character or exit program.
				if (characterCheck == 0)
				{
					int exit = 0;
					cout << "\n\t\t\t[==========================================]\n";
					cout << "\t\t\t[   You haven't created a character yet!   ]\n";
					cout << "\t\t\t[==========================================]\n";
					cout << "\t\t\t[ You can:                                 ]\n";
					cout << "\t\t\t[ 1. Go back to character creation screen. ]\n";
					cout << "\t\t\t[ 2. Exit program.                         ]\n";
					cout << "\t\t\t[==========================================]\n";
					cout << "\t\t\t[ Enter choice here: ";
					cin >> exit;
					if (exit == 1)
					{
						break;
					}
					else if (exit == 2)
					{
						True = false;
						break;
					}
				}
				// If at least one vector wasn't empty.
				else if (characterCheck == 1)
				{
					True = false;
					break;
				}
			}
		}
		else
		{
			// Main Menu Input
			cout << "\n\t\t\tWrong input entered! Please enter a number between 1-4.";
		}
	} while (True);
}

// This function will display all of the users created characters. If the user
// has created no characters yet, it will return 0 and main() will ask the user
// if they wish to create a character or exit the program.
int displayCharacters(vector<Warrior> warrior, vector<Priest> priest, vector<Mage> mage)
{
	if (warrior.empty() && priest.empty() && mage.empty())
	{
		return 0;
	}
	else
	{
		//
		// This is designed so that if the user created only one type of class then they can still
		// view their characters. For example, the user is only interested in creating warriors.
		// They will still be able to view their created warriors whilst the priest and mage
		// lists will output "No [class name] characters found!".
		//

		system("cls");

		// WARRIOR CHARACTERS
		cout << "\t\t\t[===============]\n";
		cout << "\t\t\t[  WARRIOR LIST ]\n";
		cout << "\t\t\t[===============]\n";
		if (!warrior.empty()) {
			for (int i = 0; i < warrior.size(); i++)
			{
				cout << "\t\t\tName:       " << warrior[i].getName() << endl;
				cout << "\t\t\tRace:       " << warrior[i].whatRace() << endl;
				cout << "\t\t\tAttack:     " << warrior[i].attack() << endl;
				cout << "\t\t\tHit Points: " << warrior[i].getHitPoints() << " - Magic Points: " << warrior[i].getMagicPoints() << endl;
				cout << endl;
			}
			cout << endl;
		}
		else {
			cout << "\t\t\tNo warrior characters found!\n\n";
		}

		// PRIEST CHARACTERS
		cout << "\t\t\t[===============]\n";
		cout << "\t\t\t[  PRIEST LIST  ]\n";
		cout << "\t\t\t[===============]\n";
		if (!priest.empty()) {
			for (int i = 0; i < priest.size(); i++)
			{
				cout << "\t\t\tName:       " << priest[i].getName() << endl;
				cout << "\t\t\tRace:       " << priest[i].whatRace() << endl;
				cout << "\t\t\tAttack:     " << priest[i].attack() << endl;
				cout << "\t\t\tHit Points: " << priest[i].getHitPoints() << " - Magic Points: " << priest[i].getMagicPoints() << endl;
				cout << endl;
			}
			cout << endl;
		}
		else {
			cout << "\t\t\tNo priest characters found!\n\n";
		}

		// MAGE CHARACTERS
		cout << "\t\t\t[===============]\n";
		cout << "\t\t\t[   MAGE LIST   ]\n";
		cout << "\t\t\t[===============]\n";
		if (!mage.empty()) {
			for (int i = 0; i < mage.size(); i++)
			{
				cout << "\t\t\tName:       " << mage[i].getName() << endl;
				cout << "\t\t\tRace:       " << mage[i].whatRace() << endl;
				cout << "\t\t\tAttack:     " << mage[i].attack() << endl;
				cout << "\t\t\tHit Points: " << mage[i].getHitPoints() << " - Magic Points: " << mage[i].getMagicPoints() << endl;
				cout << endl;
			}
			cout << endl;
		}
		else {
			cout << "\t\t\tNo mage characters found!\n\n";
		}
		return 1;
	}
}
