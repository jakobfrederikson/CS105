#include <iostream>
#include <vector>
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
		cin >> name;
		setName(name);
	}

	string attack()
	{
		return "I will destroy you with my sword!";
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
		cin >> name;
		setName(name);
	}

	string attack()
	{
		return "I will assault you with holy wrath!";
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
		cin >> name;
		setName(name);
	}

	string attack()
	{
		return "I will crush you with my arcane missiles!";
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

	Race test = DEFAULT;
	int classChoice;
	int raceChoice;
	int characterCheck;

	// For do{}while() loops.
	bool True = true;
	bool raceTrue = true;

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

					switch (raceChoice)
					{
					case 1:
						test = HUMAN;
						raceTrue = false;
						break;
					case 2:
						test = ELF;
						raceTrue = false;
						break;
					case 3:
						test = DWARF;
						raceTrue = false;
						break;
					case 4:
						test = ORC;
						raceTrue = false;
						break;
					case 5:
						test = TROLL;
						raceTrue = false;
						break;
					default:
						cout << "\n\t\t\tWrong input entered! Please enter a number between 1-5.\n\n";
					}
				} while (raceTrue);
			}
			switch (classChoice)
			{
			case 1:
				w.createCharacter();
				w.setRace(test);
				warrior.push_back(w);
				cout << "\n\t\t\t[Character sucessfully created!]\n";
				cout << "\t\t\t";
				system("pause");
				break;
			case 2:
				p.createCharacter();
				p.setRace(test);
				priest.push_back(p);
				cout << "\n\t\t\t[Character sucessfully created!]\n";
				cout << "\t\t\t";
				system("pause");
				break;
			case 3:
				m.createCharacter();
				m.setRace(test);
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
				cout << "\t\t\tError! Please try again.\n\n";
			}
		}
		else 
		{
			cout << "\n\t\t\tWrong input entered! Please enter a number between 1-4.";
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
		cout << "\t\t\t[ WARRIOR LIST ]\n";

		// Checking whether vectors have data or not
		if (!warrior.empty()) {
			for (int i = 0; i < warrior.size(); i++)
			{
				cout << "\t\t\tI am a warrior named " << warrior[i].getName() << ". My race is " << warrior[i].whatRace() << ". My attack: " << warrior[i].attack() << endl;
			}
			cout << endl;
		}
		else {
			cout << "\t\t\tNo warrior characters found!\n\n";
		}

		cout << "\t\t\t[ PRIEST LIST ]\n";
		if (!priest.empty()) {
			for (int i = 0; i < priest.size(); i++)
			{
				cout << "\t\t\tI am a priest named " << priest[i].getName() << ". My race is " << priest[i].whatRace() << ". My attack: " << priest[i].attack() << endl;
			}
			cout << endl;
		}
		else {
			cout << "\t\t\tNo priest characters found!\n\n";
		}

		cout << "\t\t\t[ MAGE LIST ]\n";
		if (!mage.empty()) {
			for (int i = 0; i < mage.size(); i++)
			{
				cout << "\t\t\tI am a mage named " << mage[i].getName() << ". My race is " << mage[i].whatRace() << ". My attack: " << mage[i].attack() << endl;
			}
			cout << endl;
		}
		else {
			cout << "\t\t\tNo mage characters found!\n\n";
		}
		return 1;
	}
}
