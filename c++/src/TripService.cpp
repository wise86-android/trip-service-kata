#include <vector>
#include "UserSession.h"
#include "TripService.h"

std::vector<Trip> TripService::GetTripsByUser(const User &user )
{
    User::Ptr loggedUser = mLoginManager.getLoggedUser();
    if(loggedUser == nullptr)
        throw NoLoggedUser();

    if (user.isFriendWith(*loggedUser))
        return mTripManager.getUserTrip(user);
    return {};
}


