/*
 * Expression.cpp
 *
 *  Created on: Apr 10, 2018
 *      Author: David (GitHub: DPigeon)
 */

#include <iostream>
#include <stack>
#include "Expression.h"

using namespace std;

Expression::Expression(string input) {
	infix = input;
	cout<<"You are about to convert from prefix to postfix !"<<endl;
	}

int Expression::getPriority(char p){
	int priority;
	if(p == '+' || p == '-') //last priority
		priority = 3;
	else if(p == '*' || p == '/') //second priority
		priority = 2;
	else if(p == '^') //first priority
		priority = 1;
	return priority;
}

string Expression::inToPost(){ //converting infix to postfix
	stack<char> opStack;
	string out;
	for(size_t i = 0; i < infix.length(); i++){ //looking through the expression for each char in input
		if(infix[i] == '('){ //for first parentize
			opStack.push(infix[i]); //push on stack
		}
		else if(infix[i] == ')'){ //for last parentize
		//check if there is a ( on top to continue
			while(!opStack.empty() && opStack.top() != '('){
				out.push_back(opStack.top());
				opStack.pop();
			}
			opStack.pop();
		}
		else if(infix[i] == '^' || infix[i] == '*' || infix[i] == '/' || infix[i] == '-' || infix[i] == '+'){ //for all the operators
			while(!opStack.empty() && getPriority(opStack.top()) <= getPriority(infix[i]) && opStack.top() != '('){ //here, we are looking if the stack is not empty and the priority
				out.push_back(opStack.top());
				opStack.pop();
			}
			opStack.push(infix[i]); //if stack is empty push
		}
		else { //operands
				out.push_back(infix[i]);
		}
	}
	while(!opStack.empty()){
		out.push_back(opStack.top());
		opStack.pop();
	}
	return out;
}
