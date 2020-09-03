//FILE: flight.cpp
#include  <ctype.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <string>
#include <fstream>
#include "flight.h"

void cleanStandardInputStream1(void);


Flight::Flight()
{
	std::string fileName; 
	std::cout << "Enter the full name of your text file including the type of file it is for ex:  passengers.txt   :  ";
	std::cin >> fileName;
	std::ifstream instream;
	instream.open(fileName,std::ios::in); //Opens file
	int i = 0;
	
	
	while (instream.fail())
	{
        i++;
        if (i > 3)
		{
			std::cout << "File Was Not Found. Exiting\n";
			exit(1);
        }
		
        std::cout << "File Not Found. Please enter a valid file address\n";
        std::cin >> fileName;
        instream.open(fileName);
        if (!instream.fail())
		{
            instream.clear();
        }
    }
		
	getline(instream,aircraft,' '); //sets aircraft
	instream >> row >> col; //Sets row,col
	std::string line;
	std::string start;
	int count=0;
	
	while(getline(instream,line))
	{
		count++;
	}
	numpass = count - 1; //Sets the number of passengers.
	
	pdata = std::vector<Passenger> (numpass);
	
	instream.clear(); //Clears flags.
	instream.seekg(0, std::ios::beg); //instream now is at the beginning.
	getline(instream,line); //Points to the 1st line of passenger data
	Seat temp;
	
	for (int i = 0; i<numpass; i++) 
	{
			pdata[i].set_seat(temp);
	}
		
	for (i=0;i<numpass;i++) //Fills in pdata
	{
		instream >> line;
		pdata[i].set_f_name(line);
				
		instream >> line;
		pdata[i].set_l_name(line);
		
		instream >> line;
		pdata[i].set_phone(line);
		
		instream >> line;
		temp = pdata[i].get_seat();
		temp.set_label(line);
		pdata[i].set_seat(temp);
		
		instream >> line;
		pdata[i].set_ID(line);
		
	}
	
	instream.close(); //Closes file	
}

void Flight::addPassenger()
{
    std::string id,fname,lname,phone, seat, label;
	int rowwant;
	
	while (true) //Checks if input ID is a valid integer number.
	{
		int error = 0;
		std::cout << "\n Please enter the passenger id:  ";
		std::cin >> id;
		for(unsigned i = 0; i<id.size();i++) 
		{
			if(id.at(i) <'0' || id.at(i)>'9')
			{
				std::cout <<"\n An incorrect input has been entered.";
				cleanStandardInputStream1();
				error=1;
			}
		}
		if (error == 0) break;
	}		
	
	
	std::cout << "\n Please enter the passenger first name:  ";
	std::cin >> fname;
	std::cout << "\n Please enter the passenger last name:  ";
	std::cin >> lname;
	
	while (true) //Checks if you have a valid phone-number. 
	{	int error = 0;
		std::cout << "\n Please enter the passenger phone number for example 403-123-4567   :   ";
		std::cin >> phone;
		if ( phone.size()!= 12  || phone.at(7) != '-'  || phone.at(3)!= '-')
		{	std::cout <<"\n";
			std::cout << "You have entered an invalid phone number. \n";
			cleanStandardInputStream1();
		}
		
		else 
		{
			for (int i = 0;i<12;i++) 
			{
				if (i!= 7 && i!=3)
				{
					if(phone.at(i) <'0' || (int)phone.at(i) >'9')
					{
						std::cout <<"\n";
						std::cout << "You have entered an invalid phone number. \n";
						error = 1;
						cleanStandardInputStream1();
					}
				}
				
			}
			if (error == 0) break;
		}
	}
	
    std::cout <<"\n";
    std::cout <<"\n";
	
	while (true) //Checking for valid input
	{
		int match = 0;
	
		bool valid = false;
		
		while(!valid) //Checks if row is a valid integer. If not, asks you to re-enter.
		{
			std::cout << "\n Enter the passenger's desired row :  ";
			std::cin >> rowwant;
		
			if (std::cin.fail())
			{
				std::cout << "\nInvalid input please re-enter:  ";
				std::cin.clear();
				cleanStandardInputStream1();
			}
				else
				{
					valid=true;
				}
		}
			
		std::cout << "\n Enter the passenger's desired seat:  ";
		std::cin >> seat;
		label = std::to_string(rowwant) + seat;    
		
		if (rowwant > row-1 || seat.at(0) -65 > col-1 || rowwant<0 || seat.at(0)-65<0 )
		{
			std::cout << "\n Either your row or seat is invalid. Re-enter your inputs."; 
			match = 1;
			
		}
		
			else
			{
			
				for (int i = 0; i<numpass; i++)
				{
					if (pdata[i].get_seat().get_label() == label)  
					{
						std::cout <<"That seat is already taken...";
						match = 1;
					}
			
				}
				
				if (match == 0 ) break;
			}
	}
		
	numpass+=1; 
	pdata.resize(numpass+1);
	Seat temp;
	temp.set_label(label);
	pdata[numpass-1].set_seat(temp);      //The following lines defines the new passenger data element
    pdata[numpass-1].set_f_name(fname);
    pdata[numpass-1].set_l_name(lname);
    pdata[numpass-1].set_phone(phone);
    pdata[numpass-1].set_ID(id);

}

