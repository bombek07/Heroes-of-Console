#pragma once
#include<iostream>
#include <string>
#include "Bag.h"
using namespace std;
class Hero
{
protected:
	int HP, DEF, ATK;
	string name;
	Bag *backpack;
	bool dead = 0;
public:
	virtual ~Hero();
	virtual void Attack()=0;
	virtual void Defend()=0;
	virtual void Effect(int, int, int) = 0;
	void Use();
	int getHP();
	int getDEF();
	int getATK();
	string getName();
	void setDead();
	bool getDead();
	friend ostream& operator<<(ostream& stats, const Hero& hero)
	{
		stats << "HP: " << hero.HP << " DEF: " << hero.DEF << " ATK: " << hero.ATK;
		return stats;
	}
};

