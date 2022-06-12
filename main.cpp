#include <iostream>

#include <sstream>
#include <algorithm>
#include <string>

//#include "MyBudget.h"
#include "Markup.h"
//#include "BalanceManager.h"

using namespace std;


int main() {


 //   MyBudget myBudget;

    char Choice;

    while (true) {
        if (!myBudget.IsUserLoggedIn()) {
            Choice = myBudget.ChooseOptionFromMainMenu();
            switch (Choice) {
            case '1':
                myBudget.UserRegistration();
                break;
            case '2':
                myBudget.UserLogin();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "There is no that option in menu." << endl << endl;
                system("pause");
                break;
            }
        } else {

            Choice = myBudget.ChooseOptionFromUserMenu();
            switch (Choice) {
            case '1':
                myBudget.AddIncome();
                break;
            case '2':
                myBudget.AddExpense();
                break;
            case '3':
                system("cls");
                myBudget.CalculateCurrentMonthBalance();
                break;
            case '4':
                myBudget.CalculateLastMonthBalance();
                break;
            case '5':
                myBudget.CalculateSelectedPeriodBalance();
                break;
            case '6':
                myBudget.ChangeLoggedUserPassword();
                break;
            case '7':
                myBudget.UserLogout();
                break;
            default:
                cout << endl << "There is no that option in menu." << endl << endl;
                system("pause");
                break;
            }
        }
    }

    return 0;
}

