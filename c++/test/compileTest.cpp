//
// Created by wise on 4/17/17.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "TripService.h"

TEST(compileTest, createExecWithAllTheDependency){

    try {
        User temp(0);
        TripService::GetTripsByUser(temp);
    }catch (...){

    }
    SUCCEED();
}


TEST(UserSession,IsSingleton){

    auto *session = UserSession::GetInstance();

    ASSERT_EQ(session,UserSession::GetInstance());
}