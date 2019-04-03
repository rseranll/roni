#include "address.h"

address::address()
{
	//constructor
}

address::address(float latitude, float longitude, string houseNumber, string streetName) {
	
	newLatitude = latitude;
	newLongitude = longitude;
	newHouseNumber = houseNumber;
	newStreetName = streetName;
}
address::copyAddress() {
	
	
}
address::~address()
{
}

float address::getLatitude() {
	
	return newLatitude;
}

float address::getLongitude() {
	
	return newLongitude;
}

string address::getHouseNumber() {
	
	return newHouseNumber;
}

string address::getStreetName() {
	
	return newStreetName;
}

void address::setLatitude(float latitude) {
	
	newLatitude = latitude;
}

void address::setLongitude (float longitude) {
	
	newLongitude = longitude;
}

void address::setHouseNumber(int houseNumber) {
	
	newHouseNumber = houseNumber;
}

void address::setStreetName(string streetName) {
	
	newStreetName = streetName;
}
		
void address::print() {
	
	cout << "Latitude: "  		<<newLatitude <<endl;
	cout << "longitude: " 		<<newLongitude <<endl;
	cout << "House number: " 	<<newHouseNumber << endl;
	cout << "Street: "    		<<newStreetName <<endl <<endl;
}
	
