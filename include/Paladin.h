#pragma once
#include "Hero.h"
class Paladin : public Hero
{
public:
	Paladin(string name);
	void Attack();
	void Defend();
	void Effect(int hp, int def, int atk);
	~Paladin();
};

