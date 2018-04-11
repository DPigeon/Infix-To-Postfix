/*
 * main.cpp
 *
 *  Created on: Apr 10, 2018
 *      Author: David (GitHub: DPigeon)
 */

#include <iostream>
#include "Expression.h"

using namespace std;

int main(){
	string input;
	cout<<"Type your infix expression"<<endl;
	cin>>input;
	Expression MyEx(input); // Infix expression
	string exp1 = MyEx.inToPost();
	cout<<"Your converted expression is: "<<exp1<<endl;
	return 0;
}
