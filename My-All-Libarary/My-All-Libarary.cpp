
#include <iostream>
#include "clsUtil.h"
using namespace std;

int main()
{

   clsUtil::Srand();
   cout << clsUtil::RandomNumber(4, 17) << endl;
   cout << clsUtil::GetRandomCharacter(clsUtil::MixChars) << endl;
   cout << clsUtil::GeneratWord(clsUtil::SmallLetter, 8) << endl;
   cout << clsUtil::GeneratKey(clsUtil::CapitalLetter) << endl;

   cout << "Keys Generated : \n";
   clsUtil::GenerateKeys(5,clsUtil::CapitalLetter);

   int X1 = 1, X2 = 200;
   clsUtil::Swap(X1, X2);
   cout << "\nX1 = " << X1;
   cout << "\nX2 = " << X2;

   //string integer
   int arr1[5] = { 1,2,3,4,5 };

   clsUtil::ShuffleArray(arr1, 5);
   cout << "\nArray After shuffle : \n";
   for (int i = 0; i < 5; i++)
   {
	   cout << arr1[i] << endl;
   }

   //string array
   string arr2[5] = { "Karim","issam","Ahmed","Mohammed","Anwer" };

   clsUtil::ShuffleArray(arr2, 5);
   cout << "\nArray After shuffle : \n";
   for (int i = 0; i < 5; i++)
   {
	   cout << arr2[i] << endl;
   }

   int arr3[5];
   clsUtil::FillArrayWithRandomNumber(arr3, 5,33,77);
   cout << "\nArray After fill integer numbers : \n";
   for (int i = 0; i < 5; i++)
   {
	   cout << arr3[i] << endl;
   }

   string arr4[5];
   clsUtil::FillArrayWithRandomWords(arr4, 5, clsUtil::MixChars, 8);
   cout << "\nArray After fill string words : \n";
   for (int i = 0; i < 5; i++)
   {
      cout << arr4[i] << endl;
   }

   string arr5[5];
   clsUtil::FillArrayWithRandomKeys(arr5, 5, clsUtil::CapitalLetter);
   cout << "\nArray After filling keys : \n";
   for (int i = 0; i < 5; i++)
   {
	   cout << arr5[i] << endl;
   }

   cout << "\nText1 " << clsUtil::Tabs(5) << "Text2\n";
   const short EncryptionKey = 65; //THIS IS THE KEY

   string TextAfterEncryption, TextAfterDecryption;
   string Text = "Hello World -_- !";

   TextAfterEncryption = clsUtil::Encryption(Text, EncryptionKey);
   TextAfterDecryption = clsUtil::Decryption(TextAfterEncryption, EncryptionKey);

   cout << "\nText Before Encryption : " << Text << endl;
   cout << "Text After Encryption : " << TextAfterEncryption;
   cout << "\nText After Decryption : " << TextAfterDecryption << "\n";

}
