/*
Authors:
Sam Martel
martel.s@husky.neu.edu

Barry Yung
yung.b@husky.neu.edu

This program is a game of mastermind against the computer which generates a random code.

*/

///mastermind.h include the mastermind class and both the response and code classes
#include "mastermind.h"
///input and output
#include <iostream>


using namespace std;

///declares a new game and calls playgame
int main()
{
	///global declarations
	bool result = false;
	char select2 = 'n';

	///onscreen explaination of the game
	cout << endl << endl << "!!MASTERMIND!!" << endl << endl;
	cout << "You are playing a game of mastermind with the computer, the length of the code is 5 and numbers can be any integer from 0-9. The code is random."
	<< endl << "Your guess' will be tested against the secret code. The number of correct integers in your guess will be displayed on screen" << endl
	<< "along with the number of integers that are in the wrong place." << endl << endl << endl;

	///initialise the game
	Mastermind game;

	///play the game and determine who wins
	result = game.playGame();
	if(result == true)
	{
		cout << "Congratulations, you won" << endl;
	}

	else if(result == false)
	{
		cout << "You Lost.....Pity" << endl;
	}

	///ask to play again or exit
	cout << "Would you like to play again(y/n)? ";
	cin >> select2;

	if(select2 == 'y')
		return main();
	else if(select2 == 'n')
		return 0;
	return 0;
}

