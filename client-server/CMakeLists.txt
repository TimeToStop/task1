cmake_minimum_required(VERSION 3.5)

project(client-server LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(server
    server/main.cpp
    server/serversocket.cpp
    server/serversocket.h
    shared/socketexception.cpp
    shared/socketexception.h
)


add_executable(client
    client/main.cpp
    client/worker.cpp
    client/worker.h
    client/clientsocket.cpp
    client/clientsocket.h
    client/thread.cpp
    shared/socketexception.cpp
    shared/socketexception.h
)

