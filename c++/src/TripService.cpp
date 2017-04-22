#include <vector>
#include "UserSession.h"
#include "TripService.h"



std::vector<Trip> TripService::GetTripsByUser(const User &user )
{
    User::Ptr loggedUser = getLoggedUser();
    if(loggedUser == nullptr)
        throw NoLoggedUser();

    if (user.isFriendWith(*loggedUser))
        return getUserTrip(user);
    return {};
}

std::vector<Trip> TripService::getUserTrip(const User &user) const {
    return TripDAO::FindTripsByUser(user); }

User::Ptr TripService::getLoggedUser() {
    return UserSession::GetInstance()->GetLoggedUser();
}

