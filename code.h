/*
code.h

Sam Martel
martel.s@husky.neu.edu

Barry Yung
yung.b@husky.neu.edu

declarations for Code class, part of project 1 part a in eece2560
*/


#ifndef CODE_H
#define CODE_H


#include <stdlib.h>
#include <vector>

using namespace std;

class Code
{
	private:
	int leng;								//Length of the Code
	int rang;								//Range of the Code
	vector<int> secCode;							//Code Varible

	public:
	Code(int n, int m); 					                //Constructor
	int getL() const;
	int getR() const;
	vector<int> getCode() const;							//Returns Code if it is a guess code
	void randomCode();							//Randomises secret code
	int checkCorrect(const Code &test) const;						//Checks correct numbers in the guess code
	int checkIncorrect(const Code &test) const;            				//Checks incorrect placement of numbers in guess code
    	void printSC() const;                             				//Prints the secret code
    	void humanGuess();                          				//Parses user for guess code
};

#endif

