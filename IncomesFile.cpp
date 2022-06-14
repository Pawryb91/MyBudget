#include "IncomesFile.h"
#include "Income.h"
#include "SupportMethod.h"
#include "DataManager.h"
#include <windows.h>

using namespace std;


void IncomesFile::AddIncomeToFile(Income income){

    xml.Load("incomes.xml");

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("IncomeId", income.GetIncomeId());
    xml.AddElem("UserId", income.GetUserId());
    xml.AddElem("Date", income.GetDateString());
    xml.AddElem("Item", income.GetItem());
    xml.AddElem("Amount", income.GetAmount());

    xml.Save("incomes.xml");
}
vector<Income> IncomesFile::LoadIncomesFromFile (){

    Income income;
    vector <Income> Incomes;

    xml.Load("incomes.xml");

    xml.FindElem();
    xml.IntoElem();

    while(xml.FindElem("Income")) {

        income = GetIncomeDataFromFile();
        Incomes.push_back(income);

    }
    return Incomes;


}
Income IncomesFile::GetIncomeDataFromFile (){

    string stringData;
    int intData;
    float floatData;
    DataManager dataManager;
    Income income;
    xml.IntoElem();

    xml.FindElem("IncomeId");
    stringData = xml.GetData();
    intData = SupportMethod::ConversionStringToInt(stringData);
    income.SetIncomeId(intData);

    xml.FindElem("UserId");
    stringData = xml.GetData();
    intData = SupportMethod::ConversionStringToInt(stringData);
    income.SetUserId(intData);

    xml.FindElem("Date");
    income.SetDateString(xml.GetData());

    intData = SupportMethod::ConversionStringToInt(dataManager.RemovePauseFromEnteredData(xml.GetData()));
    income.SetDateInt(intData);

    xml.FindElem("Item");
    income.SetItem(xml.GetData());

    xml.FindElem("Amount");
    stringData = xml.GetData();
    floatData = SupportMethod::ConversionStringToFloat(stringData);
    income.SetAmount(floatData);

    xml.OutOfElem();

    return income;
}
