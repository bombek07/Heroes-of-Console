#pragma once
#include "Hero.h"
class Warrior : public Hero
{
public:
	Warrior(string name);
	void Attack();
	void Defend();
	void Effect(int hp, int def, int atk);
	~Warrior();
};

