/**@file MyStack.cpp*/
#include "pch.h"

template<class ItemType>
 MyStack<ItemType>::MyStack():index(0)
{
}//end default constructor

 template<class ItemType>
 bool MyStack<ItemType>::isEmpty() const
 {
	 return index == 0;
 }

 template<class ItemType>
 bool MyStack<ItemType>::push(const ItemType & newEntry)
 {
	 if (index <= MAX_SIZE - 1)
	 {
		 itemStorage[index] = newEntry;
		 index++;
		 return true;
		 
	 }
	 
	 return false;
 }

 template<class ItemType>
 bool MyStack<ItemType>::pop()
 {
	 if (!isEmpty())
	 {
		
		 index--;
		 return true;
	 }
	 return false;
 }

 template<class ItemType>
 ItemType MyStack<ItemType>::peek()const
 {
	 if (index >= 1)
	 {
		 return itemStorage[index - 1];
	 }
 }