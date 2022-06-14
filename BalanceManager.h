#ifndef BALANCEMANAGER_H
#define BALANCEMANAGER_H

#include <iostream>
#include <vector>
#include "DataManager.h"
#include "Income.h"
#include "Expense.h"

using namespace std;

class BalanceManager {

    DataManager dataManager;
    Income income;
    Expense expense;
    float Balance = 0;
    float IncomeSum = 0;
    float ExpenseSum = 0;
    vector <Income> SortedIncomes;
    vector <Expense> SortedExpense;


    float CalculateIncomeSum(int dateBegin, int dateEnd,int LoggedUserId,vector<Income> Incomes);
    float CalculateExpenseSum(int dateBegin, int dateEnd,int LoggedUserId,vector<Expense> Expenses);
    vector<Income> IncomeVectorSort(vector<Income> Incomes);
    vector<Expense> ExpenseVectorSort(vector<Expense> Expenses);


    void ShowIncomesData(int dateBegin, int dateEnd, int LoggedUserId);
    void ShowExpensesData(int dateBegin, int dateEnd, int LoggedUserId);

    void ShowBalance (int dateBegin, int dateEnd, int LoggedUserId);

public:

    void CalculateBalanceCurrentMonth(int LoggedUserId, vector<Income> Incomes , vector<Expense> Expenses);
    void CalculateBalanceLastMonth(int LoggedUserId, vector<Income> Incomes, vector<Expense> Expenses);
    void CalculateSelectedPeriodBalance(int LoggedUserId, vector<Income> Incomes, vector<Expense> Expenses);


};


#endif // BALANCEMANAGER_H
