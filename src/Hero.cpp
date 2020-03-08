#include "../include/Hero.h"

void Hero::Use()
{
	int choice, valid = 0;
	cout << *this->backpack;
	cout << this->name << " - which potion to drink?\n";
	cout << "1. Health Potion HP +25\n";
	cout << "2. Defense Potion DEF +30\n";
	cout << "3. Attack Potion ATK +20\n";
	cout << "4. Close backpack\n";
	while (!valid)
	{
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << this->name << " is drinking HP potion. HP +25\n";
			if (this->backpack->consumePotion(1))
			{
				this->Effect(25, 0, 0);
				valid = 1;
			}
			else cout << "You have no HP potions left, choose different option.\n";
			break;
		case 2:
			cout << this->name << " is drinking DEF potion. DEF +30\n";
			if (this->backpack->consumePotion(2))
			{
				this->Effect(0, 30, 0);
				valid = 1;
			}
			else cout << "You have no DEF potions left, choose different option.\n";
			break;
		case 3:
			cout << this->name << " is drinking ATK potion. ATK +20\n";
			if (this->backpack->consumePotion(3))
			{
				this->Effect(0, 0, 20);
				valid = 1;
			}
			else cout << "You have no ATK potions left, choose different option.\n";
			break;
		case 4:
			cout << this->name << " - no drinks this time.\n";
			valid = 1;
			break;
		default:
			cout << this->name << "Invalid choice... please try again!\n";
			valid = 0;
			break;
		}

	}
}


string Hero::getName()
{
	return this->name;
}

int Hero::getHP()
{
	return this->HP;
}

int Hero::getDEF()
{
	return this->DEF;
}

int Hero::getATK()
{
	return this->ATK;
}

void Hero::setDead()
{
	this->HP = 0;
	cout << this->name << endl;
	cout << *this;
	cout << "\n----------------------------------------" << endl;
	this->dead = 1;
}

bool Hero::getDead()
{
	return dead;
}


Hero::~Hero()
{
}
