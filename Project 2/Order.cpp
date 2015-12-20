/******************************************
* Project 2 Assignment					  *
* CS-3330 Data Structures and Algorithms  *
* Created by Brandon DeWeese			  *
*******************************************
*/

#include "stdafx.h"
#include "Order.h"

using namespace std;

Order::Order()
{
}

Order::Order(const Order &order)
{
	this->trackingID = order.trackingID;
	this->orderDate = order.orderDate;
	this->itemDescription = order.itemDescription;
	this->itemAmount = order.itemAmount;
	this->shippingAmount = order.shippingAmount;
	this->warehouseZipCode = order.warehouseZipCode;
	this->departureDate = order.departureDate;
	this->departureTime = order.departureTime;
	this->shipTo = order.shipTo;
	this->destinationAddress = order.destinationAddress;
	this->destinationZipCode = order.destinationZipCode;
	this->arrivalDate = order.arrivalDate;
	this->arrivalTime = order.arrivalTime;

}


Order::~Order(void)
{
	// Deconstructor, does nothing.
}

void Order::setrackingID(const string trackingID)
{
	this->trackingID = trackingID;
}

string Order::gettrackingID() const
{
	return trackingID;
}

void Order::setorderDate(const string orderDate)
{
	this->orderDate = orderDate;
}

string Order::getorderDate() const
{
	return orderDate;
}

void Order::setitemDescription(const string itemDescription)
{
	this->itemDescription = itemDescription;
}

string Order::getitemDescription() const
{
	return itemDescription;
}

void Order::setitemAmount(const double itemAmount)
{
	this->itemAmount = itemAmount;
}

double Order::getitemAmount() const
{
	return itemAmount;
}

void Order::setshippingAmount(const double shippingAmount)
{
	this->shippingAmount = shippingAmount;
}

double Order::getshippingAmount() const
{
	return shippingAmount;
}

void Order::setwarehouseZipCode(const int warehouseZipCode)
{
	this->warehouseZipCode = warehouseZipCode;
}

int Order::getwarehouseZipCode() const
{
	return warehouseZipCode;
}

void Order::setdepartureDate(const string departureDate)
{
	this->departureDate = departureDate;
}

string Order::getdepartureDate() const
{
	return departureDate;
}

void Order::setdepartureTime(const string departureTime)
{
	this->departureTime = departureTime;
}

string Order::getdepartureTime() const
{
	return departureTime;
}

void Order::setshipTo(const string shipTo)
{
	this->shipTo = shipTo;
}

string Order::getshipTo() const
{
	return shipTo;
}

void Order::setdestinationAddress(const string destinationAddress)
{
	this->destinationAddress = destinationAddress;
}

string Order::getdestinationAddress() const
{
	return destinationAddress;
}

void Order::setdestinationZipCode(const int destinationZipCode)
{
	this->destinationZipCode = destinationZipCode;
}

int Order::getdestinationZipCode() const
{
	return destinationZipCode;
}

void Order::setarrivalDate(const string arrivalDate)
{
	this->arrivalDate = arrivalDate;
}

string Order::getarrivalDate() const
{
	return arrivalDate;
}

void Order::setarrivalTime(const string arrivalTime)
{
	this->arrivalTime = arrivalTime;
}

string Order::getarrivalTime() const
{
	return arrivalTime;
}