#ifndef USERFILE_H
#define USERFILE_H

#include <iostream>
#include <vector>
#include "User.h"
#include "Markup.h"

using namespace std;

class UserFile {

    CMarkup xml;
    User GetUserDataFromFile ();

public:

    UserFile() {

        bool fileExists = xml.Load( "users.xml" );

        if (!fileExists) {
            xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
            xml.AddElem("Users");
            xml.Save("users.xml");
        }
    }
    void AddUserToFile(User user);
    vector<User> LoadUsersFromFile ();
    void ChangePassword(int LoggedUserIDint);

};


#endif // USERFILE_H
