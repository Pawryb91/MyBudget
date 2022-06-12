#ifndef EXPENSEMANAGER_H
#define EXPENSEANAGER_H

#include <iostream>
#include <vector>
#include <iomanip>
#include "Expense.h"
#include "ExpensesFile.h"
#include "DataManager.h"

using namespace std;

class ExpenseManager {

    ExpensesFile expenseFile;
    DataManager dataManager;
    int LastExpenseID;

    Expense EnterNewExpenseData(int LoggedUserId);
    char ChoseOptionFromDateMenuForExpense();
    int GetLastExpenseID();

public:
    vector <Expense> Expenses;
    ExpenseManager () {
        Expenses = expenseFile.LoadExpensesFromFile();
    }

    void AddNewExpense(int LoggedUserId);

};

#endif // EXPENSEMANAGER_H
