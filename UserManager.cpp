#include "UserManager.h"
#include "SupportMethod.h"
#include "UserFile.h"


User UserManager::EnterNewUserData() {

    User user;
    string login;

    if(Users.size()!=0)
        user.SetUserId(Users.back().GetUserId()+1);
    else
        user.SetUserId(1);

    do
    {
        cout<< "Enter new user Login: " << endl;
        user.SetUserLogin(SupportMethod::LoadLine());
    } while (IfLoginExist(user.GetUserLogin()) == true);

    cout<< "Enter new user Password: " << endl;

    user.SetPassword(SupportMethod::LoadLine());

    cout<< "Enter new user Name: " << endl;

    user.SetName(SupportMethod::LoadLine());

    cout<< "Enter new user Surname: " << endl;

    user.SetSurname(SupportMethod::LoadLine());

    Users.push_back(user);

    return user;
}

bool UserManager::IfLoginExist(string login) {

    for(int i = 0; i < Users.size(); i++) {

        if(Users[i].GetUserLogin() == login)
        {
            cout << "Login is already taken" << endl;
            return true;
        }
    }
        return false;
}

void UserManager::AddNewUser() {

    User user;
    UserFile userFile;
    userFile.AddUserToFile(EnterNewUserData());

}

void UserManager::ShowUserData(vector<User> Users) {

    for(int i = 0; i < Users.size(); i++) {

        cout << Users[i].GetUserId() << endl;
        cout << Users[i].GetUserLogin() << endl;
        cout << Users[i].GetName() << endl;
        cout << Users[i].GetSurname() << endl;
        cout << Users[i].GetPassword() << endl;
        cout << endl;
    }

}

void UserManager::SetLoggedUserId (int UserId) {

    LoggedUserID = UserId;

}

int UserManager::GetLoggedUserId () {

    return LoggedUserID;

}

int UserManager::UserLogin() {

    User user;
    vector<User> users;
    string login = "", password = "";

    cout << "Enter login: ";
    login = SupportMethod::LoadLine();

    vector <User>::iterator itr = Users.begin();
    while (itr != Users.end()) {
        if (itr -> User::GetUserLogin() == login) {
            for (int AttemptNumber = 3; AttemptNumber > 0; AttemptNumber--) {
                cout << "Enter password. Remains attempt " << AttemptNumber << ": ";
                password = SupportMethod::LoadLine();

                if (itr -> User::GetPassword() == password) {
                    cout << endl << "Successful login." << endl << endl;
                    system("pause");
                    LoggedUserID = itr -> User::GetUserId();
                    return LoggedUserID;
                }
            }
            cout << "You entered wrong password 3 times." << endl;
            system("pause");
            return 0;
        }
        itr++;
    }
    cout << "There is not user with entered login" << endl << endl;
    system("pause");

    return 0;

}
void UserManager::UserLogout() {

    LoggedUserID = 0;

}
bool UserManager::IsUserLoggedIn() {
    if(LoggedUserID > 0)
        return true;
    else
        return false;


}
void UserManager::ChangeLoggedUserPassword (int LoggedUserId) {
    userFile.ChangePassword(LoggedUserId);
}
