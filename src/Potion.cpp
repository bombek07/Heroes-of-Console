#include "../include/Potion.h"


Potion::Potion(int type) : type(type)
{
}

int Potion::getType()
{
	return this->type;
}

void Potion::consumePotion()
{
	delete this;
}

Potion::~Potion()
{
}
