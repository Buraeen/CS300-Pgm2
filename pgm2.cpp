// Brian Akins z429h475 Programming Assignment 02 for CS 300.


// Creating the main cpp file for the program 02 store inventory management program.
// Since you are a seasoned C++ programmer, you are going to write a C++ program to  help manage inventory.

#include <iostream>				// for std::cin and std::cout
#include <fstream>	
#include <string>				// for string type

using namespace std;

#include "Part.h"
#include "ArrayList.h"

// The part number setter function.
void Part::setPartNum(int pNum)
{ partNum=pNum;}
	
// The Description setter function.	
void Part::setDescription(string desc)
{ description=desc; }

// The Quantity setter function.
void Part::setQuantity(int quant)
{ quantity = quant; }

// The Unit Price setter function.
void Part::setUnitPrice(float uPrice)
{ unitPrice = uPrice; }

// pitfall: use ArrayList::value_type, not value_type

bool ArrayList::addElement(ArrayList::value_type newElement)
{
	if (count < ARRAY_CAPACITY)
	{
		array[count] = newElement;
		count++;
		return true;
	}
	else 
		return false;	

}

bool ArrayList::deleteElement(int index)
{
	if (index < count)
	{
		for (int i = index; i < count - 1; i ++)
		{
			array[i] = array[i + 1];
		}
		count--;
		return true;
	}
	else 
		return false;
}

// pre-condition for getElement(): index must be in range, i.e. less than count
ArrayList::value_type ArrayList::getElement(int index)
{
	return array[index];
}

// pre-condition for setElement(): index must be in range, i.e. less than count
void ArrayList::setElement(int index, ArrayList::value_type newElement)
{
	array[index] = newElement;
}

// Function for giving out the current count of the array.
int ArrayList::getCount()
{
	return count;
}



void printAllParts(ArrayList);
void addPart(ArrayList&);
void modPart(ArrayList&, int);
void printCost(ArrayList);
void fileIORead(ArrayList&);
void fileIOWrite(ArrayList);

int main()
{
	
	
	// array of size 100
	ArrayList inventory;// array class to hold Part objects.
	
	//Part arr[100];   	// array to hold objects.
	
	//int count = 0;  	// count to tell how many different parts are in the array.
	int partSelect = 0;
	int debug = 0;
	
	
	//Read in the inventory.txt file.
	fileIORead(inventory);
	
	
	//Menu
	
	
	int choice = 0;
	cout<<	"\nStore Inventory Menu"<<endl;
	cout<<	"*********************************"<<endl;
	cout<<	"1. Print all parts"<<endl;
	cout<<	"2. Create a new part"<<endl;
	cout<<	"3. Modify a part"<<endl;
	cout<<	"4. Delete a part"<<endl;
	cout<<	"5. Print total"<<endl;
	cout<<	"6. Exit the program"<<endl;
	cout<<	"Please make a menu selection.";
	cin>>choice;
	
	
	while (choice !=6)
	{
		
	//Menu switch.
	switch (choice)
		{
			// The Print all parts case.
			case 1: 
				printAllParts(inventory);
				
				if(debug==1)
				{
					cout<<endl<<"Count number after printing is "<<inventory.getCount()<<endl;
				}
				break;
			
			// The 
			case 2: 
				cin.ignore();
				addPart(inventory);
				if(debug==1)
				{
					cout<<endl<<"Count number after addPart is "<<inventory.getCount()<<endl;
				}
				break;
			
			case 3:
				
				cout<<"Please select a part number to modify."<<endl;
				cin>>partSelect;
				modPart(inventory, partSelect-1);
				if(debug==1)
				{
					cout<<endl<<"Choice after modPart is "<<partSelect<<endl;
				}
				break;
				
			case 4:
				//Case for deleting an element.
				cout<<"Please select a part number to delete."<<endl;
				cin>>partSelect;
				inventory.deleteElement(partSelect-1);
							
				break;
				
			case 5:
				printCost(inventory);
							
				break;
				
			// This case sets the program into debug mode and will allow me to check code at certain intervals.
			// Not full proof, but helpful at times.
			case 117:
				debug = 1;
				cout<<endl<<"Entering debug mode."<<endl;
				
				//Debug to check what the value of count is after the file read. 
				//Can only enter debug mode after menu selection of 117, but if done first,
				//this can give the value of count from the file read.
				cout<<endl<<"Count number upon entering debug: "<<inventory.getCount()<<endl;
		
				break;

			default:
				cout<<"Invalid choice"<<endl;
		}
		
		//Debug for knowing when the menu loop restarts.
		if(debug==1)
		{
			cout<<endl<<"restarting menu loop last entry "<<choice<<endl;
		}
		
		//Menu re-loop.
		cin.clear();
		cout<<	"\nStore Inventory Menu"<<endl;
		cout<<	"*********************************"<<endl;
		cout<<	"1. Print all parts"<<endl;
		cout<<	"2. Create a new part"<<endl;
		cout<<	"3. Modify a part"<<endl;
		cout<<	"4. Delete a part"<<endl;
		cout<<	"5. Print total"<<endl;
		cout<<	"6. Exit the program"<<endl;
		cout<<	"Please make a menu selection.";
		cin>>choice;
		
	}
	

	
	
	// Save data to inventory.txt here
	if(inventory.getCount()!=0)
	{
		fileIOWrite(inventory);
	}	
	
	return 0;
}

