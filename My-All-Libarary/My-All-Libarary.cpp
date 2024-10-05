
#include <iostream>
#include "clsUtil.h"
using namespace std;

int main()
{

   clsUtil::Srand();
   cout << clsUtil::RandomNumber(4, 17) << endl;
   cout << clsUtil::GetRandomCharacter(clsUtil::MixChars) << endl;
   cout << clsUtil::GeneratWord(clsUtil::SmallLetter, 8) << endl;
   cout << clsUtil::GeneratKey(4) << endl;

   cout << "Keys Generated : \n";
   clsUtil::GenerateKeys(5);
}
