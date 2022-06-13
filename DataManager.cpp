#include "DataManager.h"
#include "SupportMethod.h"

#include <iostream>
#include <ctime>

using namespace std;

string DataManager::GetCurrentData() {

    string CurrentTimeString;

    time_t currentTime = time(0);
    int currentYear,  currentMonth, currentDay;

    tm * ltm = localtime(&currentTime);


    currentYear = 1900 + ltm->tm_year;
    currentMonth = 1 + ltm->tm_mon;
    currentDay = ltm->tm_mday;

    CurrentTimeString = CombineDateParts(SupportMethod::ConversionIntToString (currentYear),
                                         AddZeroAtTheBeginingOfMonth(SupportMethod::ConversionIntToString (currentMonth)),
                                         AddZeroAtTheBeginingOfDay(SupportMethod::ConversionIntToString (currentDay)));

    return CurrentTimeString;
}

string DataManager::CombineDateParts (string year, string month, string day) {

    string data;

    data = year +"-"+ month +"-"+ day;

    return data;


}

string DataManager::RemovePauseFromEnteredData(string date) {

    int position;
    while(date.find("-")!= string::npos) {
        position = date.find("-");
        date.erase(position,1);
    }

    return date;
}


string DataManager::EnterSpecificData() {

    bool DataCorrectness;
    string SpecificDataString;

    do{
            cout << "Enter date (YYYY-MM-DD): " << endl;

    SpecificDataString = SupportMethod::LoadLine();

    DataCorrectness = CheckIfDataIsCorrect(SpecificDataString);
    if (DataCorrectness != true)
        cout << "Entered data is not correct. Please enter data again: " << endl;

    if (SpecificDataString.size() != 10)
        cout << "Enter date in the correct form" << endl;

    }while (DataCorrectness == false || SpecificDataString.size() != 10);


    return SpecificDataString;

}

bool DataManager::CheckDateOrder(int firstDate, int secondDate){

    if (firstDate <= secondDate)
        return true;
    else {
        cout << "Date order is incorrect. Please enter dates again" << endl;
            return false;
    }
}



string DataManager::SubstractYear (string date) {
    int position;
    position = date.find("-");
    return date.substr(0,position);
}

string DataManager::SubstractMonth (string date) {
    int position;
    position = date.find("-") + 1;
    return date.substr(position,2);
}

string DataManager::SubstractDay (string date) {
    int position;
    position = date.find_last_of("-") + 1;
    return date.substr(position,2);
}

string DataManager::GetSpecificData() {

    return EnterSpecificData();

}

string DataManager::AddZeroAtTheBeginingOfDay(string day) {
    if (day.size()<2)
        day = "0" + day;
    return day;
}

string DataManager::AddZeroAtTheBeginingOfMonth(string month) {
    if (month.size()<2)
        month = "0" + month;
    return month;
}
bool DataManager::CheckIfYearIsCorrect (int year) {


    if (year >= 2000 && year <= SupportMethod::ConversionStringToInt(SubstractYear(GetCurrentData()))) // getCurrentDataYear
        return true;
    else {
        return false;
    }


}

bool DataManager::CheckIfMonthIsCorrect (int month) {



    if (month > 12 || month <= 0) {
        return false;
    } else
        return true;


}

bool DataManager::CheckIfDayIsCorrect (int year, int month, int day) {

    if (month == 2) {
        if ((((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))) {
            if (day > 29) {
                return false;
            } else
                return true;
        } else {
            if (day > 28) {
                return false;
            } else
                return true;
        }


    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30) {
            return false;
        } else
            return true;
    }

    else {
        if (day > 31) {
            return false;
        } else
            return true;
    }
}

int DataManager::GetNumberOfDaysInMonth(int year, int month) {

    if (month == 2) {
        if ((((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)))
            return 29;
        else
            return 29;
    } else if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;

    else
        return 31;
}


bool DataManager::CheckIfDataIsCorrect (string date) {

    int year,month,day;

    year = SupportMethod::ConversionStringToInt(SubstractYear(date));
    month = SupportMethod::ConversionStringToInt(SubstractMonth(date));
    day = SupportMethod::ConversionStringToInt(SubstractDay(date));

    if(CheckIfYearIsCorrect(year) == true) {
        if (CheckIfMonthIsCorrect(month) == true)
            if(CheckIfDayIsCorrect(year,month,day) == true)
                return true;
    } else
        return false;
}

int DataManager::ChangeDateStringToDateInt (string dateString) {

    return SupportMethod::ConversionStringToInt(RemovePauseFromEnteredData(dateString));

}

string DataManager::DateMenu(char choice){

    if (choice == '1')
        return GetCurrentData();
    else if(choice == '2')
        return GetSpecificData();

}
