#pragma once
// File Player.h -- Player base class. The derived classes of Player are located in Characters.h. 
//
//					NOTES:
//				    I have added these functions which were not included in the Lab 2 UML diagram:
//					- getAttackPoints(), setAttackPoints(int)
//					

enum Race { DEFAULT, HUMAN, ELF, DWARF, ORC, TROLL };

class Player
{
private:
	string name;
	int hitPoints;    // hitPoints = health
	int attackPoints; // attackPoints = physical damage
	int magicPoints;  // magicPoints = magical damage											  											  
	Race race;
public:
	Player(string defName = "DEFAULT_NAME", string defA = "DEFAULT_ATTACK", Race defRace = DEFAULT, int defHP = 0, int defAP = 0, int defMP = 0)
	{
		name = defName;
		race = defRace;
		attackPoints = defAP;
		hitPoints = defHP;
		magicPoints = defMP;
	}

	string whatRace()
	{
		switch (getRace())
		{
		case HUMAN:
			return "Human";
			break;
		case ELF:
			return "Elf";
			break;
		case DWARF:
			return "Dwarf";
			break;
		case ORC:
			return "Orc";
			break;
		case TROLL:
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
	int getAttackPoints()
	{
		return attackPoints;
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
	void setAttackPoints(int ap)
	{
		attackPoints = ap;
	}
	void setMagicPoints(int mp)
	{
		magicPoints = mp;
	}
	string attack()
	{
		return "No attack type defined yet!";
	}
};
