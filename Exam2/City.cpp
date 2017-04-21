#include "City.h"
#include "Citizen.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;


//Creates a new city with the given name
//When the city is created you need to restore
//it's population from a file.
//Hint: You will want to make the file name
//be based on the name of the city.
City::City(string cityName) {
	_cityName = cityName;
	_populationSize = 0;
	fstream iofile(_cityName + ".txt", ios::in);
	for (int i = 0; !iofile.fail(); _populationSize++) {
		string tempID, tempFirstName, tempLastName, tempColor;
		iofile >> tempID >> tempFirstName >> tempLastName >> tempColor;

		myCitizens[_populationSize].setFirstName(tempFirstName);
		myCitizens[_populationSize].setLastName(tempLastName);
		myCitizens[_populationSize].setFavoriteColor(tempColor);
	}
	iofile.close();
}

//This is the destructor for the city.  When
//this city is destroyed, save the population of
//the city to a file so that you can restore
//it in the constructor the next time that
//a city with this name is created.
City :: ~City() {
	ofstream iofile(_cityName + ".txt", ios::app);
	for (int i = 1; i < _populationSize; i++) {
		iofile << i << " " << myCitizens[i].Citizen::getFirstName() << " " << myCitizens[i].Citizen::getLastName() << " " << myCitizens[i].Citizen::getFavoriteColor() << endl;
	}
	iofile.close();
}

//Returns the city name
string City::getCityName() {
	return _cityName;
}

//Returns the number of citizens in this city
int City::populationSize() { 
	return _populationSize; 
}

//Returns the citizen at the given index.
Citizen* City::getCitizenAtIndex(int index) { 
	return &City::myCitizens[index];
}

//Adds a citizen to this city. You will need to
//make a copy of this citizen so that you make
//sure to keep it around for the life of the city.
void City::addCitizen(Citizen* citizen) {
	myCitizens.push_back(citizen);
	_populationSize++;
}

//Returns the citizen with the given id.
Citizen* City::getCitizenWithId(int id) {
	for (int i = 0; i < _populationSize; i++) {
		if (City::myCitizens[i].getId() == id) {
			return &City::myCitizens[i];
		}
	}
	return NULL;
}

//Returns a vector of citizens that all have
//the given color as their favorite color.
//For example, if color is “Blue” this will return all citizens
//for this city who’s favorite color is Blue.
vector<Citizen*> City::getCitizensForFavoriteColor(string color) {
	vector<Citizen*> sameColor;
	for (int i = 0; i < _populationSize; i++) {
		if (City::myCitizens[i].getFavoriteColor() == color) {
			sameColor.push_back(&myCitizens[i]);
		}
	}
	return sameColor;
}