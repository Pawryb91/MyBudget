#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include <iostream>
#include <vector>
#include "Income.h"
#include "Markup.h"

using namespace std;

class IncomesFile {

    CMarkup xml;

    Income GetIncomeDataFromFile ();

public:

    IncomesFile() {

        bool fileExists = xml.Load( "incomes.xml" );

        if (!fileExists) {
            xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
            xml.AddElem("Incomes");
            xml.Save("incomes.xml");
        }
    }

    void AddIncomeToFile(Income income);
    vector<Income> LoadIncomesFromFile ();

};


#endif // INCOMESFILE_H
