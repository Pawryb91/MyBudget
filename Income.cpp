#include "Income.h"
#include "SupportMethod.h"
#include "DataManager.h"

using namespace std;


void Income::SetIncomeId (int NewIncomeId) {
    if (NewIncomeId > 0)
        IncomeId = NewIncomeId;
    else
        cout << "ERROR - IncomeId" << endl;
}
void Income::SetUserId (int NewUserId) {
    if (NewUserId > 0)
        UserId = NewUserId;
    else
        cout << "ERROR - UserId" << endl;
}

void Income::SetDateInt (int NewDate) {
    DateInt = NewDate;
}
void Income::SetDateString (string NewDate) {
    DateString = NewDate;
}
void Income::SetItem (string NewItem) {
    Item = NewItem;
}
void Income::SetAmount (float NewAmount) {
    if (NewAmount >= 0)
    Amount = NewAmount;
    else
        cout << "Amount can't be negative." << endl;
}

void Income::SetAmountString (string NewAmount) {

    AmountString = NewAmount;

}


int Income::GetIncomeId() {
    return IncomeId;
}
int Income::GetUserId() {
    return UserId;
}

int Income::GetDateInt() {
    return DateInt;
}

string Income::GetDateString() {
    return DateString;
}
string Income::GetItem() {
    return Item;
}

float Income::GetAmountFloat() {
    return Amount;
}
string Income::GetAmount() {
    AmountString = SupportMethod::ConversionFloatToString(Amount);
    return AmountString;
}

