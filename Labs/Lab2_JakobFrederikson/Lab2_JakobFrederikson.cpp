#include <iostream>
using namespace std;

enum Race { DEFAULT, HUMAN, ELF, DWARF, ORC, TROLL };

class PlayerBase
{
private:
	string name;
	int hitPoints, magicPoints;
	Race race;
public:
	PlayerBase(string defStr = "DEFAULT_STRING", Race defRace = DEFAULT, int defInt = 0)
	{
		name = defStr;
		race = defRace;
		hitPoints = defInt;
		magicPoints = defInt;
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

class Warrior : private PlayerBase
{
	void getDetails()
	{

	}
};

class Priest : private PlayerBase
{

};

class Mage : private PlayerBase
{

};

int main()
{
	cout << "[=================================]\n";
	cout << "[       CHARACTER CREATION        ]\n";
}
