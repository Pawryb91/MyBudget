#include "BalanceManager.h"
#include "Income.h"
#include "Expense.h"
#include "SupportMethod.h"
#include <algorithm>
#include <iomanip>

using namespace std;

float BalanceManager::CalculateIncomeSum(int dateBegin, int dateEnd, int LoggedUserId) {

    for(int i = 0; i < SortedIncomes.size(); i++) {

        if(SortedIncomes[i].GetUserId() == LoggedUserId) {
            if(SortedIncomes[i].GetDateInt()>= dateBegin && SortedIncomes[i].GetDateInt() <= dateEnd )
                IncomeSum = IncomeSum + SortedIncomes[i].GetAmountFloat();
        }
    }
    return IncomeSum;

}
float BalanceManager::CalculateExpenseSum(int dateBegin, int dateEnd, int LoggedUserId) {

    for(int i = 0; i < SortedExpense.size(); i++) {

        if(SortedExpense[i].GetUserId() == LoggedUserId) {
            if(SortedExpense[i].GetDateInt()>= dateBegin && SortedExpense[i].GetDateInt() <= dateEnd)
                ExpenseSum = ExpenseSum + SortedExpense[i].GetAmountFloat();
        }
    }
    return ExpenseSum;

}

void BalanceManager::CalculateBalanceCurrentMonth(int LoggedUserId) {


    string dataBeginString;
    string CurrentData;

    int dataBeginInt;
    int dataEndInt;
    int day;

    CurrentData = dataManager.GetCurrentData();

    dataEndInt = SupportMethod::ConversionStringToInt((dataManager.RemovePauseFromEnteredData(CurrentData)));
    day = SupportMethod::ConversionStringToInt(dataManager.SubstractDay(CurrentData));

    dataBeginInt = dataEndInt - day + 1;
    IncomeSum = CalculateIncomeSum(dataBeginInt,dataEndInt,LoggedUserId);
    ExpenseSum = CalculateExpenseSum(dataBeginInt,dataEndInt,LoggedUserId);


    if (IncomeSum == 0 && ExpenseSum == 0){
        cout << "There are no Incomes/Expenses in that period" << endl;
        system("pause");
    }
    else
        ShowBalance(dataBeginInt,dataEndInt,LoggedUserId);
}


void BalanceManager::CalculateBalanceLastMonth(int LoggedUserId) {


    string dataBeginString;
    string CurrentData;

    int dataBeginInt;
    int dataEndInt;
    int dayCurrentData;
    int dayInMonth;
    int month, year;

    CurrentData = dataManager.GetCurrentData();

    dataEndInt = SupportMethod::ConversionStringToInt((dataManager.RemovePauseFromEnteredData(CurrentData)));
    dayCurrentData = SupportMethod::ConversionStringToInt(dataManager.SubstractDay(CurrentData));
    month = SupportMethod::ConversionStringToInt(dataManager.SubstractMonth(CurrentData));
    year = SupportMethod::ConversionStringToInt(dataManager.SubstractYear(CurrentData));

    dataBeginInt = dataEndInt - dayCurrentData - 99;

    dayInMonth = dataManager.GetNumberOfDaysInMonth(year,month);

    dataEndInt = dataEndInt - 99 - dayCurrentData + dayInMonth;


    IncomeSum = CalculateIncomeSum(dataBeginInt,dataEndInt,LoggedUserId);
    ExpenseSum = CalculateExpenseSum(dataBeginInt,dataEndInt,LoggedUserId);

    if (IncomeSum == 0 && ExpenseSum == 0){
        cout << "There are no Incomes/Expenses in that period" << endl;
        system("pause");
    }
    else
        ShowBalance(dataBeginInt,dataEndInt,LoggedUserId);
}

