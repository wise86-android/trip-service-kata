#include <vector>

#include "Trip.h"
#include "User.h"

#include "NoTestExecption.h"

class TripService
{
public:
    std::vector<Trip> GetTripsByUser(const User &user );

protected://need it to test
    virtual std::vector<Trip> getUserTrip(const User&) const;
    virtual User::Ptr getLoggedUser();
};

class NoLoggedUser : public std::exception{
};

class TripDAO
{
public:
    inline static std::vector<Trip> FindTripsByUser(User user)
    {
        throw NoTestException("should not be invoked on an unit test.");
    }
};

