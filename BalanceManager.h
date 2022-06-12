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
    float Balance;
    float IncomeSum;
    float ExpenseSum;
    vector <Income> SortedIncomes;
    vector <Expense> SortedExpense;


    float CalculateIncomeSum(int dateBegin, int dateEnd,int LoggedUserId);
    float CalculateExpenseSum(int dateBegin, int dateEnd,int LoggedUserId);
    vector<Income> IncomeVectorSort(vector<Income> Incomes);
    vector<Expense> ExpenseVectorSort(vector<Expense> Expenses);


    void ShowIncomesData(int dateBegin, int dateEnd, int LoggedUserId);
    void ShowExpensesData(int dateBegin, int dateEnd, int LoggedUserId);

    void ShowBalance (int dateBegin, int dateEnd, int LoggedUserId);

public:

    BalanceManager(vector <Income>Incomes, vector <Expense>Expense) {
        IncomeSum = 0;
        ExpenseSum = 0;
        SortedIncomes = IncomeVectorSort(Incomes);
        SortedExpense = ExpenseVectorSort(Expense);
    }

    void CalculateBalanceCurrentMonth(int LoggedUserId);
    void CalculateBalanceLastMonth(int LoggedUserId);
    void CalculateSelectedPeriodBalance(int LoggedUserId);


};


#endif // BALANCEMANAGER_H
