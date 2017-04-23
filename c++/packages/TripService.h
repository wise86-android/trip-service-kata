#include <vector>

#include "Trip.h"
#include "User.h"

#include "NoTestExecption.h"

class LoginManager{
public:
    virtual User::Ptr getLoggedUser() const=0;
};

class TripManager{
public:
    virtual std::vector<Trip> getUserTrip(const User&) const =0;
};


class TripService
{
public:

    TripService(const LoginManager &loginManager,const TripManager &tripManager ):
            mLoginManager(loginManager),mTripManager(tripManager){}

    std::vector<Trip> GetTripsByUser(const User &user );

private:
    const LoginManager &mLoginManager;
    const TripManager &mTripManager;
};

class NoLoggedUser : public std::exception{
};

class TripDAO : public TripManager
{
public:

    inline static std::vector<Trip> FindTripsByUser(User user)
    {
        throw NoTestException("should not be invoked on an unit test.");
    }
};

