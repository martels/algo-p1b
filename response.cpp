#include "response.h"

using namespace std;

	Response::Response()
	{
		correct = 0;
		incorrect = 0;
	}

void	Response::setCorrect(int val)
	{
		correct = val;
	}

void	Response::setIncorrect(int val)
	{
		incorrect = val;
	}
int	Response::getCorrect() const
	{
		return correct;
	}
int	Response::getIncorrect() const
	{
		return incorrect;
	}

