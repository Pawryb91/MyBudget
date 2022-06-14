#include "ExpensesFile.h"
#include "expense.h"
#include "SupportMethod.h"
#include "DataManager.h"
#include <windows.h>

using namespace std;

void ExpensesFile::AddExpenseToFile(Expense expense) {

    xml.Load("expenses.xml");

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("ExpenseId", expense.GetExpenseId());
    xml.AddElem("UserId", expense.GetUserId());
    xml.AddElem("Date", expense.GetDateString());
    xml.AddElem("Item", expense.GetItem());
    xml.AddElem("Amount",expense.GetAmount());

    xml.Save("expenses.xml");
}
vector<Expense> ExpensesFile::LoadExpensesFromFile () {

    Expense expense;
    vector <Expense> Expenses;

    xml.Load("expenses.xml");

    xml.FindElem();
    xml.IntoElem();

    while(xml.FindElem("Expense")) {

        expense = GetExpenseDataFromFile();
        Expenses.push_back(expense);

    }
    return Expenses;


}
Expense ExpensesFile::GetExpenseDataFromFile () {

    string stringData;
    int intData;
    float floatData;
    DataManager dataManager;
    Expense expense;
    xml.IntoElem();

    xml.FindElem("ExpenseId");
    stringData = xml.GetData();
    intData = SupportMethod::ConversionStringToInt(stringData);
    expense.SetExpenseId(intData);

    xml.FindElem("UserId");
    stringData = xml.GetData();
    intData = SupportMethod::ConversionStringToInt(stringData);
    expense.SetUserId(intData);

    xml.FindElem("Date");
    expense.SetDateString(xml.GetData());

    intData = SupportMethod::ConversionStringToInt(dataManager.RemovePauseFromEnteredData(xml.GetData()));
    expense.SetDateInt(intData);

    xml.FindElem("Item");
    expense.SetItem(xml.GetData());

    xml.FindElem("Amount");
    stringData = xml.GetData();
    floatData = SupportMethod::ConversionStringToFloat(stringData);
    expense.SetAmount(floatData);

    xml.OutOfElem();

    return expense;
}
