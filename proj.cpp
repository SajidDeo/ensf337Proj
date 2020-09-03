//FILE: proj.cpp
 
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "seat.h"
#include "passenger.h"
#include "flight.h"
using std::string;
using std::vector;
using namespace std;

void displayHeader();
//PROMISES: Displays the header.

void pressEnter();
//PROMISES: Allows user to enter spacebar to continue.

int menu();
//PROMISES: Displays the menu for your selection. 

void getChoice();
//PROMISES: Gets user's input (1-6) from terminal. 
        
void displaySeats(Flight &f); 
//REQUIRES: Object f is not empty.At least one passenger, one row, one column. Must be less than 27 columns. There must be less than 100 rows. 
//PROMISES: Displays the seating arrangement

std::vector<int> numPassPerRow(Flight &f);
//REQUIRES: object f is not empty. At least one passenger, one row, one column. Must be less than 27 columns.
//PROMISES: Returns a vector that represents how many passengers are in each row.

void displayPassinfo(Flight &f);
//REQUIRES: object f is not empty. At least one passenger.
//PROMISES: Display's passenger's info on the terminal. 

void cleanStandardInputStream (void);
//PROMISES: Flushes the input stream when an incorrect input is entered.

int main ()
{
	Flight f;
	displayHeader();
	int choice;

		while((choice=menu()))
		{
			switch(choice)
			{
				case 1:
					cout <<"\n Choise 1 has been selected\n";
					cout << "\nAircraft Seat Map\n";
					displaySeats(f);
					pressEnter();
					break;
				case 2:
					cout << "\nChoise 2 has been selected\n";
					displayPassinfo(f);
					pressEnter();
					break;
				case 3:
					cout <<"\nChoise 3 has been selected\n";
					f.addPassenger();
					pressEnter();
					break;
				case 4:
					cout <<"\nChoise 4 has been selected\n";
					f.removePassenger();
					pressEnter();
					break;
				case 5:
					cout <<"\nChoise 5 has been selected\n";
					f.savePassdata();
					pressEnter();
					break;
				case 6:
					cout <<"\nChoise 6 has been selected \n";
					cout << "Now quitting!";
					exit(0);
			}
		}	
}


	
	
int menu()
{
	pressEnter();
	cout
   	 <<"\n Please select one of the following options:  \n"
	 << "\n[1]: Display Flight Seat Map"
	 << "\n[2]: Display Passengers Information"
	 << "\n[3]: Add a Passenger"
	 << "\n[4]: Remove an Existing Passenger"
	 << "\n[5]: Save Data"
	 << "\n[6]: Quit"
	 <<"\n";
	char choice;
	while(true) //Checks if input is valid.
	{
		cout <<  "\nEnter your choice:  (1, 2, 3, 4, 5 or 6)  ";
		cin >> choice;
		cleanStandardInputStream();

		if ((int)choice <49 || (int)choice > 54)
		{
			cout << " You entered an invalid input...";
		}
		
			else break;
	}	
	return (int)choice - 48;
	
}
	
void displayHeader()
{
	cout <<"\nVersion:  3.0\n";
	cout <<"\nTerm  Project - Flight Management Program in C++\n";
	cout << "\nProduced by: Sajid Hafiz\n";
}

void pressEnter()
{
	cout << "\n<< Press Return to Continue>>\n";
	cin.get();
}
	
