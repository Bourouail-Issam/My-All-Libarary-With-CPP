#pragma once
#include <iostream>
#include<cstdlib>
#include"clsDate.h"
using namespace std;

class clsUtil
{
    public:

       static enum EnCharType
        {
            SmallLetter = 1, CapitalLetter = 2, Digit = 3, MixChars = 4, SpecialCharacter = 5
        };

       static void  Srand()
       {
           //Seeds the random number generator in C++, called only once
           srand((unsigned)time(NULL));
       }

       static int RandomNumber(int From, int To)
       {
           //Function to generate a random number

           int randNum = rand() % (To - From + 1) + From;
           return randNum;
       }

       static char GetRandomCharacter(EnCharType charType) 
       {

           if (charType == MixChars) 
               charType = (EnCharType)RandomNumber(1, 3);
           
           switch (charType)
           {
           case clsUtil::SmallLetter:
               return  char(RandomNumber(97, 122));

           case EnCharType::CapitalLetter:
               return  char(RandomNumber(65, 90));

           case EnCharType::Digit:
               return  char(RandomNumber(48, 57));

           case EnCharType::SpecialCharacter:
               return char(RandomNumber(33, 47));
           }
       }

       static string GeneratWord(EnCharType TypeChar, short length)
       {
           string word = "";

           for (int i = 0; i < length; i++)
               word += GetRandomCharacter(TypeChar);
           
           return word;
       }

       static string GeneratKey(EnCharType TypeChar)
       {
           string KeyG = "";
           for (int i = 0; i < 4; i++)
           {
               KeyG += GeneratWord(TypeChar, 4);
               if (i <=  2)
                   KeyG += '-';
           }
           return KeyG;
       }

       static void GenerateKeys(int NumberOfKeys, EnCharType TypeChar) 
       {
           for (int i = 1; i <= NumberOfKeys; i++)
               cout << "Key [" << i << "] : " << GeneratKey(TypeChar) << endl;
       }
       
       //Swap integer
       static void Swap(int& Num1, int& Num2) 
       {
           int TMP;
           TMP = Num1;
           Num1 = Num2;
           Num2 = TMP;
       }
       
       //Swap double
       static void Swap(double& Num1, double& Num2) 
       {
           double TMP;
           TMP = Num1;
           Num1 = Num2;
           Num2 = TMP;
       }

       //Swap boolean
       static void Swap(bool& booleanValue1, bool& booleanValue2)
       {
           bool TMP;
           TMP = booleanValue1;
           booleanValue1 = booleanValue2;
           booleanValue2 = TMP;
       }

       //Swap Char
       static void Swap(char& char1, char& char2)
       {
           char TMP;
           TMP = char1;
           char1 = char2;
           char2 = TMP;
       }

       //Swap String
       static void Swap(string& string1, string& string2)
       {
           string TMP;
           TMP = string1;
           string1 = string2;
           string2 = TMP;
       }

       //Swap date
       static void Swap(clsDate& Date1, clsDate& Date2)
       {
           clsDate TMP;
           TMP = Date1;
           Date1 = Date2;
           Date2 = TMP;
       }

       static void ShuffleArray(int Arr[100], int ArrLength) {
           for (int i = 0; i < ArrLength; i++)
               Swap(Arr[RandomNumber(1, ArrLength) - 1], Arr[RandomNumber(1, ArrLength) - 1]);
       }
       static void ShuffleArray(string Arr[100], int ArrLength) {
           for (int i = 0; i < ArrLength; i++)
               Swap(Arr[RandomNumber(1, ArrLength) - 1], Arr[RandomNumber(1, ArrLength) - 1]);
       }
       static void FillArrayWithRandomNumber(int Arr[100], int Arraylength, int From, int To)
       {
           for (int i = 0; i < Arraylength; i++)
           {
               Arr[i] = RandomNumber(From, To);
           }
       }
       static void FillArrayWithRandomWords(string Arr[100], int Arraylength,EnCharType CharType,int lengthOfWord)
     {
         for (int i = 0; i < Arraylength; i++)
         {
             Arr[i] = GeneratWord(CharType, lengthOfWord);
         }
     }
}; 

