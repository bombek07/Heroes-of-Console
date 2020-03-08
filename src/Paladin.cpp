#include "../include/Paladin.h"


Paladin::Paladin(string name)
{
	cout << "New Paladin " << name << " appeared in the Console!\n";
	this->HP = 100;
	this->DEF = 25;
	this->ATK = 25;
	this->name = name;
	this->backpack = new Bag(3, 3, 3);
}
void Paladin::Attack()
{
	this->ATK += 10;
	cout << *this;
	cout << "\n----------------------------------------" << endl;
}
void Paladin::Defend()
{
	this->DEF += 5;
	this->HP += 10;
	cout << *this;
	cout << "\n----------------------------------------" << endl;
}

void Paladin::Effect(int hp, int def, int atk)
{
	this->HP += hp;
	if (this->getHP() <= 0)
	{
		this->setDead();
	}
	else
	{
		if (this->getHP() < 50)
		{
			cout << "HP < 50 - Paladin " << this->name << " Divine's Blessing ability activated! HP +15\n";
			this->HP += 15;
		}
		if (this->getHP() > 100) this->HP = 100;
		this->DEF += def;
		if (this->getDEF() > 50) this->DEF = 50;
		else if (this->getDEF() < 0)
		{
			this->DEF = 0;
		}
		this->ATK += atk;
		if (this->getATK() > 75) this->ATK = 75;
	}
}


Paladin::~Paladin()
{
	if (dead) cout << "Paladin " << this->name << " has been defeated and his lantern no longer shines...\n\n";
	else cout << "Paladin " << this->name << " has WON! Praise the sun!\n\n";
}
