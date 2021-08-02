#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

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
		int choice;
		bool True = true;

		cout << "\t\t\t[=======================================]\n";
		cout << "\t\t\t[Choose your characters race:           ]\n";
		cout << "\t\t\t[1. Human                               ]\n";
		cout << "\t\t\t[2. Elf                                 ]\n";
		cout << "\t\t\t[3. Dwarf                               ]\n";
		cout << "\t\t\t[4. Orc                                 ]\n";
		cout << "\t\t\t[5. Troll                               ]\n";
		cout << "\t\t\t[=======================================]\n";
		do {
			cout << "\t\t\t[Enter choice here: ";
			cin >> choice;
			switch (choice)
			{
			case 1:
				return "Human";
				True = false;
				break;
			case 2:
				return "Elf";
				True = false;
				break;
			case 3:
				return "Dwarf";
				True = false;
				break;
			case 4:
				return "Orc";
				True = false;
				break;
			case 5:
				return "Troll";
				True = false;
				break;
			default:
				cout << "\t\t\tWrong input entered! Please enter a number between 1-5.\n\n";
			}
		} while (True);
		cout << endl;
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
	void getMagicPoints(int mp)
	{
		magicPoints = mp;
	}
	string attack()
	{
		return "No attack method defined yet!";
	}
};

class Warrior:private Player
{
public:
	void createCharacter()
	{
		string race, name;
		Race r;

		setHitPoints(200);
		getMagicPoints(0);

		race = whatRace();
		if (race == "Human")
		{
			r = HUMAN;
		}
		else if (race == "Elf")
		{
			r = ELF;
		}
		else if (race == "Dwarf")
		{
			r = DWARF;
		}
		else if (race == "Orc")
		{
			r = ORC;
		}
		else if (race == "Troll")
		{
			r = TROLL;
		}
		setRace(r);

		cout << "\t\t\t[==========================]\n";
		cout << "\t\t\t[Enter characters name: ";
		cin >> name;
		setName(name);
	}
};

class Priest:private Player
{
public:
	void createCharacter()
	{
		string race, name;
		Race r;

		setHitPoints(100);
		getMagicPoints(200);

		race = whatRace();
		if (race == "Human")
		{
			r = HUMAN;
		}
		else if (race == "Elf")
		{
			r = ELF;
		}
		else if (race == "Dwarf")
		{
			r = DWARF;
		}
		else if (race == "Orc")
		{
			r = ORC;
		}
		else if (race == "Troll")
		{
			r = TROLL;
		}
		setRace(r);

		cout << "\t\t\t[==========================]\n";
		cout << "\t\t\t[Enter characters name: ";
		cin >> name;
		setName(name);
	}
};

class Mage:private Player
{
public:
	void createCharacter()
	{
		string race, name;
		Race r;

		setHitPoints(100);
		getMagicPoints(200);

		race = whatRace();
		if (race == "Human")
		{
			r = HUMAN;
		}
		else if (race == "Elf")
		{
			r = ELF;
		}
		else if (race == "Dwarf")
		{
			r = DWARF;
		}
		else if (race == "Orc")
		{
			r = ORC;
		}
		else if (race == "Troll")
		{
			r = TROLL;
		}
		setRace(r);

		cout << "\t\t\t[==========================]\n";
		cout << "\t\t\t[Enter characters name: ";
		cin >> name;
		setName(name);
	}
};

int displayCharacters(vector<Warrior> warrior, vector<Priest> priest, vector<Mage> mage);

int main()
{
	Warrior w;
	Priest p;
	Mage m;
	vector<Warrior> warrior;
	vector<Priest> priest;
	vector<Mage> mage;

	int choice;
	int characterCheck;
	bool True = true;

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
		cin >> choice;

		switch (choice)
		{
		case 1:
			w.createCharacter();
			warrior.push_back(w);
			cout << "\n\t\t\t[Character sucessfully created!]\n";
			cout << "\t\t\t";
			system("pause");
			break;
		case 2:
			p.createCharacter();
			priest.push_back(p);
			cout << "\n\t\t\t[Character sucessfully created!]\n";
			cout << "\t\t\t";
			system("pause");
			break;
		case 3:
			m.createCharacter();
			mage.push_back(m);
			cout << "\n\t\t\t[Character sucessfully created!]\n";
			cout << "\t\t\t";
			system("pause");
			break;
		case 4:
			characterCheck = displayCharacters(warrior, priest, mage);
			if (characterCheck == 0)
			{
				char exit;
				cout << "\n\t\t\t[You have no created characters! Exit anyway?(y/n): ";
				cin >> exit;
				if (towlower(exit) == 'y') {
					True = false;
					break;
				}
				else
				{
					break;
				}
			}
			else if (characterCheck == 1)
			{
				True = false;
				break;
			}
		default:
			cout << "\t\t\tWrong input entered! Please enter a number between 1-4.\n\n";
		}
	} while (True);
}

int displayCharacters(vector<Warrior> warrior, vector<Priest> priest, vector<Mage> mage)
{
	if (warrior.empty() && priest.empty() && mage.empty())
	{
		return 0;
	}
	else 
	{
		system("cls");
		if (!warrior.empty()) {
			cout << "\t\t\t[ WARRIOR LIST ]\n";
			cout << "\t\t\t";
			for (int i = 0; i < warrior.size(); i++)
			{
			}
		}
		

		return 1;
	}
}
