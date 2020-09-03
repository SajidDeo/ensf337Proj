//FILE: seat.h
#ifndef SEAT_H
#define SEAT_H

class Seat
{
	public:
	
	std::string get_label() const;
	//PROMISES: Returns the row number as well as the seat of the passenger.
	
	void set_label(std::string input_label);
	//PROMISES: Sets the label of the seat (row number and seat) to input_label.
	
	Seat();
	//PROMISES: Is the default constructor for seat. Initializes it to:0A
	
	private:
	
	std::string label;
	};
	
#endif