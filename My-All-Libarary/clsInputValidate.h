#pragma once
#include "clsDate.h"

class clsInputValidate
{
public:
	static bool IsNumberBetween(short Number, short From, short To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}

	static bool IsNumberBetween(int Number, int From, int To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}

	static bool IsNumberBetween(double Number, double From, double To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}

	static bool IsNumberBetween(float Number, float From, float To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}

	static bool IsNumberBetween(clsDate Date, clsDate DateFrom, clsDate DateTo)
	{
		if (clsDate::IsDate1AfterDate2(DateFrom, DateTo))
		{
			clsDate::SwapDates(DateFrom, DateTo);
		}

		//Last solution
		// 
		//if ((clsDate::IsDate1AfterDate2(Date,DateFrom) || clsDate::IsDate1EqualDate2(Date, DateFrom)) 
		//	&& 
		//	(clsDate::IsDate1BeforeDate2(Date,DateTo) || clsDate::IsDate1EqualDate2(Date, DateTo)))
		//	return true;		
		//else 
		//	return false;

		//update my solution
		if (clsDate::IsDate1AfterDate2(Date, DateTo) || clsDate::IsDate1BeforeDate2(Date, DateFrom))
			return false;
		else
			return true;		
	}

	static int ReadIntNumber(string ErrorMessage = "Invalid Number, Enter again : ")
	{
		int Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static double ReadDblNumber(string ErrorMessage = "Invalid Number, Enter again : ")
	{
		double Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number is not within range, enter again: ")
	{
		int number = ReadIntNumber();

		while (!IsNumberBetween(number,From,To))
		{
			cout << ErrorMessage;
			number = ReadIntNumber();
		}

		return number;
	}

	static double ReadDblNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, enter again: ")
	{
		double number = ReadDblNumber();

		while (!IsNumberBetween(number, From, To))
		{
			cout << ErrorMessage;
			number = ReadDblNumber();
		}

		return number;
	}

	static bool IsValideDate(clsDate Date) {
		return clsDate::IsValidDate(Date);
	}
};

