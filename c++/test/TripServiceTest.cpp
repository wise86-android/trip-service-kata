#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "TripService.h"

using ::testing::Return;
using ::testing::Matcher;
using ::testing::Eq;
using ::testing::NiceMock;

class LoginManagerMock : public LoginManager{
public:
    MOCK_CONST_METHOD0(getLoggedUser,User::Ptr (void));
};

class TripManagerMock : public TripManager{
public:
    MOCK_CONST_METHOD1(getUserTrip,std::vector<Trip>(const User& user));
};

class TripServiceTest : public ::testing::Test{

protected:
    NiceMock<TripManagerMock> tripMock;
    NiceMock<LoginManagerMock> userMock;
    TripService testService;

    TripServiceTest():
            tripMock(),
            userMock(),
            testService(userMock,tripMock){}


};

TEST_F(TripServiceTest,trowWhenUserNotLog){

    ON_CALL(userMock,getLoggedUser()).WillByDefault(Return(nullptr));

    try {
        User unused(0);
        testService.GetTripsByUser(unused);
    }catch (NoLoggedUser e){
        SUCCEED();
        return;
    }
    FAIL();

}

TEST_F(TripServiceTest,loggedUserWithoutFriendGiveEmptyTrips){

    User::Ptr loggedUser = std::make_shared<User>(0);
    User unused(1);
    ON_CALL(userMock,getLoggedUser()).
            WillByDefault(Return(loggedUser));
    auto tripvector=testService.GetTripsByUser(unused);
    ASSERT_TRUE(tripvector.empty());
}

TEST_F(TripServiceTest,whenUserAreFrendsToTheLoggedOneReturnUserTrip){

    Trip friendUserTrip;
    User::Ptr loggedUser = std::make_shared<User>(0);
    User friendUser(1);
    std::vector<Trip> trips = {Trip(),Trip()};
    friendUser.AddFriend(loggedUser);
    ON_CALL(userMock,getLoggedUser()).
            WillByDefault(Return(loggedUser));
    ON_CALL(tripMock,getUserTrip(Eq(friendUser))).WillByDefault(Return(trips));
    auto tripvector=testService.GetTripsByUser(friendUser);
    ASSERT_FALSE(tripvector.empty());
}