#pragma once
#include "Hero.h"
class Mage : public Hero
{
public:
	Mage(string name);
	void Attack();
	void Defend();
	void Effect(int hp, int def, int atk);
	~Mage();
};

