//FILE: seat.cpp
#include <string>
#include <vector>
#include "seat.h"


void Seat::set_label(std::string input_label)
{
	label = input_label;
}

std::string Seat::get_label() const
{
	return label;
}

Seat::Seat()
{
	
	label ="0A";
}