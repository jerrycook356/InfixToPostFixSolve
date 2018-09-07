/**@file Precedence.cpp*/

#include"pch.h"
#include "Precedence.h"


Precedence::Precedence() {

}//end default constructor

//ch must be a binary operator
int Precedence::orderOfPoperations(char ch)
{
	switch (ch)
	{

	case '*':
		return 2;
		break;
	case'/':
		return 2;
		break;
	case'+':
		return 1;
		break;
	case'-':
		return 1;
		break;
	case'(':
		return 0;
		break;
	case')':
		return 0;
		break;
	}


}