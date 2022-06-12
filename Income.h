#ifndef INCOME_H
#define INCOME_H

#include <iostream>

using namespace std;

class Income {

    int IncomeId;
    int UserId;
    int DateInt;
    string DateString;
    string Item;
    float Amount;

public:

    void SetIncomeId (int NewIncomeId);
    void SetUserId (int NewUserId);
    void SetDateString (string NewDate);
    void SetDateInt (int NewDate);
    void SetItem (string NewItem);
    void SetAmount(float NewAmount);

    int GetIncomeId();
    int GetUserId();
    int GetDateInt();
    string GetDateString();
    string GetItem();
    float GetAmount();

};

#endif // INCOME_H
