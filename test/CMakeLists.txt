cmake_minimum_required(VERSION 2.8)
project(TrainTicketUnitTest)
set(CMAKE_CXX_STANDARD 11)

FIND_PACKAGE(PkgConfig REQUIRED)
PKG_SEARCH_MODULE(GIOUNIX REQUIRED gio-unix-2.0)

INCLUDE_DIRECTORIES(../
        ../include
        ${GIOUNIX_INCLUDE_DIRS}
        )

LINK_DIRECTORIES(
)

add_executable(train_ticket_ut ../main.cpp)
target_link_libraries(train_ticket_ut gtest_main gtest ${GIOUNIX_LIBRARIES} pthread)
