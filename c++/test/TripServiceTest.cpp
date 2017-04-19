#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "TripServiceSupport.h"

using ::testing::Return;
using ::testing::Matcher;
using ::testing::Eq;
using ::testing::NiceMock;

class TripServiceMock : public TripService{
public:

    MOCK_METHOD0(getLoggedUser,User*(void));
    MOCK_CONST_METHOD1(getUserTrip,std::list<Trip>(const User& user));
};


TEST(TripService,trowWhenUserNotLog){

    NiceMock<TripServiceMock> service;

    ON_CALL(service,getLoggedUser()).WillByDefault(Return(nullptr));

    try {
        User unused(0);
        service.GetTripsByUser(unused);
    }catch (const char *s){
        ASSERT_EQ(strcmp(s,"UserNotLoggedInException"),0);
        return;
    }
    FAIL();

}

TEST(TripService,loggedUserWithoutFriendGiveEmptyTrips){

    NiceMock<TripServiceMock> service;
    User loggedUser(0);
    User unused(1);
    ON_CALL(service,getLoggedUser()).
            WillByDefault(Return(&loggedUser));
    auto tripList=service.GetTripsByUser(unused);
    ASSERT_TRUE(tripList.empty());
}

TEST(TripService,whenUserAreFrendsToTheLoggedOneReturnUserTrip){
    NiceMock<TripServiceMock> service;

    Trip friendUserTrip;
    User loggedUser(0);
    User friendUser(1);
    friendUser.AddTrip(friendUserTrip);
    friendUser.AddFriend(loggedUser);
    ON_CALL(service,getLoggedUser()).
            WillByDefault(Return(&loggedUser));
    ON_CALL(service,getUserTrip(Eq(friendUser))).WillByDefault(Return(friendUser.Trips()));
    auto tripList=service.GetTripsByUser(friendUser);
    ASSERT_FALSE(tripList.empty());
}