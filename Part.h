// Brian Akins z429h475 Programming Assignment 02 for CS 300.


// Creating a header class for the program 02 store inventory management program.
// Part Class Header program.   
// Since you are a seasoned C++ programmer, you are going to write a C++ program to  help manage inventory.

#include <string>				// for string type

class Part
{
	private:
	int partNum;
	string description;
	int quantity;
	float unitPrice;

	public: 
	//Default contrsuctor.
	Part () 
	{
		partNum = 0; 
		description = " "; 
		quantity = 0; 
		unitPrice = 0;
	}  
	
	//Setters
	void setPartNum(int);
	void setDescription(string);
	void setQuantity(int);
	void setUnitPrice(float);
	
	//Getters
	int getPartNum(){return partNum;}
	string getDescription() {return description;}
	int getQuantity() {return quantity;}
	float getUnitPrice() {return unitPrice;}

};

