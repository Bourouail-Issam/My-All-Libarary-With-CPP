#pragma once
#include <iostream>
#include<cstdlib>
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

};

