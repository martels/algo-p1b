#include "mastermind.h"
#include "code.h"

#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;


int main()
{
	bool result = false;
	int length = 5 , range = 9;
	char select2 = 'n';
	cout << "Please enter length of code: ";
	cin >> length;
	cout << "Please enter Range of code: ";
	cin >> range;
	Mastermind game(length, range);
	cout << endl << endl;

	result = game.playGame();
	if(result == true)
	{
		cout << "Congratulations, you won" << endl;
	}

	else if(result == false)
	{
		cout << "You Lost.....Pity" << endl;
	}

	cout << "Would you like to play again(y/n)? ";
	cin >> select2;

	if(select2 == 'y')
		return main();
	else if(select2 == 'n')
		return 0;
}

