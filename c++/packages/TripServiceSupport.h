#include <list>

class Trip
{
};

class User
{
public:
    inline User( int _id ):id(_id) {} ;
    
    inline const std::list<User>& GetFriends() const { return friends; }
    inline void AddFriend( User user ) { friends.push_back( user ); }
    inline std::list<Trip> Trips() { return trips; }
    inline void AddTrip( Trip trip ) { trips.push_back( trip ); }
    inline bool isFriendWith(const User &user){
        for(const auto& person : friends){
            if(person == user)
                return true;
        }
        return false;
    }
    inline bool operator==( const User& other )const { return (other.id==id); }
private:
    int id;
    std::list<Trip> trips;
    std::list<User> friends;
};

class TripService
{
public:
    std::list<Trip> GetTripsByUser( User user );


protected://need it to test
    virtual std::list<Trip> getUserTrip(const User&) const;
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
    inline static std::list<Trip> FindTripsByUser(User user)
    {
        throw "TripDAO should not be invoked on an unit test.";
    }
};

