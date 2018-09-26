/*
Project 1

Sam Martel
martel.s@husky.neu.edu
 
Barry Yung
yung.b@husky.neu.edu

Class definition of 'code'. header file 'code.h'. Defines the memeber functions of the code class

Constructor
getcode
RandomCode
checkCorrect
checkIncorrect
getSecret
printSC
humanGuess
*/

#include <vector>
#include <iostream>											//include Vector
#include <stdlib.h>											//include standard libraries
#include "code.h"											//include code header

using namespace std;											//use stdlib namespace


///Constructor
///Parameters: int n, int m
///Return Type: Consructor
///Purpose: assign values to the private data values of the code class
Code::Code(int n, int m)
{
	leng = n;
	rang = m;
}

int Code::getL() const
{
	return leng;
}

int Code::getR() const
{
	return rang;
}

///RandomCode
///Parameters : None
///Return Type: void
///Purpose: Create a random code for the mastermind
void Code::randomCode()
{
	srand(time(0));
	for(int i = 0; i < leng; i++)
	{
		secCode.push_back(rand()%rang+1);
	}
	return;
}

///getCode
///Parameters: None
///Return Type: Void
///Purpose: Returns the code sequence
vector<int> Code::getCode() const
{
    return secCode; //returns the Code Array
}

///checkCorrect
///Parameters: Code Class
///Return Type: Integer
///Purpose: Determine how many numbers in the guess code are in the correct position
int Code::checkCorrect(const Code &test) const
{
	//Extract code from test code
	vector<int> testcode = test.getCode();
		if(testcode.empty())
		{cout << "Invalid Permissions" << endl;}
	//Declare Count values
	int count = 0;
	//Move through vector and test if correct
	for(int i = 0; i < leng; i++)
	{
		if(testcode.at(i) == secCode.at(i))
		{ count++;}
	}
	return count;
}

//printSC()
//Parameters: none
//Return Type: void
//Purpose prints secret code
void Code::printSC() const
{
    cout << "Secret Code is : ";
    //for loop to print through secCode Array
    for(int i = 0; i<leng; i++){
        cout << secCode[i] << " ";
    }
    cout << endl << endl;
}

///checkIncorrect
///Parameters: Code Class
///Retrun Type: integer
///Purpose: Check number of numbers of the guess are correct but in the wrong place
int Code::checkIncorrect(const Code &test) const
{
	vector<int> testcode = test.getCode();//Extract code from Code Class
		if(testcode.empty())
		{cout << "Invalid Permission" << endl;}

	int count = 0;//declare count variables
	int repeat = 0;

	for(int i = 0; i < leng; i++)//Move through the vector and check each element against one another
	{
		for(int k = 0;k < leng; k++)
		{
			//if a match is found and is not in the correct place
			if(testcode.at(i) == secCode.at(k) && secCode.at(k) != testcode.at(k))
			{
				//check if it is a repeat
				for(int j = 0; j < i; j++)
				{
					if(testcode.at(j) == testcode.at(i))
					{ repeat++;}
				}
				if(!repeat)
				{ count++;}
				repeat = 0;
			}
		}
	}
	return count;
}

//humanGuess
//Parameters:None
//Type: Void
//Purpose: Parses user to guess code
void Code::humanGuess()
{
    int x; //placeholder for user parse
    for(int i = 0; i < leng; i++)
    {
        cout << "Please input guess number " << i+1 << endl;
        cin >> x; //parses user for input number
        secCode.push_back(x); // adds the user input to the secCode array
        cout << endl;
        }
}
