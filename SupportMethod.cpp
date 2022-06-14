#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>

#include "SupportMethod.h"


int SupportMethod::ConversionStringToInt (string text) {

    int NumberInt;
    istringstream iss(text);
    iss >> NumberInt;

    return NumberInt;
}

string SupportMethod::ConversionIntToString (int Number) {

    ostringstream ss;
    ss << Number;
    string str = ss.str();
    return str;

}

float SupportMethod::ConversionStringToFloat (string text) {

    float NumberFloat;
    NumberFloat = stof(text);

    return NumberFloat;
}
string SupportMethod::ConversionFloatToString (float floatNumber) {
    string stringNumber;

    stringNumber = to_string(floatNumber);
    return stringNumber;
}


string SupportMethod::LoadLine() {

    string EnterString = "";
    getline(cin, EnterString);
    return EnterString;

}
string SupportMethod::ChangeFirstLetterToUpercaseRestLowercase(string text) {

    if (!text.empty()) {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;

}
char SupportMethod::LoadCharacter() {

    string EnterString = "";
    char Character  = {0};

    while (true) {
        getline(cin, EnterString);

        if (EnterString.length() == 1) {
            Character = EnterString[0];
            break;
        }
        cout <<" This is not a single character. Please enter character again." << endl;
    }
    return Character;

}

string SupportMethod::LoadFloat() {

    string EnterString = "";
    string NumberFloat = "";
    bool IfStringCouldBeFloat = false;

    while (IfStringCouldBeFloat == false) {
        getline(cin, EnterString);

        EnterString = ConversionCommaToDot(EnterString);

        IfStringCouldBeFloat = CheckIfStringCouldBeConverseToFloat(EnterString);
    }

    return EnterString;
}

bool SupportMethod::CheckIfStringCouldBeConverseToFloat(string EnterString) {

    int amountOfDots = 0;
    size_t condition_1 = EnterString.find_first_not_of("0123456789.");

    while(amountOfDots < 2) {

        size_t condition_2 = EnterString.find(".");

        if (condition_2!=std::string::npos) {
            amountOfDots++;
            EnterString = EnterString.erase(condition_2,1);
        } else
            break;
    }
    if (condition_1==std::string::npos && amountOfDots < 2 && EnterString.size()>0) {
        return true;
    } else {
        cout << "It is not a number. Please enter again. " << endl;
        return false;
    }

}

string SupportMethod::ConversionCommaToDot(string text) {

    int CommaPosition;
    string Dot = ".";

    while (text.find(",") != std::string::npos) {

        CommaPosition = text.find(",");
        text = text.replace(CommaPosition,1,Dot);
    }
    return text;
}

