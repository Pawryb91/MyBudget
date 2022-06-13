#include "UserFile.h"
#include "User.h"
#include "SupportMethod.h"

void UserFile::AddUserToFile(User user) {

    xml.Load("users.xml");

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", user.GetUserId());
    xml.AddElem("Login", user.GetUserLogin());
    xml.AddElem("Password", user.GetPassword());
    xml.AddElem("Name", user.GetName());
    xml.AddElem("Surname", user.GetSurname());

    xml.Save("users.xml");

}

void UserFile::ChangePassword(int LoggedUserIDint){

string LoggedUserIDstring = SupportMethod::ConversionIntToString(LoggedUserIDint);
string Data = "";
cout << "Enter new password " << endl;
string NewPassword = SupportMethod::LoadLine();

xml.Load("users.xml");


    xml.FindElem();
    xml.IntoElem();

    while(true){
    xml.FindElem();
    xml.IntoElem();
    xml.FindElem("UserId");
    Data = xml.GetData();
    if (Data == LoggedUserIDstring){
    xml.FindElem("Password");
    xml.SetData(NewPassword);
    cout << "Password has been changed succesfully" << endl;
    system("pause");
    break;
    }
    else
    xml.OutOfElem();
    }

    xml.Save("users.xml");


}

User UserFile::GetUserDataFromFile () {

    string Data;
    int data;
    User user;
    xml.IntoElem();

    xml.FindElem("UserId");
    Data = xml.GetData();
    data = SupportMethod::ConversionStringToInt(Data);
    user.SetUserId(data);

    xml.FindElem("Login");
    user.SetUserLogin(xml.GetData());

    xml.FindElem("Password");
    user.SetPassword(xml.GetData());

    xml.FindElem("Name");
    user.SetName(xml.GetData());

    xml.FindElem("Surname");
    user.SetSurname(xml.GetData());

    xml.OutOfElem();

    return user;

}

vector<User> UserFile::LoadUsersFromFile() {

    User user;
    vector <User> Users;

    xml.Load("users.xml");

    xml.FindElem();
    xml.IntoElem();

    while(xml.FindElem("User")) {

        user = GetUserDataFromFile();
        Users.push_back(user);

    }
    return Users;
}


