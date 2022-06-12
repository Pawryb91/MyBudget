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
    float Amount;

public:

    void SetExpenseId (int NewExpenseId);
    void SetUserId (int NewUserId);
    void SetDateString (string NewDate);
    void SetDateInt (int NewDate);
    void SetItem (string NewItem);
    void SetAmount (float NewAmount);

    int GetExpenseId();
    int GetUserId();
    int GetDateInt();
    string GetDateString();
    string GetItem();
    float GetAmount();

};

#endif // EXPENSE_H
