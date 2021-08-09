//
// Programmer: Jakob Frederikson
// Student ID: 200729667
//
// Bachelor of Software Engineering
// CS105 Development Principles II
// Lab 2
//

// "using namespace std" must be written before including any user created header files to function properly.
using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include "Player.h"
#include "Characters.h"


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
	// USER INPUT RELATED VARIABLES 
	//
	Race r;
	int classChoice;
	int raceChoice;
	int characterCheck;
	int attackChoice;

	//
	// LOOP CONTROLS
	//
	bool True = true;       // "CHARACTER CREATION" loop
	bool raceTrue = true;   // "Choose characters race" loop
	bool attackTrue = true; // "Choose characters attack" loop

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
				//
				// CHOOSE CHARACTER RACE LOOP
				//
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

				//
				// CHOOSE CHARACTER ATTACK LOOP
				//
				do
				{
					if (classChoice == 1) // If user chose WARRIOR
					{
						cout << "\t\t\t[=======================================]\n";
						cout << "\t\t\t[Choose your characters attack:         ]\n";
						cout << "\t\t\t[1. Bone crunching mace swing!          ]\n";
						cout << "\t\t\t[2. Slicing sword swipe!                ]\n";
						cout << "\t\t\t[3. Kidney bruising punch!              ]\n";
						cout << "\t\t\t[=======================================]\n";
						cout << "\t\t\t[Enter choice here: ";
						cin >> attackChoice;
						cout << endl;
						attackTrue = false;
					}
					else if (classChoice == 2) // If user chose PRIEST
					{
						cout << "\t\t\t[=======================================]\n";
						cout << "\t\t\t[Choose your characters attack:         ]\n";
						cout << "\t\t\t[1. Blinding holy wrath!                ]\n";
						cout << "\t\t\t[2. Desperate prayer!                   ]\n";
						cout << "\t\t\t[3. Shadow pain!                        ]\n";
						cout << "\t\t\t[=======================================]\n";
						cout << "\t\t\t[Enter choice here: ";
						cin >> attackChoice;
						cout << endl;
						attackTrue = false;
					}
					else if (classChoice == 3) // If user chose MAGE
					{
						cout << "\t\t\t[=======================================]\n";
						cout << "\t\t\t[Choose your characters attack:         ]\n";
						cout << "\t\t\t[1. Spikey frostbolt!                   ]\n";
						cout << "\t\t\t[2. Melting fireball!                   ]\n";
						cout << "\t\t\t[3. Luminous arcane missiles!           ]\n";
						cout << "\t\t\t[=======================================]\n";
						cout << "\t\t\t[Enter choice here: ";
						cin >> attackChoice;
						cout << endl;
						attackTrue = false;
					}
				} while (attackTrue);
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
				w.setAttack(attackChoice);
				warrior.push_back(w);
				cout << "\n\t\t\t[Character sucessfully created!]\n";
				cout << "\t\t\t";
				system("pause");
				break;
			case 2:
				p.createCharacter();
				p.setRace(r);
				p.setAttack(attackChoice);
				priest.push_back(p);
				cout << "\n\t\t\t[Character sucessfully created!]\n";
				cout << "\t\t\t";
				system("pause");
				break;
			case 3:
				m.createCharacter();
				m.setRace(r);
				m.setAttack(attackChoice);
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
		cout << "\t\t\t[===========================================]\n";
		cout << "\t\t\t[                WARRIOR LIST               ]\n";
		cout << "\t\t\t[===========================================]\n";
		if (!warrior.empty()) {
			for (int i = 0; i < warrior.size(); i++)
			{
				int n = warrior.size();
				cout << "\t\t\t[Name:            " << warrior[i].getName() << endl;
				cout << "\t\t\t[Race:            " << warrior[i].whatRace() << endl;
				cout << "\t\t\t[Attack:          " << warrior[i].attack() << endl;
				cout << "\t\t\t[Starting health: " << warrior[i].getHitPoints() << endl;
				cout << "\t\t\t[Attack Points:   " << warrior[i].getAttackPoints() << endl;
				cout << "\t\t\t[Magic Points:    " << warrior[i].getMagicPoints() << endl;

				if ((i + 1) != n)
					cout << "\t\t\t[-------------------------------------------]\n"; // If there's still more characters to print, seperate them with a thin line.
				else
					cout << "\t\t\t[===========================================]\n"; // Otherwise, finish the list off with a thick line. This is repeated for priest and mage.
			}
			cout << endl;
		}
		else {
			cout << "\t\t\tNo warrior characters found!\n\n";
		}

		// PRIEST CHARACTERS
		cout << "\t\t\t[===========================================]\n";
		cout << "\t\t\t[                PRIEST LIST                ]\n";
		cout << "\t\t\t[===========================================]\n";
		if (!priest.empty()) {
			for (int i = 0; i < priest.size(); i++)
			{
				int n = priest.size();
				cout << "\t\t\t[Name:            " << priest[i].getName() << endl;
				cout << "\t\t\t[Race:            " << priest[i].whatRace() << endl;
				cout << "\t\t\t[Attack:          " << priest[i].attack() << endl;
				cout << "\t\t\t[Starting health: " << priest[i].getHitPoints() << endl;
				cout << "\t\t\t[Attack Points:   " << priest[i].getAttackPoints() << endl;
				cout << "\t\t\t[Magic Points:    " << priest[i].getMagicPoints() << endl;

				if ((i + 1) != n)
					cout << "\t\t\t[-------------------------------------------]\n";
				else
					cout << "\t\t\t[===========================================]\n";
			}
			cout << endl;
		}
		else {
			cout << "\t\t\tNo priest characters found!\n\n";
		}

		// MAGE CHARACTERS
		cout << "\t\t\t[===========================================]\n";
		cout << "\t\t\t[                MAGE LIST                  ]\n";
		cout << "\t\t\t[===========================================]\n";
		if (!mage.empty()) {
			for (int i = 0; i < mage.size(); i++)
			{
				int n = mage.size();
				cout << "\t\t\t[Name:            " << mage[i].getName() << endl;
				cout << "\t\t\t[Race:            " << mage[i].whatRace() << endl;
				cout << "\t\t\t[Attack:          " << mage[i].attack() << endl;
				cout << "\t\t\t[Starting health: " << mage[i].getHitPoints() << endl;
				cout << "\t\t\t[Attack Points:   " << mage[i].getAttackPoints() << endl;
				cout << "\t\t\t[Magic Points:    " << mage[i].getMagicPoints() << endl;

				if ((i + 1) != n)
					cout << "\t\t\t[-------------------------------------------]\n";
				else
					cout << "\t\t\t[===========================================]\n";
			}
			cout << endl;
		}
		else {
			cout << "\t\t\tNo mage characters found!\n\n";
		}
		return 1;
	}
}
