//FILE: flight.h

#ifndef FLIGHT_H
#define FLIGHT_H
#include "passenger.h"


class Flight
{
	
	public:
	
	Flight();
	//REQUIRES: The file that holds the Flight and passenger data must be "properly formatted" and logical. 
	//PROMISES: Initializes an object of class Flight from the data inside a file. 
	
	void savePassdata();
	//PROMISES: Saves the passenger data into a text file.
	
	int get_row() const;
	//PROMISES: Returns the number of rows in the aircraft.
	
	int get_col() const;
	//PROMISES: Returns the number of columns in the aircraft.
	
	std::string get_aircraft() const;
	//PROMISES: Returns the aircraft identifier.
	
	int get_numpass() const;
	//PROMISES: Returns the number of passengers on the flight.
	
	void set_numpass(int input_numpass);
	//PROMISES: Sets the number of passengers on the flight to input_numpass.
	
	void addPassenger();
	//PROMISES: Records user's inputs of ID, Seating arrangement, first name, last name as well as phone number and adds it to the pdata vector increasing the
	//          number of passengers byo ne.
	
	void removePassenger();
	//REQUIRES: At least one or more passengers are on the flight (one element of pdata must be initialized)
	//PROMISES: Asks user which passenger to remove and removes the passenger / deletes the information of passenger on pdata from the passenger's ID 
	//          and shifts elements to the left as well as resizing the vector to it's previous size minus one. 
	
	Passenger get_pdata(int index) const;
	//PROMISES: Returns the passenger data in pdata at index i.
	
	std::vector<Passenger> get_pdata() const;
	//PROMISES: Returns the vector pdata
	
	private:
	
	std::string aircraft;
	int row;
	int col;
	std::vector<Passenger>pdata;
	int numpass;

	
};
#endif