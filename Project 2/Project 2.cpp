/******************************************
* Project 2 Assignment					  *
* CS-3330 Data Structures and Algorithms  *
* Created by Brandon DeWeese			  *
*******************************************
*/

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <list>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#include "Order.h"

using namespace std;

void menu(); 
void displayOrders(); 
void enterOrder(); 
void deleteOrder(); 
void searchOrder(); 
void editOrder();

// Functions for trackingID
char getRandomChar();
char getRandomNum();
string getRandomString();

static const char num[] = "0123456789";
static const char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int stringLength = sizeof(alpha) - 1;

int numLength = sizeof(num) - 1;

// Functions for data file.
int loadFile();
void addFile(Order);


list <Order> orderList; //Declare the order list and an STL linked list variable.

int main () // The main function for our program.
{
	
	if (loadFile())
	{
		cerr << "Error: could not read from file!" << endl;
	}

	

	srand(time(0));

	menu();
	
	return 0;
}

// *********************
// Member Functions:   
// *********************

// Function to display the Menu.
void menu() 
{
	string userOption;
	bool exitProgram = false;

	while (!exitProgram)
	{
		// This section will allow the user to select options to add, delete, edit, and display orders.
		cout << endl << "\t***ORDER MENU***\n" << endl;
		cout << "1. Display Orders" << endl;
		cout << "2. Enter Order" << endl;
		cout << "3. Delete Order" << endl;
		cout << "4. Search Orders" << endl;
		cout << "5. Edit Order\n" << endl;
		cout << "6. Exit System" << endl << endl;

		cout << "Enter Option: ";
		getline(cin, userOption, '\n');

		switch (atoi(userOption.c_str())) // Process user entry
		{
		case 1:
			displayOrders();
			break;
		case 2:
			enterOrder();
			break;
		case 3:
			deleteOrder();
			break;
		case 4:
			searchOrder();
			break;
		case 5:
			editOrder();
			break;
		case 6:
			exitProgram = true;
			break;
		default:
			cerr << "Error: unknown option! Please enter 1-6." << endl;
			break;
		}


	}

	return;
}

