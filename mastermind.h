/*
Authors:
Sam Martel
martel.s@husky.neu.edu

Barry Yung
yung.b@husky.neu.edu

mastermind class definition
*/

#ifndef MASTERMIND_H
#define MASTERMIND_H
#include <iostream>
#include <stdlib.h>
#include <vector>
#include "code.h"
#include "response.h"

class Mastermind
{
	private:
Code		secret;

	public:
		Mastermind();
		Mastermind(int l, int r);
void		printSecret();
Code		humanGuess();
Response	getResponse(const Code& guess) const;
bool		isSolved(const Response& r) const;
bool		playGame();
};


#endif

