find_package(GTest)
find_package(GMock)

set(GTEST_LIBS gmock gtest gtest_main)

add_executable(compileTest

        compileTest.cpp)

target_link_libraries(compileTest
        tripService
        ${GTEST_LIBS})

add_executable(TripServiceTest

        TripServiceTest.cpp)

target_link_libraries(TripServiceTest
        tripService
        ${GTEST_LIBS})