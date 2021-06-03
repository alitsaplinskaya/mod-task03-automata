#include "Automata.h"
#include <iostream>
using namespace std;

Automata::Automata()
{
	menu = new string[10];
	menu = ["latte", "esspreso", "double esspreso", "capuchino", "hot chocolate", "americano", "raf", "frappe", "glyasse", "makkiato"];
	price = new int[10];
	price =[50, 55, 60, 65, 70, 75, 80, 90, 100, 130];
	money = 0;
	NowStatus = OFF;
}
void Automata::on()
{
	NowStatus = wait;
	money = 0;
}
const string* Automata::etMenu()
{
	return menu;
}
Status Automata::getStatus()
{
	return NowStatus;
}
void Automata::cash(int inMoney) 
{
	if (getStatus() == wait || getStatus() == accept)
	{
		if (getStatus() == wait) {
			NowStatus = accept;
		}
		money += inMoney;
	}
}
void Automata::check(int checkup)
{
	if (getStatus() == accept)
	{
		NowStatus = control;
		if (proof(checkup - 1) && (checkup > 0) && (checkup < 10))
		{
			money -= price[checkup - 1];
			cook();

		}
		else cancel();
	}
}
bool Automata::proof(int checkup)
{
	if (getStatus() == control)
	{
		if (money - price[checkup] >= 0) return true;
		else return false;
	}
}
int Automata::cook()
{
	if (getStatus() == control)
	{
		NowStatus = cook;
		if (money == 0) 
			finish(); 
	}
}
int Automata::cancel()
{
	if (getStatus() == wait || getStatus() == control)
	{
		int temp = money; 
		NowStatus = wait;
		money = 0;
		return temp;
	}
	else return 0;
}
int Automata::finish()
{
	if (getStatus() == cook)
	{
		NowStatus = wait;
		int temp = money;
		money = 0;
		return temp;
	}
}
void Automata::off()
{
	NowStatus = off;
}
Automata::~Automata()
{
	delete[] menu;
	delete[] price;
}