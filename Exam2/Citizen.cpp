#include "Citizen.h"
#include <string>

using namespace std;

//Creates a new Citizen object with the passed in
//id, name, and favorite color
//Once a citizen is created, you can't change their id or name
//but you can change their favorite color
Citizen::Citizen(int id, string firstName, string lastName, string color) {
	_id = id;
	_firstName = firstName;
	_lastName = lastName;
	_color = color;
}

//Creates a new Citizen object by copying data from the
//passed in citizen
Citizen::Citizen(Citizen* citizen) {
	;//Citizen kane = citizen;
}

//Returns the first name of this citizen
string Citizen::getFirstName() {
	return _firstName;
}

//Returns the last name of this citizen
string Citizen::getLastName() {
	return _lastName;
}

//Returns the id for this citizen
int Citizen::getId() {
	return _id;
}

//Returns the favorite color for this citizen
string Citizen::getFavoriteColor() {
	return _color;
}

//Sets the favorite color for this citizen
void Citizen::setFavoriteColor(string color) {
	_color = color;
}

//setId, setFirstName, and setLastName should only be called when restoring a city from a file. No other time.
void Citizen::setId(int id) {
	_id = id;
}
void Citizen::setFirstName(string firstName) {
	_firstName = firstName;
}
void Citizen::setLastName(string lastName) {
	_lastName = lastName;
}