// Function to display all orders in the linked list.
void displayOrders()
{
	cout << "** Displaying Orders**\n";

	list<Order>::iterator order;
	for (order = orderList.begin(); order != orderList.end(); ++order)
	{
		cout << "Tracking ID:\t" << order->gettrackingID() << endl;
		cout << "Order Date:\t\t" << order->getorderDate() << endl;
		cout << "Item Description:\t" << order->getitemDescription() << endl;
		cout << "Item Amount:\t\t" << order->getitemAmount() << endl;
		cout << "Shipping Amount:\t" << order->getshippingAmount() << endl;
		cout << "Warehouse Zip Code:\t" << order->getwarehouseZipCode() << endl;
		cout << "Departure Date:\t\t" << order->getdepartureDate() << endl;
		cout << "Shipping to:\t\t" << order->getshipTo() << endl;
		cout << "Destination Address:\t" << order->getdestinationAddress() << endl;
		cout << "Destination Zip Code:\t" << order->getdestinationZipCode() << endl;
		cout << "Arrival Date:\t\t" << order->getarrivalDate() << endl;
		cout << "Arrival Time:\t\t" << order->getarrivalTime() << endl << endl;
	}

	return;
}
// This function will create an order / add to the linked list.
void enterOrder()
{
	Order order;
	string userInput;
	double userInputDouble;
	int userInputInt;

	cout << endl << "**ADD AN ORDER**" << endl << endl;

	
	order.setrackingID(getRandomString());

	cout << "Order Date (mm/dd/yyyy): "; 
	getline(cin, userInput, '\n');
	
	while (userInput.length() !=  10)
	{
		cout << "Invalid format. Please Re-enter: ";
		getline(cin, userInput, '\n');
	}
	while (userInput.substr(2, 1) != "/" || userInput.substr(5, 1) != "/")
	{
		cout << "Invalid format. Please Re-enter: ";
		getline(cin, userInput, '\n');
	}
	while (isdigit(userInput[0]) == 0 || isdigit(userInput[1]) == 0 || isdigit(userInput[3]) == 0 || isdigit(userInput[4]) == 0
		   || isdigit(userInput[6]) == 0 || isdigit(userInput[7]) == 0 || isdigit(userInput[8]) == 0 || isdigit(userInput[9]) == 0)
	{
		cout << "Invalid format. Please Re-enter: ";
			getline(cin, userInput, '\n');
	}
	order.setorderDate(userInput);

	cout << "Item Description: ";
	getline(cin, userInput, '\n');
	order.setitemDescription(userInput);

	cout << "Item Amount: ";
	cin >> userInputDouble;             
	cin.ignore();
	order.setitemAmount(userInputDouble);

	cout << "Shipping Amount: ";
	cin >> userInputDouble;				
	cin.ignore();
	order.setshippingAmount(userInputDouble);

	cout << "Warehouse Zip Code: "; 
	cin >> userInputInt;		
	while (userInputInt < 10000 || userInputInt > 99999)
	{
		cout << "Please enter the correct zip code: ";
		cin >> userInputInt;
	}
	cin.ignore();
	order.setwarehouseZipCode(userInputInt);

	cout << "Departure Date (mm/dd/yyyy): "; 
	getline(cin, userInput, '\n');
	while (userInput.length() !=  10)
	{
		cout << "Invalid format. Please Re-enter: ";
		getline(cin, userInput, '\n');
	}
	while (userInput.substr(2, 1) != "/" || userInput.substr(5, 1) != "/")
	{
		cout << "Invalid format. Please Re-enter: ";
		getline(cin, userInput, '\n');
	}
	while (isdigit(userInput[0]) == 0 || isdigit(userInput[1]) == 0 || isdigit(userInput[3]) == 0 || isdigit(userInput[4]) == 0
		   || isdigit(userInput[6]) == 0 || isdigit(userInput[7]) == 0 || isdigit(userInput[8]) == 0 || isdigit(userInput[9]) == 0)
	{
		cout << "Invalid format. Please Re-enter: ";
			getline(cin, userInput, '\n');
	}
	order.setdepartureDate(userInput);

	cout << "Departure Time (hhmmss): "; 
	getline(cin, userInput, '\n');
	while (userInput.length() != 6)
	{
		cout << "Invalid format. Please Re-enter: ";
		getline(cin, userInput, '\n');
	}
	while (isdigit(userInput[0]) == 0 || isdigit(userInput[1]) == 0 || isdigit(userInput[2]) == 0 || isdigit(userInput[3]) == 0
			|| isdigit(userInput[4]) == 0 || isdigit(userInput[5]) == 0)
	{
		cout << "Invalid format. Please Re-enter: ";
		getline(cin, userInput, '\n');
	}
	order.setdepartureTime(userInput);

	cout << "Ship To: ";
	getline(cin, userInput, '\n');
	order.setshipTo(userInput);

	cout << "Destination Address: ";
	getline(cin, userInput, '\n');
	order.setdestinationAddress(userInput);

	cout << "Destination Zip Code: "; 
	cin >> userInputInt;			
	while (userInputInt < 10000 || userInputInt > 99999)
	{
		cout << "Please enter the correct zip code: ";
		cin >> userInputInt;
	}
	cin.ignore();
	order.setdestinationZipCode(userInputInt);

	cout << "Arrival Date (mm/dd/yyyy): "; 
	getline(cin, userInput, '\n');
	while (userInput.length() !=  10)
	{
		cout << "Invalid format. Please Re-enter: ";
		getline(cin, userInput, '\n');
	}
	while (userInput.substr(2, 1) != "/" || userInput.substr(5, 1) != "/")
	{
		cout << "Invalid format. Please Re-enter: ";
		getline(cin, userInput, '\n');
	}
	while (isdigit(userInput[0]) == 0 || isdigit(userInput[1]) == 0 || isdigit(userInput[3]) == 0 || isdigit(userInput[4]) == 0
		   || isdigit(userInput[6]) == 0 || isdigit(userInput[7]) == 0 || isdigit(userInput[8]) == 0 || isdigit(userInput[9]) == 0)
	{
		cout << "Invalid format. Please Re-enter: ";
			getline(cin, userInput, '\n');
	}
	order.setarrivalDate(userInput);

	cout << "Arrival Time (hhmmss): ";
	getline(cin, userInput, '\n');
	while (userInput.length() != 6)
	{
		cout << "Invalid format. Please Re-enter: ";
		getline(cin, userInput, '\n');
	}
	while (isdigit(userInput[0]) == 0 || isdigit(userInput[1]) == 0 || isdigit(userInput[2]) == 0 || isdigit(userInput[3]) == 0
			|| isdigit(userInput[4]) == 0 || isdigit(userInput[5]) == 0)
	{
		cout << "Invalid format. Please Re-enter: ";
		getline(cin, userInput, '\n');
	}
	order.setarrivalTime(userInput);

	// Add to the linked list.
	orderList.push_back(order); 

	addFile(order);

	return;
}

