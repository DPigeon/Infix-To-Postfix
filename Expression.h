/*
 * Expression.h
 *
 *  Created on: Apr 10, 2018
 *      Author: David (GitHub: DPigeon)
 */

#ifndef Expression_h
#define Expression_h

#include <iostream>

using namespace std;

class Expression{
	private:
		string infix;
		string postfix;
	public:
		Expression(string); //initial constructor
		int getPriority(char); //gets the operator priority
		string inToPost(); // Converts infix expression to postfix
};

#endif