void Flight::removePassenger() 
{
	int indexmatch = 0; //stores the index of the matching ID's. In the case there is no matching ID's it represents the number of passengers.
	
	int ID;

	while(true) //This portion of the code checks if the input is valid (an int) as well as if there is a match for the input. 
	{
		bool valid = false;
			while(!valid) 
			{
				std::cout << "\n Please enter the ID of the passenger that needs to be removed:  ";
				std::cin >> ID;
					if (std::cin.fail())
					{
						std::cout << "\nInvalid input please re-enter:  ";
						std::cin.clear();
						cleanStandardInputStream1();
					}
						else
						{
							valid=true;
						}
			}
	
			for (int i = 0; i<numpass; i++)  //Checks if there is a match, if there isn't asks you to re-enter.
			{
				if(stoi(pdata[i].get_ID()) != ID)
				{
					indexmatch++;

				}
				else break;
			}
		
			if (indexmatch == numpass  )
			{
				std::cout << "\n No match was found for the entered ID.  Please re-enter    ";
				cleanStandardInputStream1();
			}
				
				else break;
				
	}
	
							
	pdata.erase(pdata.begin()+indexmatch); //Erase deletes the element in pdata at index c then shifts all elements to the left one space.
    numpass-=1;
	pdata.resize(numpass);
}

void Flight::savePassdata()
{
	std::cout << "\nDo you want to save data in the flight_info.txt? Please answer <Y or N>:   ";
	std::string response;
	std::cin >> response;
	
	std::ofstream out_stream;
		if (response  != "Y" && response !="y") std::cout <<"Returning you to main menu...";
		
			else 
			{
				out_stream.open("flight_info.txt");
				
					if (out_stream.fail()) 
						{
							std::cout << "Error opening file...Will now exit\n";
							exit(0);
						}
						
				std::cout<<"\n Now saving your file...\n";
				out_stream << aircraft <<" " << row << " " << col << "\n";
				
					for(int i = 0; i<numpass; i++)
					{
						 out_stream << std::left << std::setw(16) << pdata[i].get_f_name() << std::setw(16) << pdata[i].get_l_name() << std::setw(15)  << pdata[i].get_phone() << std::setw(10) 
						<< pdata[i].get_seat().get_label() << " " << pdata[i].get_ID() << "\n";
					}
	
			}
	out_stream.close();
	
}


int Flight::get_row() const
{
	return row;
}
int Flight::get_col() const
{
	return col;
}
std::string Flight::get_aircraft() const
{
	return aircraft;
}

int Flight::get_numpass() const
{
	return numpass;
}


Passenger Flight::get_pdata(int index)const
{
	return pdata[index];
}

void Flight::set_numpass(int input_numpass)
{
	numpass = input_numpass;
}

std::vector<Passenger> Flight::get_pdata() const
{
	return pdata;
}


void cleanStandardInputStream1 (void)
{
 int leftover;
 do {

 leftover = std::cin.get();

 } while (leftover !='\n' && leftover != EOF);

}
