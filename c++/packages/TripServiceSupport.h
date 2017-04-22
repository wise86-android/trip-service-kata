#include <vector>

class Trip
{
};

#include "User.h"

class TripService
{
public:
    std::vector<Trip> GetTripsByUser( User user );


protected://need it to test
    virtual std::vector<Trip> getUserTrip(const User&) const;
    virtual User *getLoggedUser();
};

class UserSession
{
public:
    inline static UserSession* GetInstance()
    {
        if ( !oneUserSession ) { oneUserSession = new UserSession(); }
        return oneUserSession;    
    }
    
    inline bool IsUserLoggedIn( User user )
    {
        throw "UserSession.IsUserLoggedIn() should not be called in an unit test";
    }
    inline User* GetLoggedUser()
    {
        throw "UserSession.GetLoggedUser() should not be called in an unit test";
    }
    
private:
    inline UserSession() {};
    static UserSession *oneUserSession;
};

class TripDAO
{
public:
    inline static std::vector<Trip> FindTripsByUser(User user)
    {
        throw "TripDAO should not be invoked on an unit test.";
    }
};