// Functino to delete an order from the list.
void deleteOrder()
{
	string tracker;
	bool foundEntry = false;

	cout << endl << "** DELETE AN ORDER **" << endl << endl;
	cout << "Tracking ID: ";

	getline(cin, tracker, '\n');

	list<Order>::iterator order;
	for (order = orderList.begin(); order != orderList.end(); ++order)
	{
		if (order->gettrackingID() == tracker)
		{
			foundEntry = true;
			orderList.erase(order);
			break;
		}
	}

	if (foundEntry)
		cout << "Entry deleted." << endl;
	else
		cout << "Entry not found." << endl;


	return;
}

// Function to search for an order in the list.
void searchOrder()
{
	string tracker;
	bool foundEntry = false;

	cout << endl << "** SEARCH AN ORDER **" << endl << endl;
	cout << "Tracking ID: ";

	getline(cin, tracker, '\n');

	list<Order>::iterator order;
	for (order = orderList.begin(); order != orderList.end(); ++order)
	{
		if (order->gettrackingID() == tracker)
		{
			foundEntry = true;
			break;
		}
	}
	if (foundEntry)
		{
			cout << "Tracking ID:\t" << order->gettrackingID() << endl;
			cout << "Order Date:\t\t" << order->getorderDate() << endl;
			cout << "Item Description:\t" << order->getitemDescription() << endl;
			cout << "Item Amount:\t\t" << order->getitemAmount() << endl;
			cout << "Shipping Amount:\t" << order->getshippingAmount() << endl;
			cout << "Warehouse Zip Code:\t" << order->getwarehouseZipCode() << endl;
			cout << "Departure Date:\t\t" << order->getdepartureDate() << endl;
			cout << "Shipping to:\t\t" << order->getshipTo() << endl;
			cout << "Destination Address:\t" << order->getdestinationAddress() << endl;
			cout << "Destination Zip Code:\t" << order->getdestinationZipCode() << endl;
			cout << "Arrival Date:\t\t" << order->getarrivalDate() << endl;
			cout << "Arrival Time:\t\t" << order->getarrivalTime() << endl << endl;
		}
	else
		cout << "Entry not found.\n";


	return;
}

