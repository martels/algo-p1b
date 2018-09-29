/*
Authors:
Sam Martel
martel.s@husky.neu.edu

Barry Yung
yung.b@husky.neu.edu

member function definitions for the mastermind class
*/

#include "mastermind.h"
#include "code.h"
#include "response.h"
#include <iostream>
#include <stdlib.h>
#include <vector>

		///Constructor with 2 integer parameters
		Mastermind::Mastermind(int l, int r) : secret(l, r){}

		///default constructor
		Mastermind::Mastermind() : secret(5, 9){}

		//Prints the seret code
void		Mastermind::printSecret()
		{
			secret.printSC();
		}

		///asks for human guess and commits it to a new code object
Code		Mastermind::humanGuess()
		{
			///sets the new geuess to the right legnth and range
			Code temp(secret.getL(), secret.getR());
			///gets the inout from the user
			temp.humanGuess();
			return temp;
		}

		///Returns a response object from a code  object
Response	Mastermind::getResponse(const Code& guess) const
		{
			Response temp;
			///sets the private members of response
			temp.setCorrect(secret.checkCorrect(guess));
			temp.setIncorrect(secret.checkIncorrect(guess));
			return temp;
		}

		///Checks if the code is solved
bool 		Mastermind::isSolved(const Response& r) const
		{
			///If the number of correct is equal to the length of the code then tthe code is solved
			if(secret.getL() == r.getCorrect())
				return true;
			else
				return false;
		}

		///Plays the game
bool		Mastermind::playGame()
		{
			///Declare a return value and a count
			bool check = false;
			int count = 10;
			Response resp;
			///randomises the code 
			secret.randomCode();
			///prints the secret for debugging
//			printSecret();
			///runs the game while the code is not solved or the count has not run out
			while(check == false && count >= 0)
			{
				resp = getResponse(humanGuess());
				cout << resp << endl << endl;
				cout << "You have " << count-1 << " attempts remaining" << endl << endl;
				check = isSolved(resp);
				count--;
			}
			///determine who wins
			if(count == 0)
				return false;
			else if(check == true)
				return true;
			return false;
		}
