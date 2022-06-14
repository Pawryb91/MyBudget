#ifndef MYBUDGET_H
#define MYBUDGET_H

#include <iostream>
#include "UserManager.h"
#include "IncomeManager.h"
#include "ExpenseManager.h"
#include "BalanceManager.h"

using namespace std;

class MyBudget {

    IncomeManager incomeManager;
    ExpenseManager expenseManager;
    UserManager userManager;
    //BalanceManager balanceManager;

    char ChoseOptionFromDateMenuForIncome();
    char ChoseOptionFromDateMenuForExpense();


public:

    char ChooseOptionFromMainMenu ();
    char ChooseOptionFromUserMenu();
    void UserRegistration();
    void UserLogin();
    void ChangeLoggedUserPassword();
    void UserLogout();
    bool IsUserLoggedIn();
    void CalculateCurrentMonthBalance();
    void CalculateLastMonthBalance();
    void CalculateSelectedPeriodBalance();
    void AddIncome();
    void AddExpense();

};
#endif // MYBUDGET_H
