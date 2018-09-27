/*
Author:
Sam Martel
martel.s@husky.neu.edu

Barry Yung
yung.b@husky.neu.edu


response class definition
*/

#ifndef RESPONSE_H
#define RESPONSE_H
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Response
{
	private:
	int correct;
	int incorrect;

	public:
	Response();
void	setCorrect(int val);
void	setIncorrect(int val);
int	getCorrect() const;
int	getIncorrect() const;
};

///Operator overload for == regarding the response class
inline bool operator == (Response& lhs, Response& rhs)
{
        if(lhs.getCorrect() == rhs.getCorrect() && lhs.getIncorrect() == rhs.getIncorrect())
                return true;
        else
                return false;
}

///Operator overload for the ostream operator << regarding response class
inline ostream& operator<< (ostream& ostr, Response& r)
{
        ostr << "Correct: " << r.getCorrect() << ", Incorrect: " << r.getIncorrect();
        return ostr;
}

#endif
