#pragma once
#include "Hero.h"

class Rogue : public Hero
{
public:
	Rogue(string name);
	void Attack();
	void Defend();
	void Effect(int hp, int def, int atk);
	~Rogue();
};

