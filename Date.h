#ifndef __DATE_H
#define __DATE_H

#include <iostream>
using namespace std;

class Date
{
	public:
		
		Date(unsigned int day [], unsigned int month [], unsigned int year []);
		
		bool setDay(unsigned int * day, unsigned int * month, unsigned int * year); // Month and year passed for validation check
		bool setMonth(unsigned int * month);
		bool setYear(unsigned int * year);
		// Is there a need for const methods in here- because it didn't work for some reason 
		inline unsigned int * getDay()   { return this->day; };
		inline unsigned int * getMonth() { return this->month; };
		inline unsigned int * getYear()  { return this->year; };

		void show(unsigned int day[], unsigned int month[], unsigned int year[]) const;
		// Validation functions
		bool yearIsValid(unsigned int * year);
		bool monthIsValid(unsigned int* month);
		bool dayIsValid(unsigned int *day, unsigned int * month, unsigned int * year); // Month and year passed for validation check
		bool is31DaysMonth(unsigned int month);
		inline unsigned int getNumericYear(unsigned int * year);
			   		 			   	
	private:
		static constexpr unsigned int	MAX_LENGTH_DAY = 2;
		static constexpr unsigned int	MAX_LENGTH_MONTH = 2;
		static constexpr unsigned int	MAX_LENGTH_YEAR = 4;
		static unsigned int placeCounter;
		// Works only on later versions of c++ - we need to look for another way of initializing the arrays (maybe calling initializing functions on the init lines of feedbacks constructor)
		unsigned int day[MAX_LENGTH_DAY] = { 0,0 };  // 2-digit number
		unsigned int month[MAX_LENGTH_MONTH] = { 0,0 };;// 2-digit number
		unsigned int year[MAX_LENGTH_YEAR] = { 2, 0 , 0, 0 }; // 4-digit number
};


#endif 