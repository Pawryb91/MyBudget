#include "MyBudget.h"
#include "SupportMethod.h"


using namespace std;



char MyBudget::ChooseOptionFromMainMenu() {

    char Choice;

    system("cls");
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Registration" << endl;
    cout << "2. Login" << endl;
    cout << "9. End" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    Choice = SupportMethod::LoadCharacter();

    return Choice;
}

char MyBudget::ChooseOptionFromUserMenu() {

    char Choice;

    system("cls");
    cout << " >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Current month balance" << endl;
    cout << "4. Last month balance" << endl;
    cout << "5. Selected period balance" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Change password" << endl;
    cout << "7. Logout" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    Choice = SupportMethod::LoadCharacter();

    return Choice;

}

void MyBudget::UserRegistration() {
    userManager.AddNewUser();
}
void MyBudget::UserLogin() {
   userManager.SetLoggedUserId(userManager.UserLogin());
}
void MyBudget::ChangeLoggedUserPassword() {
    userManager.ChangeLoggedUserPassword(userManager.GetLoggedUserId());
}
void MyBudget::UserLogout() {
    userManager.UserLogout();
}
bool MyBudget::IsUserLoggedIn() {
    return userManager.IsUserLoggedIn();
}
void MyBudget::CalculateCurrentMonthBalance() {
    BalanceManager balanceManager;
    balanceManager.CalculateBalanceCurrentMonth(userManager.GetLoggedUserId(),incomeManager.Incomes, expenseManager.Expenses);
}
void MyBudget::CalculateLastMonthBalance() {
    BalanceManager balanceManager;
    balanceManager.CalculateBalanceLastMonth(userManager.GetLoggedUserId(),incomeManager.Incomes, expenseManager.Expenses);
}
void MyBudget::CalculateSelectedPeriodBalance() {
    BalanceManager balanceManager;
    balanceManager.CalculateSelectedPeriodBalance(userManager.GetLoggedUserId(),incomeManager.Incomes, expenseManager.Expenses);
}
void MyBudget::AddIncome() {
    incomeManager.AddNewIncome(userManager.GetLoggedUserId());
}
void MyBudget::AddExpense() {
    expenseManager.AddNewExpense(userManager.GetLoggedUserId());
}
