/**@file StackInterface.h*/
#ifndef _STACK_INTERFACE
#define _STACE_INTERFACE

template<class ItemType>
class StackInterface
{
public:
	/**sees whether the stack is empty
	@return true if the stack is empty false otherwise*/
	virtual bool isEmpty() const = 0;

	/**Adds a new entry to the top of this stack
	@post if the operation was successful, newEntry is at the top of the stack.
	@param newEntry the object to be added as a new entry
	@return true if the addition is successfull false otherwise*/
	virtual bool push(const ItemType& newEntry) = 0;

	/**Removes the top of this stack
	@post if the operation is successful, the top of the stack has been removed
	@return true if the operation is successfull false otherwise*/
	virtual bool pop() = 0;

	/**returns a copy of the top if this stack
	@pre the stack is not empty
	@post a copy of the top of the stack has been returned, and the stack in unchanged
	@return a copy of the top of the stack*/
	virtual ItemType peek() const = 0;

	/**destroys this stack and frees its assigned memory*/
	~StackInterface() {}
};//end StackInterface
#endif // !_STACK_INTERFACE

