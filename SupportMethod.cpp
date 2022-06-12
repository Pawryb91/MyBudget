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
int SupportMethod::LoadIntiger() {

    string EnterString = "";
    int NubmerIntiger = 0;

    while (true) {
        getline(cin, EnterString);

        stringstream myStream(EnterString);
        if (myStream >> NubmerIntiger)
            break;
        cout << "It is not a number. Please enter again. " << endl;
    }
    return NubmerIntiger;

}

float SupportMethod::LoadFloat() {

    string EnterString = "";
    float NumberFloat = 0;

    while (true) {
        getline(cin, EnterString);

        EnterString = ConversionCommaToDot(EnterString);

        NumberFloat = stof(EnterString);
        //stringstream myStream(EnterString);
        //if (myStream >> NubmerIntiger)
        break;
        //cout << "It is not a number. Please enter again. " << endl;
    }
    return NumberFloat;

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

