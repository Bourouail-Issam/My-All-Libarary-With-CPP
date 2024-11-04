#pragma once
#include "clsDate.h"

template <class T>
class clsInputValidate
{
public:

	static bool IsDateBetween(clsDate Date, clsDate DateFrom, clsDate DateTo)
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

	static bool IsValideDate(clsDate Date) {
		return clsDate::IsValidDate(Date);
	}

	static bool IsNumberBetween(T Number, T From, T To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}

	static T ReadNumber(string ErrorMessage = "Invalid Number, Enter again : ")
	{
		T Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static T ReadNumberBetween(T From, T To, string ErrorMessage = "Number is not within range, enter again: ")
	{
		T number = ReadNumber();

		while (!IsNumberBetween(number,From,To))
		{
			cout << ErrorMessage;
			number = ReadNumber();
		}

		return number;
	}

	static string ReadString()
	{
		string  S1 = "";
		// Usage of std::ws will extract all the whitespace character
		getline(cin >> ws, S1);
		return S1;
	}
};

