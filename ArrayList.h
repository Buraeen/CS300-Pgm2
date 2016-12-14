// Brian Akins z429h475 Programming Assignment 02 for CS 300.


// Creating a header class for the program 02 store inventory management program.
// ArrayList Class Header program.  
// Since you are a seasoned C++ programmer, you are going to write a C++ program to  help manage inventory.

// add include guard to this file
#ifndef CS300_DS
#define CS300_DS

// we will define the capacity of array to be 100
// note that there is no semicolon followed by 100 
#define ARRAY_CAPACITY 100

class ArrayList
{
public:
 	
	// type can be easily changed here, and just here. 
	typedef Part value_type;

	// default constructor 
	ArrayList(){count = 0;}
	
	// we don't need copy constructor or custom constructor so far
	
	// addElement() function will add an element at the end. 
	//   return true if success. 
	//   return false if Array List is full.
	bool addElement(value_type newElement);
	
	// deleteElement() function will delete the element given by index. 
	//   return true if deleted.
	//   return false if incorrect index
	bool deleteElement(int index);
	
	// getElement() function will get element on index.
	//   pre-condition: index must be in proper range. 
	//   return the element to caller. 
	value_type getElement(int index);
	
	// setElement() function will set element on index. 
	//   pre-conditionL index must be in proper range. 
	void setElement(int index, value_type newElement);
	
	// getCount() function will return count to caller. 
	int getCount();
	
	
private:
	// two variables will be created here:
	//  1. one array to store elements, with preset capacity
	//  2. one integer to count how many elements in array. 
 	value_type array[ARRAY_CAPACITY];
 	int count;

};

/*
class LinkedList
{
public: 
	typedef Part* NodeP;
	
	// default constructor
	LinkedList(){head = NULL;}
	
	void addElement(NodeP newElement);
	
	// deleteElement should be more general. 
	// for now I will use PartNumber from Part as key
	//   to find the Node to be deleted. 
	// return true if found and deleted. 
	// return false if not found
	bool deleteElement(int key);
	
	NodeP getElement(int key);
	
	void setElement(int key);
	
	NodeP getHead(){return head;};

private:
	NodeP head;
	
	void setHead(NodeP newElement);

};
*/

#endif
