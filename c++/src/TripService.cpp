#include <list>
#include "TripServiceSupport.h"
UserSession *UserSession::oneUserSession=0;

std::list<Trip> TripService::GetTripsByUser( User user )
{
    std::list<Trip> triplist ;
    User* loggedUser = getLoggedUser();
    bool isFriend = false;
    if ( loggedUser )
    {
        std::list<User>::const_iterator i;
        for( i = user.GetFriends().begin(); i != user.GetFriends().end(); ++i )
        {
            if ( *i == *loggedUser )
            {
                isFriend = true;
                break;
            }
        }
        if (isFriend)
        {
            triplist = getUserTrip(user);
        }
        return triplist;
    }
    else
    {
        throw "UserNotLoggedInException"; //TODO USE A TYPE
    }
}

std::list<Trip> TripService::getUserTrip(const User &user) const {
    return TripDAO::FindTripsByUser(user); }

User *TripService::getLoggedUser() {
    return UserSession::GetInstance()->GetLoggedUser();
}

