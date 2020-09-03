//FILE: passenger.cpp
#include <string>
#include <vector>
#include "passenger.h"


void Passenger::set_f_name(std::string input_f_name)
{
	f_name = input_f_name;
}

std::string Passenger::get_f_name() const
{
	return f_name;
}


std::string Passenger::get_l_name() const
{
	return l_name;
}

std::string Passenger::get_phone() const
{
	return phone;
}

std::string Passenger::get_ID() const
{
	return ID;
}

void Passenger::set_l_name(std::string input_l_name)
{
	l_name = input_l_name;
}

void Passenger::set_phone(std::string input_phone)
{
	phone = input_phone;
}

void Passenger::set_ID (std::string input_ID)
{
	ID = input_ID;
}

Seat Passenger::get_seat() const
{
	return seat;
}

void Passenger::set_seat(Seat input_seat)
{
	seat = input_seat;
	
}