#include <iostream>
#include <fstream>
#include <vector>
#include "address.h"
using namespace std;

//function to open and upload the data from the file
void addressVector (vector <address> & myCity) {
	
	ifstream din;
	float latitude, longitude;
	string houseNumber;
	string streetName, rmv;
	
	din.open("input.rc");
	
		if (!din) {
			cerr << "Error opening file" <<endl;
			exit(1);
		}
		
	
		//while the end of the file isn't reached, keep uploading.
		while (!din.eof()) {
		
			din >> latitude >> longitude;
			din >> houseNumber;
		
				for (int i = 0; i = 3 - houseNumber.size(); i++){
			
					houseNumber = "0" + houseNumber; 
				}
			getline(din, streetName);
		
			streetName.erase(0, 1);

			address newAddress(latitude, longitude, houseNumber, streetName); 
			myCity.push_back(newAddress);

		}	

din.close();
}
		

//binary search using the vector created from the file (function above)
int binarySearch(vector <address> myCity, int start, int end, string name) {

	int mid;
	mid = (end + start ) / 2;
	
	string fullAddress;
	fullAddress = myCity[mid].getStreetName() + " " + myCity[mid].getHouseNumber();
	
	//for loop to lowercase everything, so there is error checking
	for (int i = 0; i < fullAddress.size()-1; i++ ) {
	
		fullAddress[i] = tolower(fullAddress[i]);
	}
	
	//if the user looks up an address that doesn't exist in the file
	if (end < start ) {
	
		cout << "We found the nearby addresses: ";
		myCity[mid].print();
		myCity[mid+1].print();
		return -1; 
	}
	
	//base case of the recursion 
	if (name == fullAddress) {
		
		cout << "We found the address below: \n";
		myCity[mid].print();
		return mid;
	}
	
	//recursion occurs if not found until base reached
 	if (name > fullAddress) {

		return binarySearch(myCity, mid + 1, end, name);
	}

	else if (name < fullAddress) { 

		return binarySearch(myCity, start, mid -1, name);
	}

}

	

int main () {

	vector <address> myCity;
	addressVector(myCity);
	
	string runAgain = "Y";
	while (( runAgain == "y" )|| (runAgain == "Y")){
	
		string houseNumber; 
		string rmv, streetName;
		cout << "Welcome to GIS PF2\n";
		cout << "\nPlease, enter the building number: ";
		getline(cin, houseNumber);
		
		while (houseNumber.size() > 3){
 			cin.clear()	;
 			cout <<"Your house number should be 3 or less digits: ";
 			getline(cin, houseNumber);
 			cout << endl;
 		}
			//since I am inputing the house number as a string, I am adding extra zeros at the beginning of the number, to set them equal
			for (int i = 0; i = 3 - houseNumber.size(); i++) 
				houseNumber = "0" + houseNumber; 
			
		cout << "\nPlease, enter the street name: ";
		getline(cin, streetName);
		//combining the street name and house number.
		streetName = streetName + " " + houseNumber;
	
			for (int i = 0; i < streetName.size()-1; i++)
				streetName[i] = tolower(streetName[i]);
	
	int number;
	number =  binarySearch(myCity, 0 , myCity.size() - 1, streetName);

	cout << "Would you like to look up another address? Press Y to continue: ";
	getline(cin, runAgain);
	
}

	cout <<"\nThank you for using GIS PF2!\n";
return 0;
}


