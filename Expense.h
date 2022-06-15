#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>

using namespace std;

class Expense {

    int ExpenseId;
    int UserId;
    int DateInt;
    string DateString;
    string Item;
    string AmountString;
    float AmountFloat;

public:

    void SetExpenseId (int NewExpenseId);
    void SetUserId (int NewUserId);
    void SetDateString (string NewDate);
    void SetDateInt (int NewDate);
    void SetItem (string NewItem);
    void SetAmountFloat (float NewAmount);
    void SetAmountString (string NewAmount);

    int GetExpenseId();
    int GetUserId();
    int GetDateInt();
    string GetDateString();
    string GetItem();
    string GetAmountString();
    float GetAmountFloat();

};

#endif // EXPENSE_H
