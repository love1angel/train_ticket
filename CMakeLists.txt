cmake_minimum_required(VERSION 3.16)
project(train_ticket)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-write-strings -ggdb -std=c++0x")
SET(CMAKE_VERBOSE_MAKEFILE on)

FIND_PACKAGE(PkgConfig REQUIRED)

INCLUDE_DIRECTORIES(./
        ./include
        )

AUX_SOURCE_DIRECTORY(${PROJECT_SOURCE_DIR}/src SRC)

ADD_EXECUTABLE(${PROJECT_NAME} main.cpp src/Customer.cc src/CustomerDataBaseHelper.cc)
