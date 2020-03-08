#include "../include/Hunter.h"


Hunter::Hunter(string name)
{
	cout << "New Hunter " << name << " appeared in the Console!\n";
	this->HP = 100;
	this->DEF = 20;
	this->ATK = 30;
	this->name = name;
	this->backpack = new Bag(3, 3, 3);
}
void Hunter::Attack()
{
	this->ATK += 20;
	cout << *this;
	cout << "\n----------------------------------------" << endl;
}
void Hunter::Defend()
{
	this->DEF += 10;
	cout << *this;
	cout << "\n----------------------------------------" << endl;
}

void Hunter::Effect(int hp, int def, int atk)
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
		if(this->ATK>75)
		{
			cout << "ATK > 75 - Hunter " << this->name << " cut himself with super sharp arrow! HP -10\n";
			this->HP -= 10;
			if (this->getHP() <= 0)
			{
				this->setDead();
			}
			if (this->getATK() > 100) this->ATK = 75;
		}
	}
}

Hunter::~Hunter()
{
	if (dead) cout << "Hunter " << this->name << " became the prey and has been defeated...\n\n";
	else cout << "Hunter " << this->name << " has WON and caught his prey!\n\n";
}
