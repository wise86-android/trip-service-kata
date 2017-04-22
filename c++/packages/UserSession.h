//
// Created by wise on 4/22/17.
//

#ifndef TRIPSERVICE_USERSESSION_H
#define TRIPSERVICE_USERSESSION_H

#include "NoTestExecption.h"

#include "User.h"

class UserSession
{
public:
    inline static UserSession* GetInstance()
    {
        if ( !oneUserSession ) { oneUserSession = new UserSession(); }
        return oneUserSession;
    }

    inline bool IsUserLoggedIn(const User &user )
    {
        throw NoTestException("UserSession.IsUserLoggedIn() should not be called in an unit test");
    }
    inline User::Ptr GetLoggedUser(){
        throw NoTestException("UserSession.GetLoggedUser() should not be called in an unit test");
    }

private:
    inline UserSession() {};
    static UserSession *oneUserSession;
};

#endif //TRIPSERVICE_USERSESSION_H
