#ifndef DATAMANGER_H
#define DATAMANGER_H


#include <iostream>

using namespace std;

class DataManager {

    int CurrentData;
    int SpecificData;

    string EnterSpecificData();
    string CombineDateParts (string year, string month, string day);
    string AddZeroAtTheBeginingOfDay(string day);
    string AddZeroAtTheBeginingOfMonth(string month);
    bool CheckIfDataIsCorrect (string date);
    bool CheckIfDayIsCorrect (int year, int month, int day);
    bool CheckIfMonthIsCorrect (int month);
    bool CheckIfYearIsCorrect (int year);


public:

    string GetCurrentData();
    string GetSpecificData();
    string RemovePauseFromEnteredData(string date);
    string SubstractYear (string date);
    string SubstractMonth (string date);
    string SubstractDay (string date);
    int ChangeDateStringToDateInt (string dateString);
    int GetNumberOfDaysInMonth(int year, int month);
    string DateMenu(char choice);
    bool CheckDateOrder(int firstDate, int secondDate);

};


#endif // DATAMANGER_H
