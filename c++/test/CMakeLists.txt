find_package(GTest)
find_package(GMock)

set(GTEST_LIBS gmock gtest gtest_main)

add_executable(compileTest
        compileTest.cpp)

target_link_libraries(compileTest
        ${GTEST_LIBS})

add_executable(TripServiceLibTest
        UserTest.cpp
        TripServiceTest.cpp)

target_link_libraries(TripServiceLibTest
        tripService
        ${GTEST_LIBS})
