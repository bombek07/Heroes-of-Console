#pragma once
#include <list>
#include "Potion.h" 

class Bag
{
private:
	list<Potion*> bag;
	int hp, def, atk;
public:
	Bag(int hp, int def, int atk);
	void addPotions(int type, int count);
	bool consumePotion(int type);
	friend ostream& operator<<(ostream& amount, const Bag& bag)
	{
		amount << "HP[" << bag.hp << "]\tDEF[" << bag.def << "]\tATK[" << bag.atk << "]\n";
		return amount;
	}
	~Bag();
};

