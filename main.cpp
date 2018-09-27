#include "mastermind.h"
#include "code.h"

#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;


int main()
{
	bool result = false;
	char select2 = 'n';
	cout << endl << endl << "!!MASTERMIND!!" << endl << endl;
	cout << "You are playing a game of mastermind with the computer, the length of the code is 5 and numbers can be any integer from 0-9. The code is random."
	<< endl << "Your guess' will be tested against the secret code. The number of correct integers in your guess will be displayed on screen" << endl
	<< "along with the number of integers that are in the wrong place." << endl << endl << endl;

	Mastermind game;
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

