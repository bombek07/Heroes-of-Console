#include "../include/Mage.h"


Mage::Mage(string name)
{
	cout << "New Mage " << name << " appeared in the Console!\n";
	this->HP = 100;
	this->DEF = 20;
	this->ATK = 20;
	this->name = name;
	this->backpack = new Bag(3, 3, 3);
}
void Mage::Attack()
{
	this->ATK += 20;
	this->DEF -= 7;
	if (this->ATK == 50)
	{
		cout << "ATK = 50 - Mage " << this->name << " casted a firebal! ATK +50\n";
		this->ATK += 50;
	}
	cout << *this;
	cout << "\n----------------------------------------" << endl;
}
void Mage::Defend()
{
	this->DEF += 30;
	this->ATK -= 10;
	if (this->ATK == 50)
	{
		cout << "ATK = 50 - Mage " << this->name << " casted a firebal! ATK +50\n";
		this->ATK += 50;
	}
	cout << *this;
	cout << "\n----------------------------------------" << endl;
}

void Mage::Effect(int hp, int def, int atk)
{
	this->HP += hp;
	if (this->getHP() <= 0)
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
			this->DEF = 0;
		}
		this->ATK += atk;
		if (this->getATK() > 75) this->ATK = 75;
	}
}

Mage::~Mage()
{
	if (dead) cout << "Mage " << this->name << " has been defeated. He casted a wrong spell at a wrong time...\n\n";
	else cout << "Mage " << this->name << " has WON! Magic proved to be superior.\n\n";
}
