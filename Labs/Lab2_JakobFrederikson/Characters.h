#pragma once
// File Characters.h  --  Holds every currently available class to the player.
//
//						 -Each class sets their custom hit points, attack points and magic points.
//
//						 -Each class also holds an attack function that sets the players attack based
//						  on their chosen class.

class Warrior : public Player
{
private:
	string playerAttack;
public:
	Warrior()
	{
		setHitPoints(105);
		setAttackPoints(120);
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
	void setAttack(int choice)
	{
		if (choice == 1)
		{
			playerAttack = "Bone crunching mace swing!";
		}
		else if (choice == 2)
		{
			playerAttack = "Slicing sword swipe!";
		}
		else if (choice == 3)
		{
			playerAttack = "Kidney bruising punch!";
		}
	}
	string attack()
	{
		return playerAttack;
	}
};

class Priest : public Player
{
private:
	string playerAttack;
public:
	Priest()
	{
		setHitPoints(100);
		setAttackPoints(20);
		setMagicPoints(90);
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
	void setAttack(int choice)
	{
		if (choice == 1)
		{
			playerAttack = "Blinding holy wrath!";
		}
		else if (choice == 2)
		{
			playerAttack = "Desperate prayer!";
		}
		else if (choice == 3)
		{
			playerAttack = "Shadow pain!";
		}
	}
	string attack()
	{
		return playerAttack;
	}
};

class Mage : public Player
{
private:
	string playerAttack;
public:
	Mage()
	{
		setHitPoints(100);
		setAttackPoints(0);
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
	void setAttack(int choice)
	{
		if (choice == 1)
		{
			playerAttack = "Spikey frostbolt!";
		}
		else if (choice == 2)
		{
			playerAttack = "Melting fireball!";
		}
		else if (choice == 3)
		{
			playerAttack = "Luminous Arcane Missiles!";
		}
	}
	string attack()
	{
		return playerAttack;
	}
};
