cmake_minimum_required(VERSION 3.5)

project(client-server LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(server
    src/server/main.cpp
    src/server/serversocket.cpp
    src/server/serversocket.h
    src/shared/socketexception.cpp
    src/shared/socketexception.h
)


add_executable(client
    src/client/main.cpp
    src/client/worker.cpp
    src/client/worker.h
    src/client/clientsocket.cpp
    src/client/clientsocket.h
    src/shared/socketexception.cpp
    src/shared/socketexception.h
)

