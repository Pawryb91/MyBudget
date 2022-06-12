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
    static int LoadIntiger();
    static float LoadFloat();
    static string ConversionCommaToDot(string text);
};
#endif // SUPPORTMETHOD_H
