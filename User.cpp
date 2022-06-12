#include "User.h"


void User::SetUserId (int NewId) {
    if (NewId > 0)
        UserId = NewId;
    else
        cout << "ERROR - UserId" << endl;
}

void User::SetUserLogin (string NewLogin) {
    Login = NewLogin;
}

void User::SetPassword (string NewPassword) {
    Password = NewPassword;
}
void User::SetName (string NewName) {
    Name = NewName;
}
void User::SetSurname (string NewSurname) {
    Surname = NewSurname;
}

int User::GetUserId () {
    return UserId;
}
string User::GetUserLogin () {
    return Login;
}
string User::GetPassword () {
    return Password;
}
string User::GetName () {
    return Name;
}
string User::GetSurname () {
    return Surname;
}

