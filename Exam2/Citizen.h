#ifndef _Citizen_H
#define _Citizen_H

#include <string>
using namespace std;

class Citizen
{
private:
	int _id;
	string _firstName;
	string _lastName;
	string _color;

public:

	//Creates a new Citizen object with the passed in
	//id, name, and favorite color
	//Once a citizen is created, you can't change their id or name
	//but you can change their favorite color
	Citizen(int id, string firstName, string lastName, string color);

	//Creates a new Citizen object by copying data from the
	//passed in citizen
	Citizen(Citizen* citizen);

	//Returns the first name of this citizen
	string getFirstName();

	//Returns the last name of this citizen
	string getLastName();

	//Returns the id for this citizen
	int getId();

	//Returns the favorite color for this citizen
	string getFavoriteColor();

	//Sets the favorite color for this citizen
	void setFavoriteColor(string color);

	//setId, setFirstName, and setLastName should only be called when restoring a city from a file. No other time.
	void setId(int id);
	void setFirstName(string firstName);
	void setLastName(string lastName);
};

#endif