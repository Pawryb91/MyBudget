#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include <iostream>
#include <vector>
#include <iomanip>
#include "Income.h"
#include "IncomesFile.h"
#include "DataManager.h"

using namespace std;

class IncomeManager {

    IncomesFile incomesFile;
    DataManager dataManager;
    int LastIncomeID;

    Income EnterNewIncomeData(int LoggedUserId);
    char ChoseOptionFromDateMenuForIncome();
    int GetLastIncomeID();

public:
    vector <Income> Incomes;
    IncomeManager () {
        Incomes = incomesFile.LoadIncomesFromFile();
    }

    void AddNewIncome(int LoggedUserId);
};


#endif // INCOMEMANAGER_H