void BalanceManager::CalculateSelectedPeriodBalance(int LoggedUserId) {


    string dataBeginString;
    string CurrentData;

    int dataBeginInt;
    int dataEndInt;

    bool DateOrder = false;

    while(DateOrder == false){

    cout << "Enter begin of period "<< endl;
    CurrentData = dataManager.GetSpecificData();

    dataBeginInt = SupportMethod::ConversionStringToInt((dataManager.RemovePauseFromEnteredData(CurrentData)));

    cout << "Enter end of period "<< endl;
    CurrentData = dataManager.GetSpecificData();

    dataEndInt = SupportMethod::ConversionStringToInt((dataManager.RemovePauseFromEnteredData(CurrentData)));

    DateOrder = dataManager.CheckDateOrder(dataBeginInt,dataEndInt);

    }

    IncomeSum = CalculateIncomeSum(dataBeginInt,dataEndInt,LoggedUserId);
    ExpenseSum = CalculateExpenseSum(dataBeginInt,dataEndInt,LoggedUserId);

    if (IncomeSum == 0 && ExpenseSum == 0){
        cout << "There are no Incomes/Expenses in that period" << endl;
        system("pause");
    }
    else
        ShowBalance(dataBeginInt,dataEndInt,LoggedUserId);
}

bool lowerEx (Expense expenseFirst, Expense expenseSecond) {
    return expenseFirst.GetDateInt() < expenseSecond.GetDateInt();
}

vector<Expense> BalanceManager::ExpenseVectorSort(vector<Expense> Expenses) {

    sort(Expenses.begin(),Expenses.end(), lowerEx);
    return Expenses;
}

bool lowerIn (Income incomeFirst, Income incomeSecond) {
    return incomeFirst.GetDateInt() < incomeSecond.GetDateInt();
}

vector<Income> BalanceManager::IncomeVectorSort(vector<Income> Incomes) {

    sort(Incomes.begin(),Incomes.end(), lowerIn);
    return Incomes;
}
void BalanceManager::ShowIncomesData(int dateBegin, int dateEnd,int LoggedUserId) {


    for(int i = 0; i < SortedIncomes.size(); i++) {

        if(SortedIncomes[i].GetUserId() == LoggedUserId) {
            if(SortedIncomes[i].GetDateInt()>= dateBegin && SortedIncomes[i].GetDateInt() <= dateEnd) {
                cout << fixed;
                cout
                        << SortedIncomes[i].GetDateString()
                        << " " << SortedIncomes[i].GetItem()
                        << " " << setprecision(2)<< SortedIncomes[i].GetAmountFloat() << endl;
                cout << endl;
            }
        }
    }
}

void BalanceManager::ShowExpensesData(int dateBegin, int dateEnd,int LoggedUserId) {

    for(int i = 0; i < SortedExpense.size(); i++) {
        if(SortedExpense[i].GetUserId() == LoggedUserId) {
            if(SortedExpense[i].GetDateInt()>= dateBegin && SortedExpense[i].GetDateInt() <= dateEnd) {
                cout << fixed;
                cout    << SortedExpense[i].GetDateString()
                        << " " << SortedExpense[i].GetItem()
                        << " " << setprecision(2)<< SortedExpense[i].GetAmountFloat() << endl;
                cout << endl;
            }
        }
    }
}

void BalanceManager::ShowBalance (int dateBeginInt, int dateEndInt, int LoggedUserId) {

    system("cls");
    cout << endl;
    cout << "----------------" << endl;
    cout << "Incomes: " << endl;
    cout << "----------------" << endl;

    ShowIncomesData(dateBeginInt,dateEndInt,LoggedUserId);

    cout << "----------------" << endl;
    cout << fixed;
    cout << "IncomeSum: " << setprecision(2) << IncomeSum << endl;
    cout << "----------------" << endl;
    cout << endl;
    cout << "----------------" << endl;
    cout << "Expenses: "<< endl;
    cout << "----------------" << endl;

    ShowExpensesData(dateBeginInt,dateEndInt,LoggedUserId);

    cout << "----------------" << endl;
    cout << fixed;
    cout << "ExpenseSum: "<< setprecision(2) << ExpenseSum << endl;
    cout << "----------------" << endl;

    cout << "================" << endl;
    cout << fixed;
    cout <<"Balance: " << setprecision(2) << IncomeSum - ExpenseSum << endl;
    cout << "================" << endl;
    system("pause");



}