// Function to edit an order in the list.
void editOrder()
{
	Order order;
	string userInput;
	double userInputDouble;
	int userInputInt;
	string tracker;
	bool foundEntry = false;

	cout << endl << "** EDIT AN ORDER **" << endl << endl;
	cout << "Tracking ID: ";

	getline(cin, tracker, '\n');

	list<Order>::iterator ordeR;
	for (ordeR = orderList.begin(); ordeR != orderList.end(); ++ordeR)
	{
		if (ordeR->gettrackingID() == tracker)
		{
			foundEntry = true;
			orderList.erase(ordeR);
			break;
		}
	}

	if (foundEntry)
	{
		order.setrackingID(tracker);

		cout << "Order Date (mm/dd/yyyy): "; 
		getline(cin, userInput, '\n');
		while (userInput.length() !=  10)
		{
			cout << "Invalid format. Please Re-enter: ";
			getline(cin, userInput, '\n');
		}
		while (userInput.substr(2, 1) != "/" || userInput.substr(5, 1) != "/")
		{
			cout << "Invalid format. Please Re-enter: ";
			getline(cin, userInput, '\n');
		}
		while (isdigit(userInput[0]) == 0 || isdigit(userInput[1]) == 0 || isdigit(userInput[3]) == 0 || isdigit(userInput[4]) == 0
			   || isdigit(userInput[6]) == 0 || isdigit(userInput[7]) == 0 || isdigit(userInput[8]) == 0 || isdigit(userInput[9]) == 0)
		{
			cout << "Invalid format. Please Re-enter: ";
			getline(cin, userInput, '\n');
		}
		order.setorderDate(userInput);

		cout << "Item Description: ";
		getline(cin, userInput, '\n');
		order.setitemDescription(userInput);

		cout << "Item Amount: ";
		cin >> userInputDouble;             
		cin.ignore();
		order.setitemAmount(userInputDouble);

		cout << "Shipping Amount: ";
		cin >> userInputDouble;				
		cin.ignore();
		order.setshippingAmount(userInputDouble);

		cout << "Warehouse Zip Code: "; 
		cin >> userInputInt;				
		while (userInputInt < 10000 || userInputInt > 99999)
		{
			cout << "Please enter the correct zip code: ";
			cin >> userInputInt;
		}
		cin.ignore();
		order.setwarehouseZipCode(userInputInt);

		cout << "Departure Date (mm/dd/yyyy): "; 
		getline(cin, userInput, '\n');
		while (userInput.length() !=  10)
		{
			cout << "Invalid format. Please Re-enter: ";
			getline(cin, userInput, '\n');
		}
		while (userInput.substr(2, 1) != "/" || userInput.substr(5, 1) != "/")
		{
			cout << "Invalid format. Please Re-enter: ";
			getline(cin, userInput, '\n');
		}
		while (isdigit(userInput[0]) == 0 || isdigit(userInput[1]) == 0 || isdigit(userInput[3]) == 0 || isdigit(userInput[4]) == 0
			   || isdigit(userInput[6]) == 0 || isdigit(userInput[7]) == 0 || isdigit(userInput[8]) == 0 || isdigit(userInput[9]) == 0)
		{
			cout << "Invalid format. Please Re-enter: ";
			getline(cin, userInput, '\n');
		}
		order.setdepartureDate(userInput);

		cout << "Departure Time (hhmmss): ";
		getline(cin, userInput, '\n');
		while (userInput.length() != 6)
		{
			cout << "Invalid format. Please Re-enter: ";
			getline(cin, userInput, '\n');
		}
		while (isdigit(userInput[0]) == 0 || isdigit(userInput[1]) == 0 || isdigit(userInput[2]) == 0 || isdigit(userInput[3]) == 0
			|| isdigit(userInput[4]) == 0 || isdigit(userInput[5]) == 0)
		{
			cout << "Invalid format. Please Re-enter: ";
			getline(cin, userInput, '\n');
		}
		order.setdepartureTime(userInput);

		cout << "Ship To: ";
		getline(cin, userInput, '\n');
		order.setshipTo(userInput);

		cout << "Destination Address: ";
		getline(cin, userInput, '\n');
		order.setdestinationAddress(userInput);

		cout << "Destination Zip Code: "; 
		cin >> userInputInt;			
		while (userInputInt < 10000 || userInputInt > 99999)
		{
			cout << "Please enter the correct zip code: ";
			cin >> userInputInt;
		}
		cin.ignore();
		order.setdestinationZipCode(userInputInt);

		cout << "Arrival Date (mm/dd/yyyy): "; 
		getline(cin, userInput, '\n');
		while (userInput.length() !=  10)
		{
			cout << "Invalid format. Please Re-enter: ";
			getline(cin, userInput, '\n');
		}
		while (userInput.substr(2, 1) != "/" || userInput.substr(5, 1) != "/")
		{
			cout << "Invalid format. Please Re-enter: ";
			getline(cin, userInput, '\n');
		}
		while (isdigit(userInput[0]) == 0 || isdigit(userInput[1]) == 0 || isdigit(userInput[3]) == 0 || isdigit(userInput[4]) == 0
			   || isdigit(userInput[6]) == 0 || isdigit(userInput[7]) == 0 || isdigit(userInput[8]) == 0 || isdigit(userInput[9]) == 0)
		{
			cout << "Invalid format. Please Re-enter: ";
			getline(cin, userInput, '\n');
		}
		order.setarrivalDate(userInput);

		cout << "Arrival Time (hhmmss): "; 
		getline(cin, userInput, '\n');
		while (userInput.length() != 6)
		{
			cout << "Invalid format. Please Re-enter: ";
			getline(cin, userInput, '\n');
		}
		while (isdigit(userInput[0]) == 0 || isdigit(userInput[1]) == 0 || isdigit(userInput[2]) == 0 || isdigit(userInput[3]) == 0
			|| isdigit(userInput[4]) == 0 || isdigit(userInput[5]) == 0)
		{
			cout << "Invalid format. Please Re-enter: ";
			getline(cin, userInput, '\n');
		}
		
		order.setarrivalTime(userInput);

		// Add to the linked list.
		orderList.push_back(order);
	}
	else
		cout << "Entry not found.\n";

	return;
}

