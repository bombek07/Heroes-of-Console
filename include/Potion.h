#pragma once
#include <string>
#include <iostream>
using namespace std;

class Potion
{
private:
	int type;
public:
	Potion(int type);
	int getType();
	void consumePotion();
	~Potion();
};

