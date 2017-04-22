//
// Created by wise on 4/22/17.
//

#ifndef TRIPSERVICE_USER_H_H
#define TRIPSERVICE_USER_H_H

#include <memory>
#include <algorithm>

class User {
public:

    using Ptr = std::shared_ptr<User>;

    inline User(int _id) : id(_id) {};

    inline const std::vector<User::Ptr> &GetFriends() const { return friends; }

    inline void AddFriend(User::Ptr user) { friends.emplace_back(user); }

    inline const std::vector<Trip> &Trips() const { return trips; }

    inline void AddTrip(Trip trip) { trips.push_back(trip); }

    inline bool isFriendWith(const User &user) const {
        return std::find_if(std::begin(friends), std::end(friends),
                            [&user](auto personPtr) { return *personPtr == user; })
               != std::end(friends);
    }

    inline bool operator==(const User &other) const { return (other.id == id); }

private:
    int id;
    std::vector<Trip> trips;
    std::vector<User::Ptr> friends;
};

#endif //TRIPSERVICE_USER_H_H
