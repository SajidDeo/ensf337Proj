//FILE: passenger.h
#ifndef PASSENGER_H
#define PASSENGER_H
#include "seat.h"


class Passenger {
	
public:

void set_seat(Seat input_seat);
//PROMISES: Takes an input of an object of class Seat then initializes private data member seat as input_seat. 

std::string get_f_name() const;
//PROMISES: Returns the first name of the passenger.

std::string get_l_name() const;
//PROMISES: Returns the last name of the passenger.

std::string get_phone() const;
//PROMISES: Returns the phone number of the passenger.

std::string get_ID() const;
//PROMISES: Returns the ID of the passenger.

void set_f_name(std::string input_f_name);
//PROMISES: Sets the first name of the passenger to input_f_name.

void set_l_name(std::string input_l_name);
//PROMISES: Sets the last name of the passenger to input_l_name.

void set_phone(std::string input_phone);
//PROMISES: Sets the phone number of the passenger to input_phone.

void set_ID (std::string input_ID);
//PROMISES: Sets the ID of the passenger to input_ID.

Seat get_seat() const;
//PROMISES: Returns an object seat that a passenger is occupying.

private:

Seat seat;
std::string f_name;
std::string l_name;
std::string phone;
std::string ID;

	
};
#endif
