#include <list>
#include "TripServiceSupport.h"
UserSession *UserSession::oneUserSession=0;

std::list<Trip> TripService::GetTripsByUser( User user )
{
    User* loggedUser = getLoggedUser();
    if(loggedUser== nullptr)
        throw "UserNotLoggedInException"; //TODO USE A TYPE

    if (user.isFriendWith(*loggedUser))
        return getUserTrip(user);
    return {};
}

std::list<Trip> TripService::getUserTrip(const User &user) const {
    return TripDAO::FindTripsByUser(user); }

User *TripService::getLoggedUser() {
    return UserSession::GetInstance()->GetLoggedUser();
}

