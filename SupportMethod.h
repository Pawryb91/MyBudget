#ifndef SUPPORTMETHOD_H
#define SUPPORTMETHOD_H

#include <iostream>
#include <sstream>

using namespace std;

class SupportMethod {

public:

    static int ConversionStringToInt (string text);
    static string ConversionIntToString (int Number);
    static float ConversionStringToFloat (string text);
    static string ConversionFloatToString (float floatNumber);
    static string LoadLine();
    static string ChangeFirstLetterToUpercaseRestLowercase(string text);
    static char LoadCharacter();
    static string LoadFloatString();
    static float LoadFloat();
    static string ConversionCommaToDot(string text);
    static bool CheckIfStringCouldBeConverseToFloat(string EnterString);
};
#endif // SUPPORTMETHOD_H
