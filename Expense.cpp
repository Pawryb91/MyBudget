#include "Expense.h"
#include "SupportMethod.h"
#include "DataManager.h"

using namespace std;


void Expense::SetExpenseId (int NewExpenseId) {
    if (NewExpenseId > 0)
        ExpenseId = NewExpenseId;
    else
        cout << "ERROR - ExpenseId" << endl;
}
void Expense::SetUserId (int NewUserId) {
    if (NewUserId > 0)
        UserId = NewUserId;
    else
        cout << "ERROR - UserId" << endl;
}
void Expense::SetDateInt (int NewDate) {
    DateInt = NewDate;
}
void Expense::SetDateString (string NewDate) {
    DateString = NewDate;
}
void Expense::SetItem (string NewItem) {
    Item = NewItem;
}
void Expense::SetAmount (float NewAmount) {
     if (NewAmount >= 0)
    Amount = NewAmount;
    else
        cout << "Amount can't be negative." << endl;
}

void Expense::SetAmountString (string NewAmount) {

    AmountString = NewAmount;

}


int Expense::GetExpenseId() {
    return ExpenseId;
}
int Expense::GetUserId() {
    return UserId;
}
int Expense::GetDateInt() {
    return DateInt;
}
string Expense::GetDateString() {
    return DateString;
}
string Expense::GetItem() {
    return Item;
}
float Expense::GetAmountFloat() {
    return Amount;
}
string Expense::GetAmount() {
    AmountString = SupportMethod::ConversionFloatToString(Amount);
    return AmountString;
}
