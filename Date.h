#ifndef __DATE_H
#define __DATE_H

#pragma warning (disable:4996)
#include <iostream>
#include <string.h>
using namespace std;
class Date
{
	public:
		friend class Feedback; 
		friend class Customer;
		Date(unsigned int* day , unsigned int* month , unsigned int *year );
		Date(const Date&);
		Date(Date&&);
		~Date();

		// Month and year passed for validation check
		bool setDay(unsigned int * day, unsigned int * month, unsigned int * year); 
		bool setMonth(unsigned int * month);
		bool setYear(unsigned int * year);

		inline unsigned int * getDay()										  const  
			{ return this->day; };
		inline unsigned int * getMonth()									  const 
			{ return this->month; };
		inline unsigned int * getYear()										  const 
			{ return this->year; };

		// Validation functions
		bool yearIsValid(unsigned int * year);
		bool monthIsValid(unsigned int* month);
		// Month and year passed for validation check
		bool dayIsValid(unsigned int *day, unsigned int * month, unsigned int * year); 
		bool is31DaysMonth(unsigned int month);
		inline unsigned int getNumericYear(unsigned int * year);
		
	public:
		friend ostream& operator<<(ostream& os, const Date& date);
						   		 			   	
	private:
		static constexpr unsigned int	MAX_LENGTH_DAY = 2;
		static constexpr unsigned int	MAX_LENGTH_MONTH = 2;
		static constexpr unsigned int	MAX_LENGTH_YEAR = 4;
		static unsigned int placeCounter;

		unsigned int * day;   //preparation for 2-digit number
		unsigned int * month; // preparation 2-digit number
		unsigned int * year;  // preparation 4-digit number
};


#endif 