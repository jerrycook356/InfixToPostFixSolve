/**@file MyStack.h*/
#ifndef _MY_STACK
#define _My_STACK

#include "pch.h"
#include "StackInterface.h"
#include <array>

template<class ItemType>

class MyStack : public StackInterface<ItemType>
{
	const static int MAX_SIZE = 100;
private:
	int index;
	
	ItemType itemStorage[MAX_SIZE];
public:
	MyStack();
	bool isEmpty() const;
	bool push(const ItemType& newEntry);
	bool pop();
	ItemType peek()const;

};
#include "MyStack.cpp"
#endif // !_MY_STACK