//Function for printing all of the parts in inventory.
//Count should not be changed for this function.
void printAllParts(ArrayList inv)
{
	int count = inv.getCount();
	Part temp;
	if(count == 0)
	{
		cout<<"Empty Inventory."<<endl;
		return;
	}
	for(int i = 0; i < count; i++)
	{
		temp = inv.getElement(i);
		cout<<endl;
		cout	<<"Part Numbber: "	<<temp.getPartNum()+1		<<endl;
		cout	<<"Description: "	<<temp.getDescription()		<<endl;
		cout	<<"Quantity: "		<<temp.getQuantity()		<<endl;
		cout	<<"Unit Price: " 	<<temp.getUnitPrice()		<<endl;
	}
	
}

//Function for adding a Part to the array. 
//Count should be incremented by 1 after this function.
void addPart(ArrayList& inv)
{
	Part temp;
	
	cout<<"New part description: ";
	string desc;
	getline(cin, desc);
	
	cout<<"New part quantity: ";
	int quantity = 0;
	cin>>quantity;
	
	cout<<"New part unit price: ";
	float price = 0;
	cin>> price;
		
	temp.setPartNum(inv.getCount());
	temp.setDescription(desc);
	temp.setQuantity(quantity);
	temp.setUnitPrice(price);
	
	inv.addElement(temp);
		 
}
//Function for modifying a Part. 
//Count should not be changed for this function.
void modPart(ArrayList& inv, int select)
{
	int choice = 0;
	string desc;
	int quantity = 0;
	float price = 0;
	
	if(select == -1)
	{
		cout<<"Invalid part number."<<endl;
		return;
	}
	
	Part temp = inv.getElement(select);
	

	cout<<"Part that has been selected to modify: "<<temp.getDescription()<<endl;
	
	cout<<"Part Field modification Menu"<<endl;
	cout<<	"1. Edit Description."<<endl;
	cout<<	"2. Edit Quantity."<<endl;
	cout<<	"3. Edit Cost."<<endl;
	cout<<	"4. Exit menu."<<endl;
	cin>>choice;
	while (choice !=4)
	{
		switch (choice)
		{
			case 1:
					cout<<"New part description: ";
					cin.ignore();
					getline(cin, desc);
					temp.setDescription(desc); // Temp is an ArrayList Object.
					break;
			case 2:
					cout<<"New part quantity: ";
					cin>>quantity;
					temp.setQuantity(quantity);
					break;
			case 3:
					cout<<"New part unit price: ";
					cin>>price;
					temp.setUnitPrice(price);
					break;		
					
			default:
				cout<<"Invalid choice"<<endl;		
		}
		
		inv.setElement(select, temp);
		
		cin.clear();
		cout<<"Part Field modification Menu"<<endl;
		cout<<	"1. Edit Description."<<endl;
		cout<<	"2. Edit Quantity."<<endl;
		cout<<	"3. Edit Cost."<<endl;
		cout<<	"4. Exit menu."<<endl;
		cout<<endl<<"Please make a new menu selection.";
		cin.clear();
		cin>>choice;
		
		
		
	}
	
}
//Function for outputting the cost of the inventory.
//Count should not be changed for this function.
void printCost(ArrayList inv)
{
	int count = inv.getCount();
	
	Part temp;
	
	float inventoryCost = 0;
	for(int i=0; i < count; i++)
	{
		temp = inv.getElement(i);
		inventoryCost = inventoryCost + (temp.getQuantity()*temp.getUnitPrice());
	}
	cout<<endl<<"The cost of the total inventory is $"<< inventoryCost <<endl;
	
}

//Function for reading the "inventory.txt" file. 
//Function will not create an inventory if "inventory.txt" does not exist.
//Count will match the inventory.txt file maximum part number after this
//function or 100, whichever is higher. 
void fileIORead(ArrayList& inv)
{
	fstream file("inventory.txt", ios::in);
	
	int count = 0;
	
	Part temp;
	
	if(file)
	{
		int partNum = 0;
		string description = "";
		int quantity = 0;
		float unitPrice = 0;
		
		// using a loop to keep reading file.
		// if reading file fails, the loop will end
		while(file >> partNum && count<100)
		{
			count = inv.getCount();
			
			file.ignore();
			getline(file, description);
			file >> quantity;
			file >> unitPrice;	
			
			temp.setPartNum(count);
			temp.setDescription(description);
			temp.setQuantity(quantity);
			temp.setUnitPrice(unitPrice);
				
			inv.addElement(temp);
		}	
	}
	else
	{
		cout<<"No inventory file found. One will be created if a new inventory is created."<<endl;
	}
	
	// close file when done
	file.close();
}

//Function for writing the "inventory.txt" file.
//Function destroys old "inventory.txt" file.
//Count should not be changed for this function.
void fileIOWrite(ArrayList inv)
{	
	// create fstream object	
	fstream file("inventory.txt", ios::out);
	
	int count = inv.getCount();
	Part temp;
	
	// 	if file is good, then write to the file
	if(file)
	{	
		for(int i = 0; i< count; i++)
		{
			temp = inv.getElement(i);
			
			file << 	temp.getPartNum()		<<endl;
			file << 	temp.getDescription()	<<endl;
			file << 	temp.getQuantity()		<<endl; 
			file << 	temp.getUnitPrice() 	<<endl;	
		}
		
		
		cout<<"Writing file \"inventory.txt\" succeed."<<endl;

	}
	else
	{
		cout<<"Error when writing to file \"inventory.txt\""<<endl;
	}
	
	// close file when done.
	file.close();
}


