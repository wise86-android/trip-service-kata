#include <list>
#include "TripServiceSupport.h"
UserSession *UserSession::oneUserSession=0;

std::list<Trip> TripService::GetTripsByUser( User user )
{
    std::list<Trip> triplist ;
    User* loggedUser = getLoggedUser();

    if ( loggedUser )
    {
        if (user.isFriendWith(*loggedUser))
        {
            return getUserTrip(user);
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

