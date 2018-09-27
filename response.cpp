/*
Authors:
Sam Martel
martel.s@husky.neu.edu

Barry Yung
yung.b@husky.neu.edu

response memeber function definitions
*/

#include "response.h"

using namespace std;

	///default constructor
	Response::Response()
	{
		correct = 0;
		incorrect = 0;
	}

	///set value (correct)
void	Response::setCorrect(int val)
	{
		correct = val;
	}

	///set value (Incorrect)
void	Response::setIncorrect(int val)
	{
		incorrect = val;
	}

	///get value (correct)
int	Response::getCorrect() const
	{
		return correct;
	}

	///get value (Incorrect)
int	Response::getIncorrect() const
	{
		return incorrect;
	}

