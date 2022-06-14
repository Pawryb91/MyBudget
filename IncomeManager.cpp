#include "IncomeManager.h"
#include "SupportMethod.h"
#include "IncomesFile.h"
#include "UserManager.h"
#include "DataManager.h"
#include <algorithm>


Income IncomeManager::EnterNewIncomeData(int LoggedUserId) {

    Income income;
    DataManager dataManager;
    string dateString;
    int dateInt;
    char choice;
    int IncomeID;
    LastIncomeID = GetLastIncomeID();

    dateString = dataManager.DateMenu(ChoseOptionFromDateMenuForIncome());

    income.SetIncomeId(LastIncomeID + 1);
    income.SetUserId(LoggedUserId);
    income.SetDateString(dateString);

    dateInt = dataManager.ChangeDateStringToDateInt(dataManager.RemovePauseFromEnteredData(dateString));
    income.SetDateInt(dateInt);

    cout<< "Enter new income item: " << endl;

    income.SetItem(SupportMethod::LoadLine());

    cout<< "Enter new income amount: " << endl;

    income.SetAmount(SupportMethod::ConversionStringToFloat(SupportMethod::LoadFloat()));

    Incomes.push_back(income);

    return income;

}

void IncomeManager::AddNewIncome(int LoggedUserId) {

    Income income;
    IncomesFile incomesFile;
    incomesFile.AddIncomeToFile(EnterNewIncomeData(LoggedUserId));

}


char IncomeManager::ChoseOptionFromDateMenuForIncome() {

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

int IncomeManager::GetLastIncomeID() {

    if(Incomes.size() > 0)
        return Incomes.back().GetIncomeId();
    else
        return 0;

}



