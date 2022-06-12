#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;


class User {

    int UserId;
    string Login;
    string Password;
    string Name;
    string Surname;

public:

    void SetUserId (int NewId);
    void SetUserLogin (string NewLogin);
    void SetPassword (string NewPassword);
    void SetName (string NewName);
    void SetSurname (string NewSurname);

    int GetUserId ();
    string GetUserLogin ();
    string GetPassword ();
    string GetName ();
    string GetSurname();

};
#endif // USER_H
