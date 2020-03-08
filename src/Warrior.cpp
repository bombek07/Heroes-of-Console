#include "../include/Warrior.h"


Warrior::Warrior(string name)
{
	cout << "New Warrior " << name << " appeared in the Console!\n";
	this->HP = 100;
	this->DEF = 30;
	this->ATK = 25;
	this->name = name;
	this->backpack = new Bag(3, 3, 3);
}
void Warrior::Attack()
{
	this->ATK += 10;
	cout << *this;
	cout << "\n----------------------------------------" << endl;
}
void Warrior::Defend()
{
	this->DEF += 10;
	cout << *this;
	cout << "\n----------------------------------------"<< endl;
}

void Warrior::Effect(int hp, int def, int atk)
{
	this->HP += hp;
	if (this->getHP()<=0)
	{
		this->setDead();
	}
	else
	{
		if (this->getHP() > 100) this->HP = 100;
		this->DEF += def;
		if (this->getDEF() > 50) this->DEF = 50;
		else if (this->getDEF() < 0)
		{
			cout << "DEF = 0 - Warrior " << this->name << " Berserk ability activated, DEF +20\n";
			this->DEF = 20;
		}
		this->ATK += atk;
		if (this->getATK() > 75) this->ATK = 75;
	}
	

}

Warrior::~Warrior()
{
	if(dead) cout << "Warrior " << this->name << " has been defeated and left the battlefield on his shield...\n\n";
	else cout << "Warrior " << this->name << " has WON and left the battlefield with his shield!\n\n";
}
