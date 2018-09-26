#include "mastermind.h"
#include "code.h"
#include "response.h"
#include <iostream>
#include <stdlib.h>
#include <vector>

		Mastermind::Mastermind(int l, int r) : secret(l, r){}

		Mastermind::Mastermind() : secret(5, 10){}

void		Mastermind::printSecret()
		{
			secret.printSC();
		}

Code		Mastermind::humanGuess()
		{
			Code temp(secret.getL(), secret.getR());
			temp.humanGuess();
			return temp;
		}

Response	Mastermind::getResponse(const Code& guess) const
		{
			Response temp;
			temp.setCorrect(secret.checkCorrect(guess));
			temp.setIncorrect(secret.checkIncorrect(guess));
			return temp;
		}

bool 		Mastermind::isSolved(const Response& r) const
		{
			if(secret.getL() == r.getCorrect())
				return true;
			else
				return false;
		}

bool		Mastermind::playGame()
		{
			bool check = false;
			int count = 10;
			Response resp;
			secret.randomCode();
			printSecret();
			while(check == false && count >= 0)
			{
				resp = getResponse(humanGuess());
				cout << resp << endl << endl;
				cout << "You have " << count-1 << " attempts remaining" << endl << endl;
				check = isSolved(resp);
				count--;
			}
			if(count == 0)
				return false;
			else if(check == true)
				return true;
			return false;
		}
