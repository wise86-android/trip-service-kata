//
// Created by wise on 4/22/17.
//

#ifndef TRIPSERVICE_USER_H_H
#define TRIPSERVICE_USER_H_H

#include <algorithm>

class User{
public:
    inline User( int _id ):id(_id) {} ;

    inline const std::vector<User>& GetFriends() const { return friends; }
    inline void AddFriend( User user ) { friends.push_back( user ); }
    inline std::vector<Trip> Trips() { return trips; }
    inline void AddTrip( Trip trip ) { trips.push_back( trip ); }

    inline bool isFriendWith(const User &user){
        return std::find(std::begin(friends),std::end(friends),user)!=std::end(friends);
    }

    inline bool operator==( const User& other )const { return (other.id==id); }
private:
    int id;
    std::vector<Trip> trips;
    std::vector<User> friends;
};

#endif //TRIPSERVICE_USER_H_H
