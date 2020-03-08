#include "../include/Rogue.h"


Rogue::Rogue(string name)
{
	cout << "New Rogue " << name << " appeared in the Console!\n";
	this->HP = 80;
	this->DEF = 40;
	this->ATK = 40;
	this->name = name;
	this->backpack = new Bag(3, 3, 3);
}
void Rogue::Attack()
{
	this->ATK += 10;
	cout << *this;
	cout << "\n----------------------------------------" << endl;
}
void Rogue::Defend()
{
	this->DEF += 5;
	cout << "Rogue " << this->name << " found a DEF potion!\n";
	this->backpack->addPotions(2, 1);
	cout << *this;
	cout << "\n----------------------------------------" << endl;
}

void Rogue::Effect(int hp, int def, int atk)
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
			cout << "Def = 0 - Rogue " << this->name << " is exposed! ATK -15\n";
			this->ATK -= 15;
		}
		this->ATK += atk;
		if (this->getATK() > 75) this->ATK = 75;
	}
}


Rogue::~Rogue()
{
	if (dead) cout << "Rogue " << this->name << " has been defeated by law...\n\n";
	else cout << "Rogue " << this->name << " backstabbed his enemy and WON!\n\n";
}
