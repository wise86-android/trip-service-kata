#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "TripService.h"

using ::testing::Return;
using ::testing::Matcher;
using ::testing::Eq;
using ::testing::NiceMock;

class TripServiceMock : public TripService{
public:

    MOCK_METHOD0(getLoggedUser,User::Ptr (void));
    MOCK_CONST_METHOD1(getUserTrip,std::vector<Trip>(const User& user));
};


TEST(TripService,trowWhenUserNotLog){

    NiceMock<TripServiceMock> service;

    ON_CALL(service,getLoggedUser()).WillByDefault(Return(nullptr));

    try {
        User unused(0);
        service.GetTripsByUser(unused);
    }catch (NoLoggedUser e){
        SUCCEED();
        return;
    }
    FAIL();

}

TEST(TripService,loggedUserWithoutFriendGiveEmptyTrips){

    NiceMock<TripServiceMock> service;
    User::Ptr loggedUser = std::make_shared<User>(0);
    User unused(1);
    ON_CALL(service,getLoggedUser()).
            WillByDefault(Return(loggedUser));
    auto tripvector=service.GetTripsByUser(unused);
    ASSERT_TRUE(tripvector.empty());
}

TEST(TripService,whenUserAreFrendsToTheLoggedOneReturnUserTrip){
    NiceMock<TripServiceMock> service;

    Trip friendUserTrip;
    User::Ptr loggedUser = std::make_shared<User>(0);
    User friendUser(1);
    std::vector<Trip> trips = {Trip(),Trip()};
    friendUser.AddFriend(loggedUser);
    ON_CALL(service,getLoggedUser()).
            WillByDefault(Return(loggedUser));
    ON_CALL(service,getUserTrip(Eq(friendUser))).WillByDefault(Return(trips));
    auto tripvector=service.GetTripsByUser(friendUser);
    ASSERT_FALSE(tripvector.empty());
}