#include <iostream>
#include "Automata.h"
#include <string>

using namespace std;

int main()
{
	Automata cofeem = Automata();
	cofeem.on();
	cofeem.cash(40);
	cofeem.cash(35);
	cofeem.check(5); //75
	cofeem.off();

	return 0;

}