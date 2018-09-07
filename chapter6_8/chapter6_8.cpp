// chapter6_8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include "MyStack.h"
#include "Precedence.h"

Precedence precedence = Precedence();

void evaluateInfix(std::string infixExp, StackInterface<char>* opStack, 
	StackInterface<std::string>* valStack);

bool isOperator(char ch);
void performOperation(StackInterface<char>* opStack, StackInterface<std::string>* valStack);
void convertToPostfix(std::string infixExp, StackInterface<char>* opStack);


int main()
{
	StackInterface<char>* opStack;
	StackInterface<std::string>* valStack;

    std::string infixExp;

	do
	{
		opStack = new MyStack<char>();
		valStack = new MyStack<std::string>();

		infixExp = "";
		std::cout << std::endl << "Enter the equation to be solved or enter \" . \" to quit: ";
		getline(std::cin, infixExp);
		if (!infixExp.empty())
		{
			convertToPostfix(infixExp, opStack);
			evaluateInfix(infixExp, opStack, valStack);
		}
		delete opStack;
		opStack = nullptr;
		delete valStack;
		valStack = nullptr;

	} while (infixExp != ".");

	

}

void convertToPostfix(std::string infixExp, StackInterface<char>* opStack)
{
	int index = 0;
	std::string converted = "";
	while (index < infixExp.length())
	{
		if (isdigit(infixExp[index]))
		{
			while (isdigit(infixExp[index]))
			{
				converted += infixExp[index];
				index++;
			}
			converted += " ";
		}
		else if (isOperator(infixExp[index]))
		{
			while (!opStack->isEmpty() && opStack->peek() != '(' && precedence.orderOfPoperations(infixExp[index] <=
				precedence.orderOfPoperations(opStack->peek())))
			{
				converted += opStack->peek();
				opStack->pop();
			}
			opStack->push(infixExp[index]);
			index++;
		}
		else if (infixExp[index] == '(')
		{
			opStack->push(infixExp[index]);
			index++;
		}
		else if (infixExp[index] == ')')
		{
			while (opStack->peek() != '(')
			{
				converted += opStack->peek();
				opStack->pop();
			}
			opStack->pop();
			index++;
		}
		else
		{
			index++;
		}
		

	}
	while (!opStack->isEmpty())
	{
		
		converted += opStack->peek();
		opStack->pop();
	}
	std::cout << std::endl << "The postfix expression of " << infixExp << " is : " << converted;
}
void evaluateInfix(std::string infixExp, StackInterface<char>* opStack,
	StackInterface<std::string>* valStack)
{
	int index = 0;
	std::string number;

	while (index < infixExp.length())
	{
		number = "";
		if (isdigit(infixExp[index]))
		{
			while (isdigit(infixExp[index])) {
				number += infixExp[index];
				index++;
			}
			valStack->push(number);
		}
		else if (infixExp[index] == '(')
		{
			opStack->push(infixExp[index]);
			index++;
		}
		else if (isOperator(infixExp[index]))
		{
			if (opStack->isEmpty())
			{
				opStack->push(infixExp[index]);
				index++;
			}
			else if (precedence.orderOfPoperations(infixExp[index]) > precedence.orderOfPoperations(opStack->peek()))
			{
				opStack->push(infixExp[index]);
				index++;
			}
			else
			{
				while (!opStack->isEmpty() && precedence.orderOfPoperations(infixExp[index]) <=
					precedence.orderOfPoperations(opStack->peek()))
					performOperation(opStack, valStack);
				opStack->push(infixExp[index]);
				index++;
			}
		}
		else if (infixExp[index] == ')')
		{
			while (opStack->peek() != '(')
				performOperation(opStack, valStack);
			opStack->pop();
			index++;
		}
		else
			index++;

	}
	while (!opStack->isEmpty())
	{
		performOperation(opStack, valStack);
	}
	std::cout << std::endl << "answer = " << valStack->peek();

}
bool isOperator(char ch)
{
	std::string operators = "*/+-";
	for (int i = 0; i < operators.length();i++)
	{
		if (ch == operators[i])
			return true;
	}
	return false;
}

void performOperation(StackInterface<char>* opStack, StackInterface<std::string>* valStack)
{

	int result = 0;

	int operand2 = stoi(valStack->peek());
	valStack->pop();

	int operand1 = stoi(valStack->peek());
	valStack->pop();

	char op = opStack->peek();
	opStack->pop();
	switch (op)
	{
	case '*':
		result = operand1 * operand2;
		break;
	case'/':
		result = operand1 / operand2;
		break;
	case'+':
		
		result = operand1 + operand2;
		break;
	case'-':
		result = operand1 - operand2;
	case'(':
		opStack->pop();
		break;
	
	}
	valStack->push(std::to_string(result));
}



