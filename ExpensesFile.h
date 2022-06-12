#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H

#include <iostream>
#include <vector>
#include "Expense.h"
#include "Markup.h"

using namespace std;

class ExpensesFile {

    CMarkup xml;

    Expense GetExpenseDataFromFile ();

public:

    ExpensesFile() {

        bool fileExists = xml.Load( "expenses.xml" );

        if (!fileExists) {
            xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
            xml.AddElem("Expenses");
            xml.Save("expenses.xml");
        }

    }

    void AddExpenseToFile(Expense expense);
    vector<Expense> LoadExpensesFromFile ();

};


#endif // EXPENSESFILE_H
