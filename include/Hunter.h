#pragma once
#include "Hero.h"
class Hunter : public Hero
{
public:
	Hunter(string name);
	void Attack();
	void Defend();
	void Effect(int hp, int def, int atk);
	~Hunter();
};

