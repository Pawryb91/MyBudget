#include "ExpenseManager.h"
#include "SupportMethod.h"
#include "ExpensesFile.h"
#include "UserManager.h"
#include "DataManager.h"
#include <algorithm>


Expense ExpenseManager::EnterNewExpenseData(int LoggedUserId) {

    Expense expense;
    DataManager dataManager;
    string dateString;
    int dateInt;
    char choice;
    int ExpenseID;
    LastExpenseID = GetLastExpenseID();

    dateString = dataManager.DateMenu(ChoseOptionFromDateMenuForExpense());

    expense.SetExpenseId(LastExpenseID + 1);
    expense.SetUserId(LoggedUserId);

    expense.SetDateString(dateString);



    dateInt = dataManager.ChangeDateStringToDateInt(dataManager.RemovePauseFromEnteredData(dateString));

    expense.SetDateInt(dateInt);

    cout<< "Enter new expense item: " << endl;

    expense.SetItem(SupportMethod::LoadLine());

    cout<< "Enter new expense amount: " << endl;

    expense.SetAmount(SupportMethod::ConversionStringToFloat(SupportMethod::LoadFloat()));

    Expenses.push_back(expense);

    return expense;

}


void ExpenseManager::AddNewExpense(int LoggedUserId) {

    Expense expense;
    ExpensesFile expensesFile;
    expensesFile.AddExpenseToFile(EnterNewExpenseData(LoggedUserId));

}

char ExpenseManager::ChoseOptionFromDateMenuForExpense() {

     char Choice;

    do{
    system("cls");
    cout << "---------------------------" << endl;
    cout << "What is the date of the added income?" << endl;
    cout << "1.Today" << endl;
    cout << "2.Other day" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: " << endl;
    Choice = SupportMethod::LoadCharacter();
    }while(Choice != '1' && Choice !='2');

    return Choice;

}

int ExpenseManager::GetLastExpenseID() {

    if(Expenses.size() > 0)
        return Expenses.back().GetExpenseId();
    else
        return 0;

}