void displaySeats(Flight& f)
{ 

std::vector <int> passrow  = numPassPerRow(f); //passrow will store how many passengers are on each row. 
	int row = f.get_row();
	int col = f.get_col();
	int numpass = f.get_numpass();
	cout <<"\n";
	cout<<"       ";
	
		for (int i = 0; i<col; i++)
		{
			cout << "  ";
			cout << (char)(i + 65);
			cout << "   ";

	    } //Creates the letters ontop of the grid. 
	
	cout <<"\n";
	cout<<"      ";
	for (int i =0; i<col; i++)
	cout << "+-----";
    cout<<"+";
    cout << "\n"; 
	
	int check_row; 
	
		if (row>10) check_row=10;

			else check_row=row;
		
		for (int k = 0; k<check_row; k++)	//Creates the rows from 0-9
		{ 
			cout<<k;
			cout<<"     |";
			int counter = 0; //Counts how many elements there are in a row. 
			int onepassrow = 0; //Value to check if there is one element (match) in any row. 
			int lastcolom1elem = 0; //Value to check if there is one element (match) in the last column of seating arrangement. 
				if (passrow[k] == 1) onepassrow = 1;

					for( int p = 0; p<col-onepassrow; p++)
					{ 
						int i = 0;
						int match = 0;

							while(i<numpass)
							{
				
								int sizestr =  (f.get_pdata(i).get_seat().get_label()).size();
								int seat = f.get_pdata(i).get_seat().get_label().at(sizestr-1) -65;
								int rownum =  stoi(f.get_pdata(i).get_seat().get_label());

									if ( (passrow[k] == 1 ) && (seat == col-1) && (k==rownum )&& (lastcolom1elem==0))
									{
										for (int i = 0; i<col-1;i++)
										cout<<"     |";
										cout<< "X";
										cout<<"    |";
										lastcolom1elem++;
									}
									
									if (( rownum == k) && ( seat == p) )
									{	
											cout<< "X";
											match = 1;
											cout<<"    |";
											counter++;

				
										if (counter == passrow[k] )
										{
											counter=0;
											i++;
											break;
										}
									}
									
								i++;
								
							}
							
							if( (match == 0|| passrow[k] == 1 ) && (lastcolom1elem==0) )
							{
									cout<<"     |";
							}

			
					}
			 
			cout<<"\n";
			cout<<"      +-----";
			
				for (int p = 0; p<col-1; p++)
				{
					cout<<"+-----";
				}
				
			cout<<"+";

			cout<<"\n";
		}
	
		if (row>10)
		{ 
				for (int k = 10; k<row; k++) //Creats rows from 10 to row
				{
					cout<<k;
					cout<<"    |";
					int counter = 0;
					int on = 0;
					int lastcolom1elem = 0;
						if (passrow[k] == 1) on = 1;
							for( int p = 0; p<col-on; p++)
							{ 
								int i = 0;
								int match = 0;
								
									while(i<numpass)
									{
										int sizestr =  (f.get_pdata(i).get_seat().get_label()).size();
										int seat = f.get_pdata(i).get_seat().get_label().at(sizestr-1) -65;
										int rownum =  stoi(f.get_pdata(i).get_seat().get_label());
										
										
										if ( (passrow[k] == 1 ) && (seat == col-1) && (k==rownum )&& (lastcolom1elem==0))
										{
											for (int i = 0; i<col-1;i++)
											cout<<"     |";
											cout<< "X";
											cout<<"    |";
											lastcolom1elem++;
										}
										
										
											if (( rownum == k) && (seat == p ) )
											{
												cout<< "X";
												match = 1;
												cout<<"    |";
												counter++;
												
													if (counter == passrow[k] )
													{
														counter=0;
														i++;
														break;
													}
											}
											
										i++;
									}

								if( (match == 0|| passrow[k] == 1 ) && (lastcolom1elem==0) )
								{
									cout<<"     |";
								}
					
							}
				
					cout<<"\n";
					cout<<"      +-----";
	
						for (int p = 0; p<col-1; p++)
						{
							cout<<"+-----";
						}
		
					cout<<"+";
					cout<<"\n";
				}
		}

}
	

std::vector<int> numPassPerRow (Flight& f)
{
	
	std::vector<int> passperrow(f.get_row());

	for(int i = 0; i<f.get_row();i++)
	{
		for (int j = 0; j<f.get_numpass();j++)
		{
			if(stoi(((f.get_pdata(j)).get_seat()).get_label()) == i)
				(passperrow[i])++;
		}
	}
	return passperrow;
}

void displayPassinfo(Flight &f)
{
cout << "\nFirst Name          Last Name             Phone                  Row  Seat             ID       \n";
cout << "\n---------------------------------------------------------------------------------------------------\n";

	for (int i = 0; i<f.get_numpass();i++)
	{

		int size =  (f.get_pdata(i).get_seat().get_label()).size(); 
                                                            
		cout << left
		<< setw(19) << f.get_pdata(i).get_f_name()
		<< setw(22) << f.get_pdata(i).get_l_name() 
		<< setw(25) << f.get_pdata(i).get_phone()
		<< setw(5)  << stoi(f.get_pdata(i).get_seat().get_label())
		<< setw(16) << f.get_pdata(i).get_seat().get_label().at(size-1)
	    << setw(16) << f.get_pdata(i).get_ID()
		<< "\n"
		<< "\n---------------------------------------------------------------------------------------------------\n";
		

	}
}	
	

void cleanStandardInputStream (void)
{
 int leftover;
 do {

 leftover = cin.get();

 } while (leftover !='\n' && leftover != EOF);

}












	