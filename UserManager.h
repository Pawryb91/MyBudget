#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>


#include "User.h"
#include "UserFile.h"

class UserManager {

    int LoggedUserID;
    vector <User> Users;
    UserFile userFile;

    User EnterNewUserData();
    void ShowUserData(vector<User>);
    bool IfLoginExist(string login);


public:

    UserManager () {
        LoggedUserID = 0;
        Users = userFile.LoadUsersFromFile();
    }
    void AddNewUser();
    void SetLoggedUserId (int UserId);
    int GetLoggedUserId ();
    int UserLogin();
    void UserLogout();
    bool IsUserLoggedIn();
    void ChangeLoggedUserPassword (int LoggedUserId);


};


#endif // USERMANAGER_H
