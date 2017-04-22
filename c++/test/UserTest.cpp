#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "TripService.h"

TEST(User,userWithoutFrendIsNotFriend){

    User noFriend(1);
    User possibleFriend(2);
    ASSERT_TRUE(noFriend.GetFriends().empty());
    ASSERT_FALSE(noFriend.isFriendWith(possibleFriend));
}

TEST(User,userWithAFriendHasAFriend){

    User oneFriend(1);
    User::Ptr friendUser = std::make_shared<User>(2);
    oneFriend.AddFriend(friendUser);
    ASSERT_FALSE(oneFriend.GetFriends().empty());
    ASSERT_TRUE(oneFriend.isFriendWith(*friendUser));
}

TEST(User,userWithMultipleFriendHasAFriend){

    User person(1);
    User::Ptr bestFriend = std::make_shared<User>(2);
    User::Ptr closeFriend = std::make_shared<User>(3);
    person.AddFriend(bestFriend);
    person.AddFriend(closeFriend);
    ASSERT_FALSE(person.GetFriends().empty());
    ASSERT_TRUE(person.isFriendWith(*bestFriend));
}