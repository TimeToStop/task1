cmake_minimum_required(VERSION 3.5)

project(client LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(client
    main.cpp
    thread.cpp
    clientsocket.h
    clientsocket.cpp
)

add_executable(server
    clientsocket.h
    )
