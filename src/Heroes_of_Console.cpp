#include <iostream>
#include <string>
#include <windows.h>
#include "../include/Hero.h"
#include "../include/Warrior.h"
#include "../include/Mage.h"
#include "../include/Hunter.h"
#include "../include/Rogue.h"
#include "../include/Paladin.h"

using namespace std;

Hero *heroSelection(string player);
void action(Hero *hero);

int main()
{
	string player1, player2;
	int turn = 1;
    cout << "Welcome to Heroes of Console!\n\n"; 
	cout << "Set Player's 1 name: ";
	cin >> player1;
	cout << "Set Player's 2 name: ";
	cin >> player2;
	Hero *hero1 = heroSelection(player1);
	Hero *hero2 = heroSelection(player2);
	while (true)
	{
		cout << "\n=========================================\nTurn " << turn << endl;
		Sleep(1000);
		cout << "FIGHT!!!\n\n";
		action(hero1);
		action(hero2);

		int dmgToH2 = hero2->getDEF() - hero1->getATK();
		int defToH2 = -(hero1->getATK() / 2);
		if (dmgToH2 > 0) dmgToH2 = 0;

		int dmgToH1 = hero1->getDEF() - hero2->getATK();
		int defToH1 = -(hero2->getATK() / 2);
		if (dmgToH1 > 0) dmgToH1 = 0;

		hero2->Effect(dmgToH2, defToH2, 0);
		hero1->Effect(dmgToH1, defToH1, 0);

		cout << hero1->getName() << "\t\t\t"<<hero2->getName() << endl;
		cout << *hero1;
		cout << "\t";
		cout << *hero2;
		cout << "\n\n";
		if (hero1->getDead() || hero2->getDead()) break;
		turn++;
	}

	delete hero1;
	delete hero2;
	cout << "Thanks for playing. ";
}

Hero *heroSelection(string player)
{
	bool valid = 0;
	int choice;
	Hero *hero = NULL;
	cout << "\n" << player << " - Choose your console figher!\n";
	cout << "1. Warrior\n";
	cout << "2. Mage\n";
	cout << "3. Hunter\n";
	cout << "4. Rogue\n";
	cout << "5. Paladin\n";
	while(valid==0)
	{
		cin >> choice;
		switch (choice)
		{
		case 1:
			hero = new Warrior(player);
			valid = 1;
			break;
		case 2:
			hero = new Mage(player);
			valid = 1;
			break;
		case 3:
			hero = new Hunter(player);
			valid = 1;
			break;
		case 4:
			hero = new Rogue(player);
			valid = 1;
			break;
		case 5:
			hero = new Paladin(player);
			valid = 1;
			break;
		default:
			cout << "Invalid selection... Please try again!\n";
			valid = 0;
			break;
		}
	}
	return hero;
}

void action(Hero *hero)
{
	bool end = 0;
	int choice;
	do
	{
		cout << hero->getName() << " - Choose your action!\n";
		cout << "1. Attack\n";
		cout << "2. Defend\n";
		cout << "3. Use\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout <<  hero->getName() << " is attacking!\n";
			hero->Attack();
			end = 1;
			break;
		case 2:
			cout <<  hero->getName() << " is defending himself!\n";
			hero->Defend();
			end = 1;
			break;
		case 3:
			cout <<  hero->getName() << " is using a potion!\n";
			hero->Use();
			end = 0;
			break;
		default:
			cout << "Invalid selection... Please try again!\n";
			end = 0;
			break;
		}
	} while (end == 0);
}
