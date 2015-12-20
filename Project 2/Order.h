/******************************************
* Project 2 Assignment					  *
* CS-3330 Data Structures and Algorithms  *
* Created by Brandon DeWeese			  *
*******************************************
*/

#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <string>

using namespace std;

class Order
{
public:
	Order();
	Order(const Order &order);
	~Order();

	void setrackingID(const string trackingID);
	string gettrackingID() const;

	void setorderDate(const string orderDate);
	string getorderDate() const;

	void setitemDescription(const string itemDescription);
	string getitemDescription() const;

	void setitemAmount(const double itemAmount);
	double getitemAmount() const;

	void setshippingAmount(const double shippingAmount);
	double getshippingAmount() const;

	void setwarehouseZipCode(const int warehouseZipCode);
	int getwarehouseZipCode() const;

	void setdepartureDate(const string departureDate);
	string getdepartureDate() const;

	void setdepartureTime(const string departureTime);
	string getdepartureTime() const;

	void setshipTo(const string shipTo);
	string getshipTo() const;

	void setdestinationAddress(const string destinationAddress);
	string getdestinationAddress() const;

	void setdestinationZipCode(const int destinationZipCode);
	int getdestinationZipCode() const;

	void setarrivalDate(const string arrivalDate);
	string getarrivalDate() const;

	void setarrivalTime(const string arrivalTime);
	string getarrivalTime() const;
		
private:
	string trackingID;
	string orderDate;
	string itemDescription;
	double itemAmount;
	double shippingAmount;
	int warehouseZipCode;
	string departureDate;
	string departureTime;
	string shipTo;
	string destinationAddress;
	int destinationZipCode;
	string arrivalDate;
	string arrivalTime;


};

#endif