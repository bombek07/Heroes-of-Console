#include "../include/Bag.h"


Bag::Bag(int hp, int def, int atk)
{
	this->hp = 0;
	this->def = 0;
	this->atk = 0;
	this->addPotions(1, hp);
	this->addPotions(2, def);
	this->addPotions(3, atk);
}

void Bag::addPotions(int type, int count)
{
	if (type == 1) this->hp += count;
	else if (type == 2) this->def += count;
	else if (type == 3) this->atk += count;
	this->bag.insert(bag.begin(), count, new Potion(type));
}

bool Bag::consumePotion(int type)
{
	bool positive = 0;
	for (auto it = this->bag.begin(); it != this->bag.end();)
	{
		if ((*it)->getType() == type)
		{
			this->bag.erase(it);
			switch (type)
			{
			case 1: this->hp--; break;
			case 2: this->def--; break;
			case 3: this->atk--; break;
			default: break;
			}
			positive = 1;
			break;
		}
		else it++;
	}
	return positive;
}

Bag::~Bag()
{
}
