
#include "Date.h"

unsigned int Date::placeCounter = 1; // Initializing first the static (shared) variable 

Date:: Date(unsigned int* day, unsigned int* month, unsigned int* year)
{
	// Allocating the arrays represents the fields of date as needed 
	this->day = new unsigned int[MAX_LENGTH_DAY];
	this->month = new unsigned int[MAX_LENGTH_MONTH];
	this->year = new unsigned int[MAX_LENGTH_YEAR];
	setYear(year);
	setMonth(month);
	setDay(day, month, year);
};
Date::~Date() 
{
	delete[] day;
	delete[] month;
	delete[] year;
}
bool Date::setDay(unsigned int * day, unsigned int * month, unsigned int * year) 
{
	if (!dayIsValid(day, month, year))
		return false;
	for (int i = 0; i < MAX_LENGTH_DAY; ++i)
		this->day[i] = day[i];
		
	return true;
}
bool Date::setMonth(unsigned int * month)
{
	if (!monthIsValid(month))
		return false;
	for (int i = 0; i < MAX_LENGTH_MONTH; ++i)
		this->month[i] = month[i];
	
	return true;
}
bool Date::setYear(unsigned int * year)
{
	if (!yearIsValid(year))
		return false;
	for (int i = 0; i < MAX_LENGTH_YEAR; ++i)
		this->year[i] = year[i];
	
	return true;
}
void Date::print() const
{
	cout << day[0] << day[1] << "/" << month[0] << month[1] << "/";
	cout << year[0] << year[1] << year[2] << year[3];
}
bool Date::dayIsValid(unsigned int* day, unsigned int* month, unsigned int* year)
{	
	placeCounter = 1;
	bool isValid = true; 
	
	// months with 31 days - 1, 3, 5, 7, 8 , 10, 12
	unsigned int numericMonth = month[0] * 10 + month[1];
	for (int i = 0; i < MAX_LENGTH_DAY && isValid; ++i, ++placeCounter)
	{ 
		switch (placeCounter) // The place of a digit we check from left to right
		{
			case 1: // First digit
				(day[i] >= 0 && day[i] <= 3) ? isValid = true : isValid=false;
				break;
			case 2: // second digit 
				if (day[i - 1] == 3)
				{
					if (is31DaysMonth(numericMonth))
						(day[i] != 0 && day[i] != 1) ? isValid = true : isValid = false;
					else if (numericMonth == 2) // February is less than 30 days month
						return false;
					else // Any other month
						day[i] != 0 ? isValid = true : isValid = false;
				}
				else if (day[i - 1] == 2)
				{
					if (numericMonth == 2) // February
					{
						if ((getNumericYear(year) % 2016) % 4 == 0) // Every 4 years- February has 28 days 
							(day[i] >= 0 && day[i] <= 8) ? isValid = true : isValid = false;
					}
					else // any other month - included years February has 29 days 
						(day[i] >= 0 && day[i] <= 9) ? isValid = true : isValid = false;
				}
				else if (day[i - 1] == 1 || day[i - 1] == 0)
					(day[i] >= 0 && day[i] <= 9) ? isValid = true : isValid = false;
				else // In any other case 
					isValid = false;
				break;
		}
	}
	return isValid;
}
unsigned int Date:: getNumericYear(unsigned int * year)
{	// Assuming the year is valid 
	unsigned int numericYear = 0, placeCounter=1000;
	
	for (int i = 0; i < MAX_LENGTH_YEAR; ++i, placeCounter/=10)
	{
		numericYear += (year[i] * placeCounter);
	}
	return numericYear;
}
bool Date:: is31DaysMonth(unsigned int month) // should we have connections of small functions to a class?
{
	switch (month)
	{
		case 1: 
			return true;
			break;
		case 3:
			return true;
			break;
		case 5:
			return true;
			break;
		case 7:
			return true;
			break;
		case 8:
			return true;
			break;
		case 10:
			return true;
			break;
		case 12:
			return true;
			break;
	}
	return false; // it is not a 31 days month
}
bool Date::monthIsValid(unsigned int* month)
{
	placeCounter = 1;
	bool isValid = true;
	for (int i = 0; i < MAX_LENGTH_MONTH && isValid; ++i, ++placeCounter)
	{
		switch (placeCounter)
		{
			case 1: // First digit 
				(month[i] == 0 || month[i] == 1) ? isValid = true : isValid=false;
				break;
			case 2: // Second digit 
				if (month[i - 1] == 0)
					(month[i] >= 1 || month[i] <= 9) ? isValid = true : isValid = false;
				else if (month[i - 1] == 1)
					(month[i] >= 0 && month[i] <= 9) ? isValid = true : isValid = false;
				else // In any other case
					isValid = false;
				break;
		}
	}
	return isValid;
}
bool Date::yearIsValid(unsigned int* year)
{
	placeCounter = 1;
	bool isValid = true;
	for (int i = 0; i < MAX_LENGTH_YEAR && isValid; ++i, ++placeCounter) // we can change to format of 2019 - 2999 
	{
		switch (placeCounter)
		{
		case 1: //First digit - assuming this system won't survive 1000 years
			if (year[i] != 2)
				isValid = false;
			(year[i] >= 0 && year[i] <= 9) ? isValid = true : isValid = false;
			break;
		case 2: // Second digit - assuming this system won't survive 100 years
			if (year[i] != 0)
				isValid = false;
			 (year[i] >= 0 && year[i] <= 9) ? isValid = true : isValid = false;
			break;
		case 3: // Third digit
			(year[i] >= 0 && year[i] <= 9) ? isValid = true : isValid = false;
			break;
		case 4: // Forth digit 
			(year[i] >= 0 && year[i] <= 9) ? isValid = true : isValid = false;
			break;
		}
	}
	return isValid;
}