char getRandomChar()
{
	return alpha[rand() % stringLength];
}

char getRandomNum()
{
	return num[rand() % numLength];
}

string getRandomString()
{
	string randomString;

	for (int i = 0; i < 3; i++)
	{
		randomString += getRandomChar();
	}

	for (int i = 0 ; i < 3; i++)
	{
		randomString += getRandomNum();
	}

	for (int i = 0; i < 2; i++)
	{
		randomString += getRandomChar();
	}
	
	return randomString;
}

/*Having some trouble with the loadfile(). When starting the program and there is already a file
with information in it, it is correctly loading it into the list however it will load another list 
thats not there with 0's where there are double/int variables. 
*/
int loadFile()	
{					
	fstream dataFile;
	string data;
	Order order;
	double ddata;
	int idata;
	
	
	dataFile.open("tracker.dat", ios_base::in);

	if (!dataFile)
	{
		// Return an error code if we can't open the file.
		return -1;
	}

	dataFile.clear();

	while (!dataFile.eof())
	{
		getline(dataFile, data);
		order.setrackingID(data);

		getline(dataFile, data);
		order.setorderDate(data);

		getline(dataFile, data);
		order.setitemDescription(data);

		getline(dataFile, data);
		ddata = atof(data.c_str());
		order.setitemAmount(ddata); 
		

		getline(dataFile, data);
		ddata = atof(data.c_str());
		order.setshippingAmount(ddata); 
		

		getline(dataFile, data);
		idata = atof(data.c_str());
		order.setwarehouseZipCode(idata); 
		
		getline(dataFile, data);
		order.setdepartureDate(data); 

		getline(dataFile, data);
		order.setshipTo(data); 

		getline(dataFile, data);
		order.setdestinationAddress(data); 

		getline(dataFile, data);
		idata = atof(data.c_str());
		order.setdestinationZipCode(idata); 
		
		getline(dataFile, data);
		order.setarrivalDate(data); 

		getline(dataFile, data);
		order.setarrivalTime(data); 

		orderList.push_back(order);
		
	}

	dataFile.close();

	return 0;
}

void addFile(Order)
{

	fstream dataFile;
	dataFile.open("tracker.dat", ios::out);

	list<Order>::iterator order;
	for (order = orderList.begin(); order != orderList.end(); ++order)
	{
		dataFile << order->gettrackingID() << endl;
		dataFile << order->getorderDate() << endl;
		dataFile << order->getitemDescription() << endl;
		dataFile << order->getitemAmount() << endl;
		dataFile << order->getshippingAmount() << endl;
		dataFile << order->getwarehouseZipCode() << endl;
		dataFile << order->getdepartureDate() << endl;
		dataFile << order->getshipTo() << endl;
		dataFile << order->getdestinationAddress() << endl;
		dataFile << order->getdestinationZipCode() << endl;
		dataFile << order->getarrivalDate() << endl;
		dataFile << order->getarrivalTime() << endl << endl;
	}

	dataFile.close();

	return;
}