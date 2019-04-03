#ifndef ADDRESS_H
#define ADDRESS_H

#include <iostream>
using namespace std;
class address
{
	public:
		address();
		address(float, float, string, string);
		copyAddress();
		~address();
		
		//methods
		float getLatitude();
		float getLongitude();
		string getHouseNumber();
		string getStreetName();
		
		void setLatitude(float);
		void setLongitude(float);
		void setHouseNumber(int);
		void setStreetName(string);
		
		//print
		
		void print();
		
	private:
		float newLatitude;
		float newLongitude;
		string newHouseNumber;
		string newStreetName;
};

#endif
